#include "value_types.h"
#include "../../helpers/strings.h"

namespace {
   namespace _stringify_enum {
      void add_weapon_mode(uint32_t value, std::string& out) {
         using _enum = reach::megalo_value_enums::add_weapon_mode;
         //
         switch ((_enum)value) {
            case _enum::add:
               out = "Add";
               return;
            case _enum::swap:
               out = "Swap";
               return;
            case _enum::unk_1:
               out = "Unk_1";
               return;
         }
         cobb::sprintf(out, "unknown:%u", value);
      }
      void c_hud_destination(uint32_t value, std::string& out) {
         using _enum = reach::megalo_value_enums::c_hud_destination;
         //
         switch ((_enum)value) {
            case _enum::unk_0:
               out = "Unk_0";
               return;
            case _enum::unk_1:
               out = "Unk_1";
               return;
         }
         cobb::sprintf(out, "unknown:%u", value);
      }
      void compare_operator(uint32_t value, std::string& out) {
         using _enum = reach::megalo_value_enums::compare_operator;
         //
         switch ((_enum)value) {
            case _enum::equal:
               out = "equal to";
               return;
            case _enum::greater:
               out = "greater than";
               return;
            case _enum::greater_or_equal:
               out = "greater than or equal to";
               return;
            case _enum::less:
               out = "less than";
               return;
            case _enum::less_or_equal:
               out = "less than or equal to";
               return;
            case _enum::not_equal:
               out = "not equal to";
               return;
         }
         cobb::sprintf(out, "unknown:%u", value);
      }
      void drop_weapon_mode(uint32_t value, std::string& out) {
         using _enum = reach::megalo_value_enums::drop_weapon_mode;
         //
         switch ((_enum)value) {
            case _enum::primary:
               out = "primary";
               return;
            case _enum::secondary:
               out = "secondary";
               return;
         }
         cobb::sprintf(out, "unknown:%u", value);
      }
      void grenade_type(uint32_t value, std::string& out) {
         using _enum = reach::megalo_value_enums::grenade_type;
         //
         switch ((_enum)value) {
            case _enum::frag:
               out = "frag";
               return;
            case _enum::plasma:
               out = "plasma";
               return;
         }
         cobb::sprintf(out, "unknown:%u", value);
      }
      void math_operator(uint32_t value, std::string& out) {
         using _enum = reach::megalo_value_enums::math_operator;
         //
         constexpr char* strings[] = {
            "add",
            "subtract",
            "multiply",
            "divide",
            "assign",
            "modulo",
            "bitwise_and",
            "bitwise_or",
            "bitwise_xor",
            "bitwise_not",
            "bitwise_shift_left",
            "bitwise_shift_right",
            "bitwise_shift_left_2",
         };
         if (value >= std::extent<decltype(strings)>::value) {
            cobb::sprintf(out, "unknown:%u", value);
            return;
         }
         out = strings[value];
      }
      void object(uint32_t value, std::string& out) {
         using _enum = reach::megalo_value_enums::object;
         //
         if (value >= (uint32_t)_enum::global_object_0 && value <= (uint32_t)_enum::global_object_15) {
            cobb::sprintf(out, "Global.Object[%d]", value - (uint32_t)_enum::global_object_0 + '0');
            return;
         }
         //
         switch ((_enum)value) {
            case _enum::current_object:
               out = "current object";
               return;
            case _enum::hud_target:
               out = "HUD target";
               return;
            case _enum::killed:
               out = "killed object";
               return;
            case _enum::killer:
               out = "killer object";
               return;
            case _enum::none:
               out = "none";
               return;
         }
         cobb::sprintf(out, "unknown:%u", value);
      }
      void pickup_priority(uint32_t value, std::string& out) {
         using _enum = reach::megalo_value_enums::pickup_priority;
         //
         constexpr char* strings[] = {
            "Unk_0",
            "hold action",
            "automatic",
            "Unk_3",
         };
         if (value >= std::extent<decltype(strings)>::value) {
            cobb::sprintf(out, "unknown:%u", value);
            return;
         }
         out = strings[value];
      }
      void player(uint32_t value, std::string& out) {
         using _enum = reach::megalo_value_enums::player;
         //
         if (value >= (uint32_t)_enum::global_player_0 && value <= (uint32_t)_enum::global_player_7) {
            cobb::sprintf(out, "Global.Player[%d]", value - (uint32_t)_enum::global_player_0 + '0');
            return;
         }
         if (value >= (uint32_t)_enum::player_0 && value <= (uint32_t)_enum::player_15) {
            cobb::sprintf(out, "Player %d", value - (uint32_t)_enum::player_0 + '1');
            return;
         }
         switch ((_enum)value) {
            case _enum::current_player:
               out = "current player";
               return;
            case _enum::hud_player:
               out = "HUD player";
               return;
            case _enum::hud_target:
               out = "HUD target";
               return;
            case _enum::killer:
               out = "killer";
               return;
            case _enum::none:
               out = "none";
               return;
         }
         cobb::sprintf(out, "unknown:%u", value);
      }
      void team(uint32_t value, std::string& out) {
         using _enum = reach::megalo_value_enums::team;
         //
         if (value >= (uint32_t)_enum::global_team_0 && value <= (uint32_t)_enum::global_team_7) {
            cobb::sprintf(out, "Global.Team[%d]", value - (uint32_t)_enum::global_team_0 + '0');
            return;
         }
         if (value >= (uint32_t)_enum::team_0 && value <= (uint32_t)_enum::team_7) {
            cobb::sprintf(out, "Team %d", value - (uint32_t)_enum::team_0 + '1');
            return;
         }
         switch ((_enum)value) {
            case _enum::current_team:
               out = "current team";
               return;
            case _enum::hud_player:
               out = "HUD player's team";
               return;
            case _enum::hud_target:
               out = "HUD target's team";
               return;
            case _enum::neutral:
               out = "neutral team";
               return;
            case _enum::none:
               out = "none";
               return;
         }
         cobb::sprintf(out, "unknown:%u", value);
      }
      void team_designator(uint32_t value, std::string& out) {
         using _enum = reach::megalo_value_enums::team_designator;
         //
         switch ((_enum)value) {
            case _enum::attackers:
               out = "Attackers";
               return;
            case _enum::defenders:
               out = "Defenders";
               return;
            case _enum::neutral:
               out = "Neutral Team";
               return;
            case _enum::none:
               out = "None";
               return;
         }
         if (value >= (uint32_t)_enum::team3 && value <= (uint32_t)_enum::team8) {
            cobb::sprintf(out, "Team %d", value - (uint32_t)_enum::team3 + '3');
            return;
         }
         cobb::sprintf(out, "unknown:%u", value);
      }
      void team_disposition(uint32_t value, std::string& out) {
         using _enum = reach::megalo_value_enums::team_disposition;
         //
         constexpr char* strings[] = {
            "Unk_0",
            "Unk_1",
            "Unk_2",
         };
         if (value >= std::extent<decltype(strings)>::value) {
            cobb::sprintf(out, "unknown:%u", value);
            return;
         }
         out = strings[value];
      }
      void waypoint_icon(uint32_t value, std::string& out) {
         using _enum = reach::megalo_value_enums::waypoint_icon;
         //
         constexpr char* strings[] = { // indices start at -1
            "none",
            "microphone",
            "death_marker",
            "lightning_bolt",
            "bullseye",
            "diamond",
            "bomb",
            "flag",
            "skull",
            "crown",
            "vip",
            "territory_lock",
            "territory_a",
            "territory_b",
            "territory_c",
            "territory_d",
            "territory_e",
            "territory_f",
            "territory_g",
            "territory_h",
            "territory_i",
            "supply",
            "supply_health",
            "supply_air_drop",
            "supply_ammo",
            "arrow",
            "defend",
            "unk_26",
            "unk_27",
         };
         if (value + 1 >= std::extent<decltype(strings)>::value) {
            cobb::sprintf(out, "unknown:%u", value);
            return;
         }
         out = strings[value + 1];
      }
      void waypoint_priority(uint32_t value, std::string& out) {
         using _enum = reach::megalo_value_enums::waypoint_priority;
         //
         constexpr char* strings[] = {
            "none",
            "low",
            "high",
            "default",
         };
         if (value >= std::extent<decltype(strings)>::value) {
            cobb::sprintf(out, "unknown:%u", value);
            return;
         }
         out = strings[value];
      }
   }
}
namespace reach {
   namespace megalo {
      extern int bits_for_index_type(MegaloValueIndexType it) {
         switch (it) {
            // icon - unknown
            case MegaloValueIndexType::incident:        return cobb::bitcount(reach::megalo::max_incident_types - 1);
            case MegaloValueIndexType::loadout_palette: return cobb::bitcount(6 - 1);
            case MegaloValueIndexType::name:            return cobb::bitcount(reach::megalo::max_string_ids - 1);
            case MegaloValueIndexType::object_filter:   return cobb::bitcount(reach::megalo::max_script_labels - 1);
            case MegaloValueIndexType::object_type:     return cobb::bitcount(reach::megalo::max_object_types - 1);
            case MegaloValueIndexType::option:          return cobb::bitcount(reach::megalo::max_script_options - 1);
            case MegaloValueIndexType::player_traits:   return cobb::bitcount(reach::megalo::max_script_traits - 1);
            case MegaloValueIndexType::sound:           return cobb::bitcount(reach::megalo::max_engine_sounds - 1);
            case MegaloValueIndexType::stat:            return cobb::bitcount(reach::megalo::max_script_stats);
            case MegaloValueIndexType::string:          return cobb::bitcount(reach::megalo::max_variant_strings - 1);
            case MegaloValueIndexType::trigger:         return cobb::bitcount(reach::megalo::max_triggers - 1);
            case MegaloValueIndexType::widget:          return cobb::bitcount(reach::megalo::max_script_widgets - 1);
         }
         return 0;
      }
      extern int bits_for_enum(MegaloValueEnum st) {
         switch (st) {
            case MegaloValueEnum::add_weapon_mode:   return 2;
            case MegaloValueEnum::c_hud_destination: return 1;
            case MegaloValueEnum::compare_operator:  return 3;
            case MegaloValueEnum::drop_weapon_mode:  return 1;
            case MegaloValueEnum::grenade_type:      return 1;
            case MegaloValueEnum::math_operator:     return 5;
            case MegaloValueEnum::object:            return 5;
            case MegaloValueEnum::pickup_priority:   return 2;
            case MegaloValueEnum::player:            return 5;
            case MegaloValueEnum::team:              return 5;
            case MegaloValueEnum::team_designator:   return 4;
            case MegaloValueEnum::team_disposition:  return 2;
            case MegaloValueEnum::waypoint_icon:     return 5;
            case MegaloValueEnum::waypoint_priority: return 2;
         }
         return 0;
      }
      extern int offset_for_enum(MegaloValueEnum st) {
         switch (st) {
            case MegaloValueEnum::team_designator:
            case MegaloValueEnum::waypoint_icon:
            case MegaloValueEnum::team:
               return 1;
         }
         return 0;
      }
      //
      extern int bits_for_flags(MegaloValueFlagsMask fm) {
         switch (fm) {
            case MegaloValueFlagsMask::create_object_flags:      return 2;
            case MegaloValueFlagsMask::killer_type:              return 5; // all values can be held in 3 bits, but it seems to use 5 bits for some reason
            case MegaloValueFlagsMask::player_unused_mode_flags: return 2;
         }
         return 0;
      }
      //
      extern MegaloStringifyEnumOrFlagsFunction stringify_function_for_enum(MegaloValueEnum e) noexcept {
         #define preprocessor_case(name) case MegaloValueEnum::##name##: return _stringify_enum::##name##;
         switch (e) {
            preprocessor_case(add_weapon_mode);
            preprocessor_case(c_hud_destination);
            preprocessor_case(compare_operator);
            preprocessor_case(drop_weapon_mode);
            preprocessor_case(grenade_type);
            preprocessor_case(math_operator);
            preprocessor_case(object);
            preprocessor_case(pickup_priority);
            preprocessor_case(player);
            preprocessor_case(team);
            preprocessor_case(team_designator);
            preprocessor_case(team_disposition);
            preprocessor_case(waypoint_icon);
            preprocessor_case(waypoint_priority);
         }
         #undef preprocessor_case
         return nullptr;
      }
      extern MegaloStringifyEnumOrFlagsFunction stringify_function_for_flags(MegaloValueFlagsMask f) noexcept;
   }
}

namespace {
   using _MST = MegaloScopeType;    // just a shorthand
   using _MVT = MegaloVariableType; // just a shorthand
};
namespace reach {
   namespace megalo {
      namespace complex_values {
         extern std::array<ComplexValueSubtype, 43> scalar = {
            ComplexValueSubtype::constant<int16_t>("Int16"),
            ComplexValueSubtype::variable<_MST::player,  _MVT::number>("Player.Number"),
            ComplexValueSubtype::variable<_MST::team,    _MVT::number>("Team.Number"),
            ComplexValueSubtype::variable<_MST::globals, _MVT::number>("Global.Number"),
            ComplexValueSubtype("User-Defined Option", MegaloValueIndexType::option, MegaloValueIndexQuirk::reference),
            ComplexValueSubtype("Spawn Sequence", MegaloValueEnum::object),
            ComplexValueSubtype("Team Score",     MegaloValueEnum::team),
            ComplexValueSubtype("Player Score",   MegaloValueEnum::player),
            ComplexValueSubtype("Unknown 09",     MegaloValueEnum::player),
            ComplexValueSubtype("Player Rating",  MegaloValueEnum::player), // runtime: float converted to int
            ComplexValueSubtype("Player Stat",    MegaloValueEnum::player, MegaloValueIndexType::stat, MegaloValueIndexQuirk::reference),
            ComplexValueSubtype("Team Stat",      MegaloValueEnum::team,   MegaloValueIndexType::stat, MegaloValueIndexQuirk::reference),
            ComplexValueSubtype("Current Round", true), // UInt16 extended to int
            ComplexValueSubtype("Symmetry (Read-Only)", true), // bool
            ComplexValueSubtype("Symmetry", false), // bool
            ComplexValueSubtype("Score To Win", true),
            ComplexValueSubtype("unkF7A6", false), // bool
            ComplexValueSubtype("Teams Enabled", false), // bool
            ComplexValueSubtype("Round Time Limit", true),
            ComplexValueSubtype("Round Limit", true),
            ComplexValueSubtype("MiscOptions.unk0.bit3", false), // bool
            ComplexValueSubtype("Round Victories To Win", true),
            ComplexValueSubtype("Sudden Death Time Limit", true),
            ComplexValueSubtype("Grace Period", true),
            ComplexValueSubtype("Lives Per Round", true),
            ComplexValueSubtype("Team Lives Per Round", true),
            ComplexValueSubtype("Respawn Time", true),
            ComplexValueSubtype("Suicide Penalty", true),
            ComplexValueSubtype("Betrayal Penalty", true),
            ComplexValueSubtype("Respawn Growth", true),
            ComplexValueSubtype("Loadout Camera Time", true),
            ComplexValueSubtype("Respawn Traits Duration", true),
            ComplexValueSubtype("Friendly Fire", true), // bool
            ComplexValueSubtype("Betrayal Booting", true), // bool
            ComplexValueSubtype("Social Flags Bit 2", true), // bool
            ComplexValueSubtype("Social Flags Bit 3", true), // bool
            ComplexValueSubtype("Social Flags Bit 4", true), // bool
            ComplexValueSubtype("Grenades On Map", true), // bool
            ComplexValueSubtype("Indestructible Vehicles", true), // bool
            ComplexValueSubtype("Powerup Duration, Red", true),
            ComplexValueSubtype("Powerup Duration, Blue", true),
            ComplexValueSubtype("Powerup Duration, Yellow", true),
            ComplexValueSubtype("Death Event Damage Type", true), // byte
         };
         extern std::array<ComplexValueSubtype,  4> player = {
            ComplexValueSubtype("Player (Explicit)", MegaloValueEnum::player), // Global.Player and any "state" players e.g. current-player
            ComplexValueSubtype::variable<_MST::player, _MVT::player>("Player.Player"),
            ComplexValueSubtype::variable<_MST::object, _MVT::player>("Object.Player"),
            ComplexValueSubtype::variable<_MST::team,   _MVT::player>("Team.Player"),
         };
         extern std::array<ComplexValueSubtype,  8> object = {
            ComplexValueSubtype("Object (Explicit)", MegaloValueEnum::object),
            ComplexValueSubtype::variable<_MST::player, _MVT::object>("Player.Object"),
            ComplexValueSubtype::variable<_MST::object, _MVT::object>("Object.Object"),
            ComplexValueSubtype::variable<_MST::team,   _MVT::object>("Team.Object"),
            ComplexValueSubtype("Player.Slave", MegaloValueEnum::object),
            ComplexValueSubtype::variable<_MST::player, _MVT::player>("Player.Player.Slave"),
            ComplexValueSubtype::variable<_MST::object, _MVT::player>("Object.Player.Slave"),
            ComplexValueSubtype::variable<_MST::team,   _MVT::player>("Team.Player.Slave"),
         };
         extern std::array<ComplexValueSubtype,  6> team = {
            ComplexValueSubtype("Team (Explicit)", MegaloValueEnum::team),
            ComplexValueSubtype::variable<_MST::player, _MVT::team>("Player.Team"),
            ComplexValueSubtype::variable<_MST::object, _MVT::team>("Object.Team"),
            ComplexValueSubtype::variable<_MST::team,   _MVT::team>("Team.Team"),
            ComplexValueSubtype("Player.OwnerTeam", MegaloValueEnum::player),
            ComplexValueSubtype("Object.OwnerTeam", MegaloValueEnum::object),
         };
         extern std::array<ComplexValueSubtype,  7> timer = {
            ComplexValueSubtype::variable<_MST::globals, _MVT::timer>("Global.Timer"),
            ComplexValueSubtype::variable<_MST::player,  _MVT::timer>("Player.Timer"),
            ComplexValueSubtype::variable<_MST::team,    _MVT::timer>("Team.Timer"),
            ComplexValueSubtype::variable<_MST::object,  _MVT::timer>("Object.Timer"),
            ComplexValueSubtype("Round Time"),
            ComplexValueSubtype("Sudden Death Time"),
            ComplexValueSubtype("Grace Period Time"),
         };
      }
   }
};

void SimpleValue::to_string(std::string& out) const noexcept {
   out.clear();
   auto underlying = this->type->simple_type;
   switch (underlying) {
      case SimpleValueType::integer_8_signed:
      case SimpleValueType::integer_16_signed:
         cobb::sprintf(out, "%d", this->value.integer_signed);
         return;
      case SimpleValueType::integer_8_unsigned:
         cobb::sprintf(out, "%u", this->value.integer_unsigned);
         return;
      case SimpleValueType::boolean:
         out = this->value.boolean ? "true" : "false";
         return;
      case SimpleValueType::enumeration:
         {
            auto func = reach::megalo::stringify_function_for_enum(this->type->enumeration);
            if (func) {
               func(this->value.integer_signed, out);
            } else {
               cobb::sprintf(out, "enum:%d", this->value.integer_signed);
            }
         }
         return;
      case SimpleValueType::flags:
         cobb::sprintf(out, "flags:%08X", this->value.integer_unsigned); // for now
         return;
      case SimpleValueType::index:
         cobb::sprintf(out, "index:%u", this->value.integer_unsigned); // for now
         break;
      case SimpleValueType::vector3:
         cobb::sprintf(out, "(%d, %d, %d)", this->value.vector3.x, this->value.vector3.y, this->value.vector3.z);
         return;
   }
}
void SimpleValue::read(cobb::bitstream& stream) noexcept {
   int  bitcount  = 0;
   bool is_signed = false;
   switch (this->type->simple_type) {
      case SimpleValueType::integer_8_signed:
         is_signed = true;
         // and fall through:
      case SimpleValueType::integer_8_unsigned:
         bitcount = 8;
         break;
      case SimpleValueType::integer_16_signed:
         bitcount  = 16;
         is_signed = true;
         break;
   }
   switch (this->type->simple_type) {
      case SimpleValueType::boolean:
         stream.read(this->value.boolean);
         break;
      case SimpleValueType::enumeration:
         bitcount = reach::megalo::bits_for_enum(this->type->enumeration);
         assert(bitcount && "Unknown enumeration; add it to reach::megalo::bits_for_enum.");
         this->value.integer_signed = stream.read_bits<int32_t>(bitcount) - reach::megalo::offset_for_enum(this->type->enumeration);
         break;
      case SimpleValueType::flags:
         bitcount = reach::megalo::bits_for_flags(this->type->flags_mask);
         assert(bitcount && "Unknown flags mask; add it to reach::megalo::bits_for_flags.");
         this->value.integer_unsigned = stream.read_bits(bitcount);
         break;
      case SimpleValueType::index:
         {
            auto iq = this->type->index_quirk;
            if (iq == MegaloValueIndexQuirk::presence) {
               bool presence = stream.read_bits<uint8_t>(1) != 0;
               if (!presence)
                  return;
            }
            bitcount = this->type->index_bitlength;
            if (!bitcount)
               bitcount = reach::megalo::bits_for_index_type(this->type->index_type);
            assert(bitcount && "Unknown index type; add it to reach::megalo::bits_for_index_type.");
            if (iq == MegaloValueIndexQuirk::word) {
               this->value.integer_signed = stream.read_bits<int32_t>(bitcount, cobb::bitstream_read_flags::is_signed);
            } else {
               this->value.integer_signed = stream.read_bits<uint32_t>(bitcount);
               if (iq == MegaloValueIndexQuirk::offset)
                  this->value.integer_signed--;
            }
         }
         break;
      case SimpleValueType::integer_8_signed:
      case SimpleValueType::integer_8_unsigned:
      case SimpleValueType::integer_16_signed:
         this->value.integer_signed = stream.read_bits<int32_t>(bitcount, is_signed ? cobb::bitstream_read_flags::is_signed : 0);
         break;
      case SimpleValueType::vector3:
         stream.read(this->value.vector3.x);
         stream.read(this->value.vector3.y);
         stream.read(this->value.vector3.z);
         break;
   }
}

namespace {
   template<int N> const ComplexValueSubtype* _getComplexSubtype(cobb::bitstream& stream, const std::array<ComplexValueSubtype, N>& list) {
      constexpr int index_bitcount = cobb::bitcount(N - 1);
      //
      uint8_t index = stream.read_bits<uint8_t>(index_bitcount);
      if (index < N)
         return &list[index];
      return nullptr;
   }
}
void ComplexValue::to_string(std::string& out) const noexcept {
   out.clear();
   auto subtype = this->subtype;
   if (!subtype) {
      out = "!INVALID!";
      return;
   }
   if (subtype->has_enum()) {
      if (subtype->has_constant()) { // almost certainly a variable
         cobb::sprintf(out, "%s[%u]", subtype->name, this->constant);
         return;
      }
      auto func = reach::megalo::stringify_function_for_enum(subtype->enumeration);
      if (func) {
         func(this->constant, out);
      } else {
         cobb::sprintf(out, "%u", this->constant);
      }
   } else if (subtype->has_constant()) {
      cobb::sprintf(out, "%d", this->constant);
   } else if (subtype->has_index()) {
      cobb::sprintf(out, "%u", this->constant); // for now
   } else
      out = subtype->name; // almost certainly a game state value
}
void ComplexValue::read(cobb::bitstream& stream) noexcept {
   ComplexValueType type = this->type;
   if (type == ComplexValueType::any)
      type = (ComplexValueType)stream.read_bits(3);
   switch (type) {
      case ComplexValueType::scalar:
         this->subtype = _getComplexSubtype(stream, reach::megalo::complex_values::scalar);
         break;
      case ComplexValueType::player:
         this->subtype = _getComplexSubtype(stream, reach::megalo::complex_values::player);
         break;
      case ComplexValueType::object:
         this->subtype = _getComplexSubtype(stream, reach::megalo::complex_values::object);
         break;
      case ComplexValueType::team:
         this->subtype = _getComplexSubtype(stream, reach::megalo::complex_values::team);
         break;
      case ComplexValueType::timer:
         this->subtype = _getComplexSubtype(stream, reach::megalo::complex_values::timer);
         break;
   }
   if (!this->subtype) {
      printf("Failed to identify subtype for complex type %d.\n", (int)type);
      return;
   }
   const ComplexValueSubtype& st = *this->subtype;
   if (st.enumeration != MegaloValueEnum::not_applicable) {
      this->enum_value = stream.read_bits(reach::megalo::bits_for_enum(st.enumeration)) - reach::megalo::offset_for_enum(st.enumeration);
   }
   if (st.constant_flags & ComplexValueSubtype::flags::has_constant) {
      this->constant = stream.read_bits(st.constant_bitlength);
   } else if (st.constant_flags & ComplexValueSubtype::flags::has_index) {
      if (st.index_quirk == MegaloValueIndexQuirk::presence) {
         bool presence = stream.read_bits<uint8_t>(1) != 0;
         if (!presence)
            return;
      }
      int bitlength = st.index_bitlength;
      if (!bitlength)
         bitlength = reach::megalo::bits_for_index_type(st.index_type);
      if (st.index_quirk == MegaloValueIndexQuirk::word) {
         this->index = stream.read_bits<uint32_t>(bitlength, cobb::bitstream_read_flags::is_signed);
      } else {
         this->index = stream.read_bits<uint32_t>(bitlength);
         if (st.index_quirk == MegaloValueIndexQuirk::offset)
            this->index--;
      }
   }
}

void MegaloValue::read(cobb::bitstream& stream) noexcept {
   assert(this->type && "Cannot read a value that hasn't had its type set!");
   if (this->type->is_simple()) {
      this->simple.type = this->type;
      this->simple.read(stream);
      return;
   }
   if (this->type->is_complex()) {
      this->complex.type = this->type->complex_type;
      this->complex.read(stream);
      return;
   }
   switch (this->type->special_type) {
      case SpecialType::shape:
         this->special.shape.read(stream);
         return;
   }
   assert(false && "Failed to load a MegaloValue!");
}