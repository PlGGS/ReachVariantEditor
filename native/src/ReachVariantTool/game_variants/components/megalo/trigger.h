#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include "actions.h"
#include "conditions.h"
#include "limits.h"
#include "limits_bitnumbers.h"
#include "forge_label.h"
#include "../../../helpers/bitnumber.h"
#include "../../../helpers/bitwriter.h"
#include "../../../helpers/bitwise.h"
#include "../../../helpers/stream.h"
#include "decompiler/decompiler.h"

class GameVariantDataMultiplayer;

namespace Megalo {
   enum class block_type : uint8_t {
      //
      // I'm representing Megalo script units as conditions and actions, but Bungie 
      // probably conceived of them as code blocks.
      //
      normal, // not a loop, but trigger can still access loop iterators from containing triggers?
      for_each_player,
      for_each_player_randomly, // iterates over all players in a random order; use for things like randomly picking initial zombies in infection
      for_each_team,
      for_each_object, // every MP object?
      for_each_object_with_label, // always sorted by ascending spawn sequence
   };
   enum class entry_type : uint8_t {
      normal,
      subroutine, // preserves iterator values from outer loops
      on_init,
      on_local_init, // unverified; not used in Bungie gametypes
      on_host_migration, // host migrations and double host migrations
      on_object_death,
      local,
      pregame,
      // Halo 4: incident
   };
   
   class Trigger;
   class TriggerEntryPoints;

   class TriggerDecompileState {
      public:
         using list_t = std::vector<TriggerDecompileState*>;
         //
         Trigger* trigger = nullptr;
         int16_t  index       = -1;
         bool     is_function = false;
         list_t   callers;
         list_t   callees;
         //
         void clear(Trigger* trigger = nullptr, int16_t index_of_my_trigger = -1) noexcept;
         void setup_callees(const std::vector<Trigger*>& allTriggers, const Trigger* mine);
         void check_if_is_function();
         void get_full_callee_stack(list_t& out, list_t& recursing) const noexcept;
         bool is_downstream_from(const TriggerDecompileState* subject, const TriggerDecompileState* _checkStart = nullptr) const noexcept;
   };

   class Trigger {
      public:
         ~Trigger();
         //
         cobb::bitnumber<3, block_type> blockType = block_type::normal;
         cobb::bitnumber<3, entry_type> entryType = entry_type::normal;
         cobb::refcount_ptr<ReachForgeLabel> forgeLabel;
         struct {
            //
            // Raw data loaded from a game variant file. Reach uses a struct-of-arrays approach to 
            // serialize trigger data, writing all conditions followed by all actions and then headers 
            // for triggers, with each header identifying the start index and count of each opcode type. 
            // This represents raw struct-of-arrays data; the (opcodes) vector is generated post-load by 
            // the (postprocess_opcodes) member function.
            //
            // The "raw" data is generally only meaningful during the load and save processes, and should 
            // not be checked at any other time. The compiler co-opts the (conditionCount) value here to 
            // handle (Condition::or_group) when compiling new triggers.
            //
            condition_index conditionStart = -1;
            condition_count conditionCount =  0;
            action_index    actionStart    = -1;
            action_count    actionCount    =  0;
            bool            serialized     = false;
         } raw;
         //
         std::vector<Opcode*> opcodes; // set up by postprocess_opcodes after read; trigger owns the opcodes and deletes them in its destructor
         #if _DEBUG
            uint32_t bit_offset = 0;
         #endif
         TriggerDecompileState decompile_state;
         //
         bool read(cobb::ibitreader& stream, GameVariantDataMultiplayer& mp) noexcept;
         void postprocess_opcodes(const std::vector<Condition>& allConditions, const std::vector<Action>& allActions) noexcept;
         void write(cobb::bitwriter& stream) const noexcept;
         //
         void prep_for_flat_opcode_lists(); // call this on ALL triggers before calling (generate_flat_opcode_lists) on ANY of them
         void generate_flat_opcode_lists(GameVariantDataMultiplayer& mp, std::vector<Condition*>& allConditions, std::vector<Action*>& allActions);
         //
         void to_string(const std::vector<Trigger*>& allTriggers, std::string& out, std::string& indent) const noexcept; // need the list of all triggers so we can see into Run Nested Trigger actions
         inline void to_string(const std::vector<Trigger*>& allTriggers, std::string& out) const noexcept {
            out.clear();
            std::string indent;
            this->to_string(allTriggers, out, indent);
         }
         void decompile(Decompiler& out) noexcept;
         //
         void count_contents(size_t& conditions, size_t& actions) const noexcept;
   };

   class TriggerEntryPoints {
      protected:
         static void _stream(cobb::ibitreader& stream, int32_t& index) noexcept;
         static void _stream(cobb::bitwriter& stream, int32_t index) noexcept;
      public:
         static constexpr int32_t none     = -1;
         static constexpr int32_t reserved = -2; // for compiler; indicates that an event belongs to a trigger that is not yet compiled
         struct {
            int32_t init        = none;
            int32_t localInit   = none;
            int32_t hostMigrate = none;
            int32_t doubleHostMigrate = none;
            int32_t objectDeath = none;
            int32_t local       = none;
            int32_t pregame     = none;
            // Halo 4 only: incident
         } indices;
         //
         bool read(cobb::ibitreader& stream) noexcept;
         void write(cobb::bitwriter& stream) const noexcept;
         void write_placeholder(cobb::bitwriter& stream) const noexcept;
         //
         int32_t get_index_of_event(entry_type) const noexcept;
         void set_index_of_event(entry_type, int32_t trigger_index) noexcept; // does nothing if the (entry_type) does not correspond to an event
   };
}
