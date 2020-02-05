#include "object.h"
#include "../../../errors.h"

namespace {
   enum class _scopes {
      global,
      player,
      object,
      team,
      player_biped, // KSoft.Tool calls these "player_slave"
      player_player_biped,
      object_player_biped,
      team_player_biped,
      //
      _count,
   };
}
namespace Megalo {
   /*virtual*/ bool OpcodeArgValueObject::read(cobb::ibitreader& stream) noexcept /*override*/ {
      this->scope = stream.read_bits(cobb::bitcount((int)_scopes::_count - 1));
      int which_bits = 0;
      int index_bits = 0;
      const VariableScope* variable_scope  = nullptr;
      const VariableScope* slave_var_scope = nullptr;
      switch ((_scopes)this->scope) {
         case _scopes::global:
            index_bits = MegaloVariableScopeObject.which_bits();
            break;
         case _scopes::player:
            variable_scope = &MegaloVariableScopePlayer;
            break;
         case _scopes::object:
            variable_scope = &MegaloVariableScopeObject;
            break;
         case _scopes::team:
            variable_scope = &MegaloVariableScopeTeam;
            break;
         case _scopes::player_biped:
            which_bits = MegaloVariableScopePlayer.which_bits();
            break;
         case _scopes::player_player_biped:
            slave_var_scope = &MegaloVariableScopePlayer;
            break;
         case _scopes::object_player_biped:
            slave_var_scope = &MegaloVariableScopeObject;
            break;
         case _scopes::team_player_biped:
            slave_var_scope = &MegaloVariableScopeTeam;
            break;
         default:
            {
               auto& error = GameEngineVariantLoadError::get();
               error.state    = GameEngineVariantLoadError::load_state::failure;
               error.reason   = GameEngineVariantLoadError::load_failure_reason::bad_script_opcode_argument;
               error.detail   = GameEngineVariantLoadError::load_failure_detail::bad_variable_subtype;
               error.extra[0] = (int32_t)variable_type::object;
               error.extra[1] = this->scope;
               return false;
            }
            return false;
      }
      if (variable_scope) {
         this->which = stream.read_bits<uint16_t>(variable_scope->which_bits());
         this->index = stream.read_bits<uint16_t>(variable_scope->index_bits(variable_type::object));
         if (!variable_scope->is_valid_which(this->which)) {
            auto& error = GameEngineVariantLoadError::get();
            error.state    = GameEngineVariantLoadError::load_state::failure;
            error.reason   = GameEngineVariantLoadError::load_failure_reason::bad_script_opcode_argument;
            error.detail   = GameEngineVariantLoadError::load_failure_detail::bad_variable_scope;
            error.extra[0] = (int32_t)getScopeConstantForObject(*variable_scope);
            error.extra[1] = this->which;
            error.extra[2] = this->index;
            error.extra[3] = (int32_t)variable_type::object;
            return false;
         }
         return true;
      } else if (slave_var_scope) {
         this->which = stream.read_bits<uint16_t>(slave_var_scope->which_bits());
         this->index = stream.read_bits<uint16_t>(slave_var_scope->index_bits(variable_type::player));
         if (!slave_var_scope->is_valid_which(this->which)) {
            auto& error = GameEngineVariantLoadError::get();
            error.state    = GameEngineVariantLoadError::load_state::failure;
            error.reason   = GameEngineVariantLoadError::load_failure_reason::bad_script_opcode_argument;
            error.detail   = GameEngineVariantLoadError::load_failure_detail::bad_variable_scope;
            error.extra[0] = (int32_t)getScopeConstantForObject(*slave_var_scope);
            error.extra[1] = this->which;
            error.extra[2] = this->index;
            error.extra[3] = (int32_t)variable_type::player;
            error.extra[4] = 1;
            return false;
         }
         return true;
      }
      if (which_bits)
         this->which = stream.read_bits<uint16_t>(which_bits);
      if (index_bits)
         this->index = stream.read_bits<uint16_t>(index_bits);
      return true;
   }
   void OpcodeArgValueObject::write(cobb::bitwriter& stream) const noexcept {
      stream.write(this->scope, cobb::bitcount((int)_scopes::_count - 1));
      int which_bits = 0;
      int index_bits = 0;
      const VariableScope* variable_scope = nullptr;
      const VariableScope* slave_var_scope = nullptr;
      switch ((_scopes)this->scope) {
         case _scopes::global:
            index_bits = MegaloVariableScopePlayer.which_bits();
            break;
         case _scopes::player:
            variable_scope = &MegaloVariableScopePlayer;
            break;
         case _scopes::object:
            variable_scope = &MegaloVariableScopeObject;
            break;
         case _scopes::team:
            variable_scope = &MegaloVariableScopeTeam;
            break;
         case _scopes::player_biped:
            which_bits = MegaloVariableScopePlayer.which_bits();
            break;
         case _scopes::player_player_biped:
            slave_var_scope = &MegaloVariableScopePlayer;
            break;
         case _scopes::object_player_biped:
            slave_var_scope = &MegaloVariableScopeObject;
            break;
         case _scopes::team_player_biped:
            slave_var_scope = &MegaloVariableScopeTeam;
            break;
      }
      if (variable_scope) {
         stream.write(this->which, variable_scope->which_bits());
         stream.write(this->index, variable_scope->index_bits(variable_type::object));
         return;
      } else if (slave_var_scope) {
         stream.write(this->which, slave_var_scope->which_bits());
         stream.write(this->index, slave_var_scope->index_bits(variable_type::player));
         return;
      }
      if (which_bits)
         stream.write(this->which, which_bits);
      if (index_bits)
         stream.write(this->index, index_bits);
   }
   /*virtual*/ void OpcodeArgValueObject::to_string(std::string& out) const noexcept /*override*/ {
      const char* which_scope = nullptr;
      switch ((_scopes)this->scope) {
         case _scopes::global:
            which_scope = megalo_objects[this->index];
            if (which_scope)
               out = which_scope;
            else
               cobb::sprintf(out, "INVALID_OBJECT[%u]", this->index);
            return;
         case _scopes::player:
            which_scope = megalo_players[this->which];
            if (which_scope)
               cobb::sprintf(out, "%s.Object[%u]", which_scope, this->index);
            else
               cobb::sprintf(out, "INVALID_PLAYER[%u].Object[%u]", this->which, this->index);
            return;
         case _scopes::object:
            which_scope = megalo_objects[this->which];
            if (which_scope)
               cobb::sprintf(out, "%s.Object[%u]", which_scope, this->index);
            else
               cobb::sprintf(out, "INVALID_OBJECT[%u].Object[%u]", this->which, this->index);
            return;
         case _scopes::team:
            which_scope = megalo_teams[this->which];
            if (which_scope)
               cobb::sprintf(out, "%s.Object[%u]", which_scope, this->index);
            else
               cobb::sprintf(out, "INVALID_TEAM[%u].Object[%u]", this->which, this->index);
            return;
         case _scopes::player_biped:
            which_scope = megalo_players[this->which];
            if (which_scope)
               cobb::sprintf(out, "%s's biped", which_scope);
            else
               cobb::sprintf(out, "INVALID_PLAYER[%u]'s biped", this->which);
            return;
         case _scopes::player_player_biped:
            which_scope = megalo_players[this->which];
            if (which_scope)
               cobb::sprintf(out, "%s.Player[%u]'s biped", which_scope, this->index);
            else
               cobb::sprintf(out, "INVALID_PLAYER[%u].Player[%u]'s biped", this->which, this->index);
            return;
         case _scopes::object_player_biped:
            which_scope = megalo_objects[this->which];
            if (which_scope)
               cobb::sprintf(out, "%s.Player[%u]'s biped", which_scope, this->index);
            else
               cobb::sprintf(out, "INVALID_OBJECT[%u].Player[%u]'s biped", this->which, this->index);
            return;
         case _scopes::team_player_biped:
            which_scope = megalo_teams[this->which];
            if (which_scope)
               cobb::sprintf(out, "%s.Player[%u]'s biped", which_scope, this->index);
            else
               cobb::sprintf(out, "INVALID_TEAM[%u].Player[%u]'s biped", this->which, this->index);
            return;
      }
   }
}