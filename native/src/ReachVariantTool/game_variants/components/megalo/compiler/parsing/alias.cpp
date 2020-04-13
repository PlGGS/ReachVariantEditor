#include "alias.h"
#include "../compiler.h"
#include "../namespaces.h"
#include "../../opcode.h"
#include "../../../../helpers/qt/string.h"

namespace {
   using namespace Megalo;
   //
   template<typename T, int I> const OpcodeFuncToScriptMapping* _check_rel_alias_name_against_opcodes(const std::array<T, I>& list, const QString& name, const OpcodeArgTypeinfo* type) {
      for (auto& function : list) {
         auto& mapping = function.mapping;
         if (mapping.arg_context == OpcodeFuncToScriptMapping::no_context)
            continue;
         auto& base = function.arguments[mapping.arg_context];
         if (&base.typeinfo == type) {
            if (cobb::qt::stricmp(name, mapping.primary_name) == 0 || cobb::qt::stricmp(name, mapping.secondary_name) == 0)
               return &mapping;
         }
      }
      return nullptr;
   }
}
namespace Megalo::Script {
   Alias::Alias(Compiler& compiler, QString name, QString target) {
      this->name = name;
      //
      // Aliases need to perform some very strict validation, because when we resolve variable references, 
      // we check for aliases before we check for built-ins. (More efficient that way.) We don't want 
      // aliases to shadow built-ins, so we have to do all of the checking to prevent that shadowing when 
      // we're actually instantiating the alias.
      //
      {  // Validate name.
         if (Compiler::is_keyword(name))
            compiler.throw_error(QString("Keyword \"%1\" cannot be used as the name of an alias.").arg(this->name));
         if (cobb::qt::string_has_any_of(name, "[]."))
            compiler.throw_error(QString("Invalid alias name \"%1\". Alias names cannot contain square brackets or periods.").arg(this->name));
         if (cobb::qt::string_is_integer(name))
            compiler.throw_error(QString("Invalid alias name \"%1\". An integer literal cannot be used as the name of an alias.").arg(this->name));
         if (namespaces::get_by_name(name))
            compiler.throw_error(QString("Namespace \"%1\" cannot be used as the name of an alias.").arg(this->name));
         if (auto type = OpcodeArgTypeRegistry::get().get_variable_type(this->name))
            //
            // Do not allow aliases to shadow variable typenames.
            //
            compiler.throw_error(QString("Typename \"%1\" cannot be used as the name of an alias.").arg(type->internal_name.c_str()));
         if (auto type = OpcodeArgTypeRegistry::get().get_static_indexable_type(this->name))
            //
            // Do not allow aliases to shadow statically-indexable types. (This isn't strictly redundant 
            // with the above; remember that widgets and traits are included here, not just variables.)
            //
            compiler.throw_error(QString("Typename \"%1\" cannot be used as the name of an alias.").arg(type->internal_name.c_str()));
      }
      auto& type_registry = OpcodeArgTypeRegistry::get();
      this->target = new VariableReference(target);
      this->target->owner = this;
      try {
         this->target->resolve(compiler, true);
      } catch (compile_exception& e) {
         delete this->target;
         this->target = nullptr;
         //
         // VariableReference::resolve will throw if we attempt to resolve an imported name, since 
         // they are unrecognized. We want to be able to have an alias target an imported name, 
         // though, so let's try matching imported names here.
         //
         auto abs = compiler.lookup_absolute_alias(target);
         if (abs) {
            //
            // This branch handles cases like:
            //
            //    alias foo = warthog
            //    alias bar = foo     -- aliases "warthog"
            //
            assert(abs->is_imported_name() && "If this was an absolute alias of a variable, then it should've been handled by VariableReference::resolve. What went wrong?");
            this->target_imported_name = abs->target_imported_name;
         } else {
            OpcodeArgTypeRegistry::type_list_t types;
            type_registry.lookup_imported_name(target, types);
            if (!types.size())
               //
               // This alias's target is not an imported name, so just re-throw the original error.
               //
               throw e;
            this->target_imported_name = target;
         }
      }
      //
      // Apply further restrictions to the alias's name based on its type:
      //
      if (this->is_relative_alias()) {
         //
         // Restrictions on relative aliases:
         //
         auto type = this->target->get_type();
         if (type->can_have_variables()) {
            //
            // Do not allow aliases to shadow nested variables.
            //
            if (auto nested = type_registry.get_variable_type(name))
               compiler.throw_error(QString("Invalid alias name. An alias cannot shadow built-in types like %1.%2.").arg(type->internal_name.c_str()).arg(nested->internal_name.c_str()));
         }
         if (auto prop = type->get_property_by_name(name))
            //
            // Do not allow aliases to shadow properties.
            //
            compiler.throw_error(QString("Invalid alias name. An alias cannot shadow properties like %1.%2.").arg(type->internal_name.c_str()).arg(prop->name.c_str()));
         //
         // Do not allow aliases to shadow member functions or accessors:
         //
         auto mapping = _check_rel_alias_name_against_opcodes(conditionFunctionList, name, type);
         if (!mapping)
            mapping = _check_rel_alias_name_against_opcodes(actionFunctionList, name, type);
         if (mapping) {
            switch (mapping->type) {
               case OpcodeFuncToScriptMapping::mapping_type::property_get:
               case OpcodeFuncToScriptMapping::mapping_type::property_set:
                  compiler.throw_error(QString("Invalid alias name. An alias cannot shadow accessors like %1.%2.").arg(type->internal_name.c_str()).arg(name));
                  break;
            }
            compiler.throw_error(QString("Invalid alias name. An alias cannot shadow member functions like %1.%2.").arg(type->internal_name.c_str()).arg(name));
         }
      } else {
         //
         // Restrictions on absolute aliases:
         //
         OpcodeArgTypeRegistry::type_list_t types;
         auto name_source = Compiler::check_name_is_taken(name, types);
         switch (name_source) {
            case Compiler::name_source::none:
               break;
            case Compiler::name_source::action:
            case Compiler::name_source::condition:
               compiler.throw_error(QString("Invalid alias name. An alias cannot shadow a non-member function like %1.").arg(name));
               break;
            case Compiler::name_source::static_typename:
            case Compiler::name_source::variable_typename:
               compiler.throw_error(QString("Invalid alias name. An alias cannot shadow built-in types like %1.").arg(name));
               break;
            case Compiler::name_source::namespace_member:
               compiler.throw_error(QString("Invalid alias name. The specified name is already in use by the \"%1\" value.").arg(name));
               break;
            case Compiler::name_source::imported_name:
               {
                  if (types.size() == 1)
                     compiler.throw_error(QString("The \"%1\" value defined by the %2 type cannot be used as an alias name.").arg(name).arg(types[0]->internal_name.c_str()));
                  auto error = QString("Invalid alias name. The \"%1\" value is defined by the following types: %2.");
                  auto list = QString();
                  for (auto type : types) {
                     if (!list.isEmpty())
                        list += ", ";
                     list += type->internal_name.c_str();
                  }
                  compiler.throw_error(error.arg(name).arg(list));
               }
               break;
         }
      }
   }
   Alias::~Alias() {
      if (this->target) {
         delete this->target;
         this->target = nullptr;
      }
   }

   bool Alias::is_integer_constant()  const noexcept {
      if (!this->target)
         return false;
      return this->target->resolved.top_level.is_constant;
   }
   int32_t Alias::get_integer_constant() const noexcept {
      if (!this->target)
         return 0;
      auto& top_level = this->target->resolved.top_level;
      if (!top_level.is_constant)
         return 0;
      return top_level.index;
   }
   bool Alias::is_relative_alias() const noexcept {
      if (!this->target)
         return false;
      if (this->target->resolved.alias_basis)
         return true;
      return false;
   }
   bool Alias::is_imported_name() const noexcept {
      return !this->target && !this->target_imported_name.isEmpty();
   }
   const OpcodeArgTypeinfo* Alias::get_basis_type() const noexcept {
      if (!this->target)
         return nullptr;
      return this->target->resolved.alias_basis;
   }
}