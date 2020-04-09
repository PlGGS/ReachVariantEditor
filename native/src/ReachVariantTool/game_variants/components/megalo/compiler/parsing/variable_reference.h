#pragma once
#include "base.h"
#include <vector>
#include "../../opcode_arg.h"

namespace Megalo {
   class VariableScopeIndicatorValue;
   class VariableScopeWhichValue;
   //
   namespace Script {
      class Property;

      class Alias;
      class VariableReference : public ParsedItem {
         public:
            enum class disambig_type : uint8_t {
               scope,
               which,
               index,
               static_var, // typename[3] e.g. "player[0]"; only valid for the first interpreted part
               constant_integer,
               alias_relative_to, // only use in alias definitions, e.g. for the "player" in "alias is_zombie = player.number[0]"
            };
            //
         public:
            QString content;
            #if !_DEBUG
               static_assert(false, "replace (content) with logic to actually parse parts");
            #endif
            //
            struct Part {
               QString name;
               QString index_str;
               int32_t index = -1;
               bool    index_is_numeric = false;
               //
               Part() {} // needed for std::vector::push_back
               Part(QString n, QString i) : name(n), index_str(i) {}
               Part(QString n, int32_t i) : name(n), index(i) {};
               //
               Part& operator=(const Part& other) noexcept;
               //
               inline bool has_index() const noexcept {
                  return this->index_is_numeric || !this->index_str.isEmpty();
               }
               void resolve_index(Compiler&);
            };
            struct InterpretedPart {
               const OpcodeArgTypeinfo*           type  = nullptr;
               const VariableScopeIndicatorValue* scope = nullptr;
               const VariableScopeWhichValue*     which = nullptr; // needed for namespaces
               int32_t       disambiguator = 0;
               disambig_type disambig_type = disambig_type::scope;
               //
               bool is_none() const noexcept;
               bool is_read_only() const noexcept;
               bool is_variable() const noexcept;
            };
            //
            std::vector<Part> parts;
            std::vector<InterpretedPart> interpreted;
            struct {
               const Property* normal = nullptr;
               int32_t normal_index = 0;
               const AbstractPropertyRegistry::Definition* abstract = nullptr;
               QString abstract_name; // used for error reporting
            } property;
            bool resolved = false;
            //
            VariableReference(QString); // can throw compile_exception
            VariableReference(int32_t);
            //
            void set_to_constant_integer(int32_t);
            inline bool is_constant_integer() const noexcept { return this->parts.empty(); }
            inline bool is_property() const noexcept {
               return this->property.normal || !this->property.abstract;
            }
            inline bool is_abstract_property() const noexcept {
               return this->property.abstract != nullptr;
            }
            inline const AbstractPropertyRegistry::Definition* get_abstract_property_definition() const noexcept {
               return this->is_abstract_property() ? this->property.abstract : nullptr;
            }
            bool is_read_only() const noexcept;
            bool is_statically_indexable_value() const noexcept;
            const OpcodeArgTypeinfo* get_type() const noexcept;
            //
            void resolve(Compiler&, bool is_alias_definition = false); // can throw compile_exception
            //
            QString to_string() const noexcept;
            //
         protected:
            inline Part* _part(int i) {
               if (i < 0)
                  i += this->parts.size();
               else if (i >= this->parts.size())
                  return nullptr;
               return &this->parts[i];
            }
            void _transclude(uint32_t index, Alias&); // replaces (this->parts[index]) with the contents of the alias. if the alias is a relative alias, does not include the alias typename
            size_t _resolve_first_parts(Compiler&, bool is_alias_definition = false);
            bool _resolve_abstract_property(Compiler&, QString property_name, const OpcodeArgTypeinfo& property_is_on);
      };
   }
}