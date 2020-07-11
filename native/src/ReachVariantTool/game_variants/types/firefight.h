#pragma once
#include "../base.h"
#include "../components/custom_game_options.h"
#include "../components/firefight_custom_skull.h"
#include "../components/firefight_round.h"
#include "../components/firefight_wave_traits.h"

class GameVariantDataFirefight : public GameVariantData {
   public:
      enum custom_skull {
         red,
         yellow,
         blue,
      };
      struct scenario_flags {
         scenario_flags() = delete;
         enum {
            hazards_enabled             = 0x01,
            all_generators_must_survive = 0x02,
            random_generator_spawns     = 0x04,
            weapon_drops_enabled        = 0x08,
            ammo_crates_enabled         = 0x10,
         };
      };
      //
      GameVariantDataFirefight() {};
      //
      virtual ReachGameEngine get_type() const noexcept { return ReachGameEngine::firefight; }
      virtual bool read(cobb::reader&) noexcept override;
      virtual void write(GameVariantSaveProcess&) noexcept override;
      virtual void write_last_minute_fixup(GameVariantSaveProcess&) const noexcept override;
      virtual GameVariantData* clone() const noexcept override; // TODO
      virtual cobb::endian_t sha1_length_endianness() const noexcept override { return cobb::endian::big; }
      //
      ReachUGCHeader variantHeader;
      cobb::bitbool  isBuiltIn;
      ReachCustomGameOptions options;
      cobb::bitnumber<5, uint8_t> scenarioFlags;
      cobb::bitnumber<3, uint8_t> unkA;
      cobb::bitnumber<8, uint8_t> unkB;
      cobb::bitnumber<4, uint8_t> waveLimit;
      cobb::bitnumber<15, uint16_t> unkC; // a quantity of points; always 10000?
      cobb::bitnumber<15, uint16_t> eliteKillBonus;
      cobb::bitnumber<7,  uint8_t, true> startingLivesSpartan;
      cobb::bitnumber<7,  uint8_t, true> startingLivesElite;
      cobb::bitnumber<15, uint16_t> unkD;
      cobb::bitnumber<7, uint8_t, true> maxSpartanExtraLives;
      cobb::bitnumber<2, uint8_t> generatorCount;
      ReachPlayerTraits baseTraitsSpartan;
      ReachPlayerTraits baseTraitsElite;
      ReachFirefightWaveTraits  baseTraitsWave; // assumed
      ReachFirefightCustomSkull customSkulls[3]; // red, yellow, blue
      ReachCGRespawnOptions eliteRespawnOptions;
      ReachFirefightRound rounds[3];
      cobb::bitnumber<12, uint16_t> bonusWaveDuration; // in seconds
      decltype(ReachFirefightRound::skulls) bonusWaveSkulls;
      ReachFirefightWave bonusWave;
};