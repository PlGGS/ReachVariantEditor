#include "all_basic_enums.h"
#include "../../../helpers/strings.h"

namespace MegaloEx {
   namespace types {
      namespace enums {
         auto sound = DetailedEnum({
            DetailedEnumValue("announce_slayer",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/slayer/slayer"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Slayer: the gametype name announced at the start of the match.")
            ),
            DetailedEnumValue("announce_ctf",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/capture_the_flag/capture_the_flag"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Capture the Flag: the gametype name announced at the start of the match.")
            ),
            DetailedEnumValue("announce_ctf_captured",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/capture_the_flag/flag_captured"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Capture the Flag: when the flag is captured.")
            ),
            DetailedEnumValue("announce_ctf_dropped",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/capture_the_flag/flag_dropped"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Capture the Flag: when the flag is dropped.")
            ),
            DetailedEnumValue("announce_ctf_recovered",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/capture_the_flag/flag_recovered"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Capture the Flag: when the flag is recovered.")
            ),
            DetailedEnumValue("announce_ctf_reset",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/capture_the_flag/flag_reset"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Capture the Flag: when the flag is reset.")
            ),
            DetailedEnumValue("announce_ctf_stolen",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/capture_the_flag/flag_stolen"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Capture the Flag: when your team's flag is stolen.")
            ),
            DetailedEnumValue("announce_ctf_taken",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/capture_the_flag/flag_taken"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Capture the Flag: when your team takes the enemy flag.")
            ),
            DetailedEnumValue("announce_vip",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/vip/vip"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for VIP: the gametype name announced at the start of the match.")
            ),
            DetailedEnumValue("announce_vip_new",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/vip/new_vip"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for VIP: when a player receives VIP status."),
               DetailedEnumValueInfo::make_subtitle("New VIP.")
            ),
            DetailedEnumValue("announce_vip_killed",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/vip/vip_killed"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for VIP: when a VIP is killed."),
               DetailedEnumValueInfo::make_subtitle("VIP killed.")
            ),
            DetailedEnumValue("announce_juggernaut",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/juggernaut/juggernaut"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Juggernaut: the gametype name announced at the start of the match.")
            ),
            DetailedEnumValue("announce_juggernaut_new",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/juggernaut/new_juggernaut"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Juggernaut: when a player receives Juggernaut status.")
            ),
            DetailedEnumValue("announce_territories",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/territories/territories"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Territories: the gametype name announced at the start of the match.")
            ),
            DetailedEnumValue("announce_territories_captured",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/territories/territory_captured"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Territories: when a territory is captured.")
            ),
            DetailedEnumValue("announce_territories_lost",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/territories/territory_lost"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Territories: when your team loses a territory.")
            ),
            DetailedEnumValue("announce_assault",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/assault/assault"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Assault: the gametype name announced at the start of the match.")
            ),
            DetailedEnumValue("announce_assault_armed",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/assault/bomb_armed"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Assault: when a bomb is armed.")
            ),
            DetailedEnumValue("announce_assault_detonated",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/assault/bomb_detonated"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Assault: when a bomb is detonated.")
            ),
            DetailedEnumValue("announce_assault_disarmed",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/assault/bomb_disarmed"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Assault: when a bomb is disarmed.")
            ),
            DetailedEnumValue("announce_assault_dropped",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/assault/bomb_dropped"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Assault: when a bomb is dropped.")
            ),
            DetailedEnumValue("announce_assault_reset",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/assault/bomb_reset"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Assault: when a bomb is reset.")
            ),
            DetailedEnumValue("announce_assault_returned",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/assault/bomb_returned"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Assault: when a bomb is returned.")
            ),
            DetailedEnumValue("announce_assault_taken",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/assault/bomb_taken"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Assault: when a bomb is taken.")
            ),
            DetailedEnumValue("announce_infection",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/infection/infection"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Infection: the gametype name announced at the start of the match.")
            ),
            DetailedEnumValue("announce_infection_infected",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/infection/infected"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Infection: when you are infected and join the zombie team."),
               DetailedEnumValueInfo::make_subtitle("Infected.")
            ),
            DetailedEnumValue("announce_infection_last_man",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/infection/last_man_standing"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Infection: when you become the Last Man Standing."),
               DetailedEnumValueInfo::make_subtitle("Last man standing.")
            ),
            DetailedEnumValue("announce_infection_new_zombie",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/infection/new_zombie"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Infection: when a player becomes a zombie."),
               DetailedEnumValueInfo::make_subtitle("New zombie.")
            ),
            DetailedEnumValue("announce_oddball",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/oddball/oddball"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Oddball: the gametype name announced at the start of the match.")
            ),
            DetailedEnumValue("announce_oddball_play",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/oddball/play_ball"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Oddball: the words, \"Play ball!\""),
               DetailedEnumValueInfo::make_subtitle("Play ball.")
            ),
            DetailedEnumValue("announce_oddball_taken",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/oddball/ball_taken"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Oddball: when the ball is taken."),
               DetailedEnumValueInfo::make_subtitle("Ball taken.")
            ),
            DetailedEnumValue("announce_oddball_dropped",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/oddball/ball_dropped"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Oddball: when the ball is dropped."),
               DetailedEnumValueInfo::make_subtitle("Ball dropped.")
            ),
            DetailedEnumValue("announce_oddball_reset",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/oddball/ball_reset"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Oddball: when the ball is reset."),
               DetailedEnumValueInfo::make_subtitle("Ball reset.")
            ),
            DetailedEnumValue("announce_koth",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/king_of_the_hill/king_of_the_hill"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for King of the Hill: the gametype name announced at the start of the match.")
            ),
            DetailedEnumValue("announce_koth_controlled",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/king_of_the_hill/hill_controlled"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for King of the Hill: when your team takes control of the hill."),
               DetailedEnumValueInfo::make_subtitle("Hill controlled.")
            ),
            DetailedEnumValue("announce_koth_contested",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/king_of_the_hill/hill_contested"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for King of the Hill: when the hill is contested."),
               DetailedEnumValueInfo::make_subtitle("Hill contested.")
            ),
            DetailedEnumValue("announce_koth_moved",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/king_of_the_hill/hill_moved"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for King of the Hill: when the hill is moved."),
               DetailedEnumValueInfo::make_subtitle("Hill moved.")
            ),
            DetailedEnumValue("announce_headhunter",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/misc/headhunter"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Headhunter: the gametype name announced at the start of the match.")
            ),
            DetailedEnumValue("announce_stockpile",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/misc/stockpile"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Stockpile: the gametype name announced at the start of the match.")
            ),
            DetailedEnumValue("announce_race",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/misc/race"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Race: the gametype name announced at the start of the match.")
            ),
            DetailedEnumValue("announce_defense",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/capture_the_flag/defense"),
               DetailedEnumValueInfo::make_description("Generic announcer dialogue informing the player that they're on Defense this round."),
               DetailedEnumValueInfo::make_subtitle("Defense.")
            ),
            DetailedEnumValue("announce_offense",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/capture_the_flag/offense"),
               DetailedEnumValueInfo::make_description("Generic announcer dialogue informing the player that they're on Defense this round."),
               DetailedEnumValueInfo::make_subtitle("Offense.")
            ),
            DetailedEnumValue("announce_destination_moved",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/vip/destination_moved"),
               DetailedEnumValueInfo::make_description("Generic announcer dialogue informing the player that their destination or goal has moved."),
               DetailedEnumValueInfo::make_subtitle("Destination moved.")
            ),
            DetailedEnumValue("announce_assault_armed_2",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/assault/bomb_armed"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Assault: when a bomb is armed. This is identical to the non-suffixed enum value; it uses the same underlying sound tag.")
            ),
            DetailedEnumValue("announce_assault_armed_3",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/assault/bomb_armed"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Assault: when a bomb is armed. This is identical to the non-suffixed enum value; it uses the same underlying sound tag.")
            ),
            DetailedEnumValue("announce_assault_disarmed_2",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/assault/bomb_disarmed"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Assault: when a bomb is armed. This is identical to the non-suffixed enum value; it uses the same underlying sound tag.")
            ),
            DetailedEnumValue("announce_assault_disarmed_3",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/assault/bomb_disarmed"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Assault: when a bomb is armed. This is identical to the non-suffixed enum value; it uses the same underlying sound tag.")
            ),
            DetailedEnumValue("announce_sudden_death",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/general/sudden_death"),
               DetailedEnumValueInfo::make_description("Generic announcer dialogue informing the player that the Sudden Death period has begun.")
            ),
            DetailedEnumValue("announce_game_over",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/general/game_over"),
               DetailedEnumValueInfo::make_description("Generic announcer dialogue informing the player that the match has ended.")
            ),
            DetailedEnumValue("inv_boneyard_vo_covenant_p3_loss",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/bone_cv_defeat"),
               DetailedEnumValueInfo::make_description("Voiceover for the Covenant played when the match is lost during Phase 3."),
               DetailedEnumValueInfo::make_subtitle("No! The humans deny us our rightful victory!")
            ),
            DetailedEnumValue("inv_boneyard_vo_covenant_p1_loss",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/bone_cv_ph1_defeat"),
               DetailedEnumValueInfo::make_description("Voiceover for the Covenant played when the match is lost during Phase 1."),
               DetailedEnumValueInfo::make_subtitle("The fleetmaster will be displeased to hear of this failure!")
            ),
            DetailedEnumValue("inv_boneyard_vo_covenant_p1_intro",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/bone_cv_ph1_intro"),
               DetailedEnumValueInfo::make_description("Voiceover for the Covenant played at the start of Phase 1."),
               DetailedEnumValueInfo::make_subtitle("Take control of the access points. We will gain entry to the humans' base.")
            ),
            DetailedEnumValue("inv_boneyard_vo_covenant_p1_win",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/bone_cv_ph1_victory"),
               DetailedEnumValueInfo::make_description("Voiceover for the Covenant played upon winning Phase 1."),
               DetailedEnumValueInfo::make_subtitle("Well done. Push forward and crush the human defenses.")
            ),
            DetailedEnumValue("inv_boneyard_vo_covenant_p2_loss",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/bone_cv_ph2_defeat"),
               DetailedEnumValueInfo::make_description("Voiceover for the Covenant played when the match is lost during Phase 2."),
               DetailedEnumValueInfo::make_subtitle("The humans battle fiercely to protect this location. What is inside?")
            ),
            DetailedEnumValue("inv_boneyard_vo_covenant_p2_win",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/bone_cv_ph2_victory"),
               DetailedEnumValueInfo::make_description("Voiceover for the Covenant played upon winning Phase 2."),
               DetailedEnumValueInfo::make_subtitle("The human object is open. Retrieve it for extraction!")
            ),
            DetailedEnumValue("inv_boneyard_vo_covenant_p3_win",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/bone_cv_ph3_victory"),
               DetailedEnumValueInfo::make_description("An unused voiceover for the Covenant, apparently meant to be played at the start of a fourth phase, in which the Covenant must wait for evac."),
               DetailedEnumValueInfo::make_subtitle("Defend this location, brothers. Our Phantom will soon arrive to retrieve the object.")
            ),
            DetailedEnumValue("inv_boneyard_vo_covenant_win",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/bone_cv_victory"),
               DetailedEnumValueInfo::make_description("Voiceover for the Covenant played upon winning Phase 3."),
               DetailedEnumValueInfo::make_subtitle("Yes, brothers! Now we will take this battle to the humans' homeworld!")
            ),
            DetailedEnumValue("inv_boneyard_vo_spartan_p3_loss",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/bone_sp_defeat"),
               DetailedEnumValueInfo::make_description("Voiceover for the Spartans played when the match is lost during Phase 3."),
               DetailedEnumValueInfo::make_subtitle("Navigation core compromised; we lost it. Alert Command.")
            ),
            DetailedEnumValue("inv_boneyard_vo_spartan_p1_intro",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/bone_sp_ph1_intro"),
               DetailedEnumValueInfo::make_description("Voiceover for the Spartans played at the start of Phase 1."),
               DetailedEnumValueInfo::make_subtitle("Securing this position is priority one, Spartans. Hold off any attack.")
            ),
            DetailedEnumValue("inv_boneyard_vo_spartan_p1_win",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/bone_sp_ph1_victory"),
               DetailedEnumValueInfo::make_description("Voiceover for the Spartans played upon winning Phase 1."),
               DetailedEnumValueInfo::make_subtitle("Nice work, Spartans. They know their place.")
            ),
            DetailedEnumValue("inv_boneyard_vo_spartan_p2_intro",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/bone_sp_ph2_intro"),
               DetailedEnumValueInfo::make_description("Voiceover for the Spartans played at the start of Phase 2."),
               DetailedEnumValueInfo::make_subtitle("Fall back, to the refinery! Don't let the Covenant get hold of the navigation core.")
            ),
            DetailedEnumValue("inv_boneyard_vo_spartan_p2_win",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/bone_sp_ph2_victory"),
               DetailedEnumValueInfo::make_description("Voiceover for the Spartans played upon winning Phase 2."),
               DetailedEnumValueInfo::make_subtitle("Well done, Spartans! The core is secure.")
            ),
            DetailedEnumValue("inv_boneyard_vo_spartan_p3_win",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/bone_sp_ph3_victory"),
               DetailedEnumValueInfo::make_description("Voiceover for the Spartans played upon winning Phase 3.")
            ),
            DetailedEnumValue("inv_spire_vo_covenant_loss",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/isle_cv_defeat"),
               DetailedEnumValueInfo::make_description("Voiceover for the Covenant played when the match is lost."),
               DetailedEnumValueInfo::make_subtitle("You've lost the power core. This will not go unpunished.")
            ),
            DetailedEnumValue("inv_spire_vo_covenant_p1_win",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/isle_cv_ph1_victory"),
               DetailedEnumValueInfo::make_description("Voiceover for the Covenant played upon winning Phase 1."),
               DetailedEnumValueInfo::make_subtitle("Well done, my brothers! The humans suffer another defeat today.")
            ),
            DetailedEnumValue("inv_spire_vo_covenant_p1_intro",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/isle_cv_ph1_intro"),
               DetailedEnumValueInfo::make_description("Voiceover for the Covenant played at the start of Phase 1."),
               DetailedEnumValueInfo::make_subtitle("Hold fast, brothers. Do not let the humans pass!")
            ),
            DetailedEnumValue("inv_spire_vo_covenant_p2_intro",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/isle_cv_ph2_intro"),
               DetailedEnumValueInfo::make_description("Voiceover for the Covenant played at the start of Phase 2."),
               DetailedEnumValueInfo::make_subtitle("Return to the spire, brothers. The humans must not deactivate our shield!")
            ),
            DetailedEnumValue("inv_spire_vo_covenant_p2_win",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/isle_cv_ph2_victory"),
               DetailedEnumValueInfo::make_description("Voiceover for the Covenant played upon winning Phase 2."),
               DetailedEnumValueInfo::make_subtitle("Well done, brothers. These humans are no match for the Covenant's might!")
            ),
            DetailedEnumValue("inv_spire_vo_covenant_p3_intro",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/isle_cv_ph3_intro"),
               DetailedEnumValueInfo::make_description("Voiceover for the Covenant played at the start of Phase 3."),
               DetailedEnumValueInfo::make_subtitle("No! The humans have activated the spire. They cannot steal our power core!")
            ),
            DetailedEnumValue("inv_spire_vo_covenant_p3_win",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/isle_cv_ph3_victory"),
               DetailedEnumValueInfo::make_description("Voiceover for the Covenant played upon winning Phase 3."),
               DetailedEnumValueInfo::make_subtitle("Yes, brothers! Well done! The humans have learned a harsh lesson!")
            ),
            DetailedEnumValue("inv_spire_vo_spartan_p3_loss",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/isle_sp_defeat"),
               DetailedEnumValueInfo::make_description("An unused voiceover for the Covenant, apparently meant to be played at the start of a fourth phase, in which the Spartans must wait for evac."),
               DetailedEnumValueInfo::make_subtitle("Damn! The humans have sent for air transport. Do not let them escape!")
            ),
            DetailedEnumValue("inv_spire_vo_spartan_p1_loss",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/isle_sp_ph1_defeat"),
               DetailedEnumValueInfo::make_description("Voiceover for the Spartans played when the match is lost during Phase 1."),
               DetailedEnumValueInfo::make_subtitle("Time for a backup plan... Fall back and regroup.")
            ),
            DetailedEnumValue("inv_spire_vo_spartan_p1_extra",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/isle_sp_ph1_extra"),
               DetailedEnumValueInfo::make_description("An unused voiceover for the Spartans, apparently meant to be played at some point during Phase 1."),
               DetailedEnumValueInfo::make_subtitle("Maintain control of that platform, Spartans!")
            ),
            DetailedEnumValue("inv_spire_vo_spartan_p1_intro",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/isle_sp_ph1_intro"),
               DetailedEnumValueInfo::make_description("Voiceover for the Spartans played at the start of Phase 1."),
               DetailedEnumValueInfo::make_subtitle("Capture the access points, Spartans. Bring down the barriers.")
            ),
            DetailedEnumValue("inv_spire_vo_spartan_p1_win",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/isle_sp_ph1_victory"),
               DetailedEnumValueInfo::make_description("Voiceover for the Spartans played upon winning Phase 1."),
               DetailedEnumValueInfo::make_subtitle("Nice work, Spartans. Infiltrate their tower!")
            ),
            DetailedEnumValue("inv_spire_vo_spartan_p2_loss",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/isle_sp_ph2_defeat"),
               DetailedEnumValueInfo::make_description("Voiceover for the Spartans played when the match is lost during Phase 2."),
               DetailedEnumValueInfo::make_subtitle("Damn split-jaws won't give up that tower easy. We need a new strategy.")
            ),
            DetailedEnumValue("inv_spire_vo_spartan_p2_win",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/isle_sp_ph2_victory"),
               DetailedEnumValueInfo::make_description("Voiceover for the Spartans played upon winning Phase 2."),
               DetailedEnumValueInfo::make_subtitle("The spire's power core is up at the top! Get it to the extraction point.")
            ),
            DetailedEnumValue("inv_spire_vo_spartan_p3_win",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/isle_sp_ph3_victory"),
               DetailedEnumValueInfo::make_description("An unused voiceover for the Spartans, apparently meant to be played at the start of a fourth phase, in which the Spartans must wait for evac."),
               DetailedEnumValueInfo::make_subtitle("Pelican is on approach. Secure that LZ.")
            ),
            DetailedEnumValue("inv_spire_vo_spartan_win",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/isle_sp_victory"),
               DetailedEnumValueInfo::make_description("Voiceover for the Spartans played upon winning Phase 3."),
               DetailedEnumValueInfo::make_subtitle("Outstanding, Spartans. We have the package. Let's move.")
            ),
            DetailedEnumValue("inv_boneyard_vo_spartan_p3_loss",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/bone_sp_ph3_defeat"),
               DetailedEnumValueInfo::make_description("An unused voiceover for the Spartans, apparently meant to be played at the start of a fourth phase, in which the Covenant must wait for evac."),
               DetailedEnumValueInfo::make_subtitle("Phantom on approach; do not let them get that core on board, Spartans!")
            ),
            DetailedEnumValue("inv_spire_vo_covenant_p3_loss",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/invasion/isle_cv_ph3_defeat"),
               DetailedEnumValueInfo::make_description("An unused voiceover for the Covenant, apparently meant to be played at the start of a fourth phase, in which the Spartans must wait for evac."),
               DetailedEnumValueInfo::make_subtitle("Damn! The humans have sent for air transport! Do not let them escape!")
            ),
            DetailedEnumValue("inv_cue_covenant_win_big",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/music/invasion_temp_cues/covy_big_win"),
               DetailedEnumValueInfo::make_description("A musical cue suitable for a Covenant round victory.")
            ),
            DetailedEnumValue("inv_cue_covenant_win_1",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/music/invasion_temp_cues/covy_win1"),
               DetailedEnumValueInfo::make_description("A brief musical cue, suitable for a Covenant-Offense Phase 1 victory.")
            ),
            DetailedEnumValue("inv_cue_covenant_win_2",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/music/invasion_temp_cues/covy_win2"),
               DetailedEnumValueInfo::make_description("A brief musical cue, suitable for a Covenant-Offense Phase 2 victory.")
            ),
            DetailedEnumValue("unused_87",
               DetailedEnumValueInfo::make_unused_sentinel(),
               DetailedEnumValueInfo::make_description("An undefined/null sound effect.")
            ),
            DetailedEnumValue("inv_cue_spartan_win_big",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/music/invasion_temp_cues/unsc_big_win"),
               DetailedEnumValueInfo::make_description("A musical cue suitable for a Spartan round victory.")
            ),
            DetailedEnumValue("inv_cue_spartan_win_1",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/music/invasion_temp_cues/unsc_win1"),
               DetailedEnumValueInfo::make_description("A brief musical cue, suitable for a Spartan-Offense Phase 1 victory.")
            ),
            DetailedEnumValue("inv_cue_spartan_win_2",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/music/invasion_temp_cues/unsc_win2"),
               DetailedEnumValueInfo::make_description("A brief musical cue, suitable for a Spartan-Offense Phase 2 victory.")
            ),
            DetailedEnumValue("boneyard_generator_power_down",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/device_machines/omaha/boneyard_generator_power_down"),
               DetailedEnumValueInfo::make_description("A sound effect originally intended to indicate a generator on Boneyard powering down; it is instead used as the \"goal scored\" sound effect in Skeeball.")
            ),
            DetailedEnumValue("firefight_lives_added",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/firefight/survival_awarded_lives"),
               DetailedEnumValueInfo::make_description("Announcer dialogue for Firefight: when the players are awarded more lives.")
            ),
            DetailedEnumValue("timer_beep",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/game_sfx/multiplayer/player_timer_beep"),
               DetailedEnumValueInfo::make_description("The beep used for the respawn timer.")
            ),
            DetailedEnumValue("announce_a_under_attack",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/reach/firefight/alpha_under_attack"),
               DetailedEnumValueInfo::make_description("Generic nnouncer dialogue for Firefight: when a territory or generator designated \"A\" is under attack."),
               DetailedEnumValueInfo::make_subtitle("Alpha under attack!")
            ),
            DetailedEnumValue("announce_b_under_attack",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/reach/firefight/bravo_under_attack"),
               DetailedEnumValueInfo::make_description("Generic nnouncer dialogue for Firefight: when a territory or generator designated \"B\" is under attack."),
               DetailedEnumValueInfo::make_subtitle("Bravo under attack!")
            ),
            DetailedEnumValue("announce_c_under_attack",
               DetailedEnumValueInfo::make_map_tag('mgls', "sound/dialog/multiplayer/reach/firefight/charlie_under_attack"),
               DetailedEnumValueInfo::make_description("Generic nnouncer dialogue for Firefight: when a territory or generator designated \"C\" is under attack."),
               DetailedEnumValueInfo::make_subtitle("Charlie under attack!")
            ),
         });
      }
      //
      OpcodeArgTypeinfo sound = OpcodeArgTypeinfo(
         QString("Sound"),
         QString("A sound that can be played."),
         OpcodeArgTypeinfo::flags::none,
         //
         [](arg_functor_state fs, cobb::bitarray128& data, arg_rel_obj_list_t& relObjs, cobb::uint128_t input_bits) { // loader
            return type_helpers::enum_arg_functor_load(enums::sound, fs, data, relObjs, input_bits);
         },
         OpcodeArgTypeinfo::default_postprocess_functor,
         [](arg_functor_state fs, cobb::bitarray128& data, arg_rel_obj_list_t& relObjs, std::string& out) { // to english
            auto e = enums::sound;
            //
            // Can't use the normal "enum helper" functions because this enum has an offset, i.e. a value 
            // of -1 is used to indicate "no sound" and to avoid sign bit mishaps, the game adds 1 before 
            // serializing and subtracts 1 when loading.
            //
            int32_t index = data.excerpt(fs.bit_offset, e.index_bits());
            --index;
            if (index < 0) {
               out = "none";
               return true;
            }
            auto item = e.item(index);
            if (!item) {
               cobb::sprintf(out, "invalid value %u", index);
               return true;
            }
            QString name = item->get_friendly_name();
            if (!name.isEmpty()) {
               out = name.toStdString();
               return true;
            }
            out = item->name;
            if (out.empty()) // enum values should never be nameless but just in case
               cobb::sprintf(out, "%u", index);
            return true;
         },
         [](arg_functor_state fs, cobb::bitarray128& data, arg_rel_obj_list_t& relObjs, std::string& out) { // to script code
            auto e = enums::sound;
            //
            // Can't use the normal "enum helper" functions because this enum has an offset, i.e. a value 
            // of -1 is used to indicate "no sound" and to avoid sign bit mishaps, the game adds 1 before 
            // serializing and subtracts 1 when loading.
            //
            int32_t index = data.excerpt(fs.bit_offset, e.index_bits());
            --index;
            if (index < 0) {
               out = "none";
               return true;
            }
            auto item = e.item(index);
            if (!item) {
               cobb::sprintf(out, "%u", index);
               return true;
            }
            out = item->name;
            if (out.empty()) // enum values should never be nameless but just in case
               cobb::sprintf(out, "%u", index);
            return true;
         },
         nullptr // TODO: "compile" functor
      );
   }
}