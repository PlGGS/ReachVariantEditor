#include "page_multiplayer_settings_map.h"

PageMPSettingsMapAndGame::PageMPSettingsMapAndGame(QWidget* parent) : QWidget(parent) {
   ui.setupUi(this);
   //
   auto& editor = ReachEditorState::get();
   QObject::connect(&editor, &ReachEditorState::variantAcquired, this, &PageMPSettingsMapAndGame::updateFromVariant);
   //
   #include "widget_macros_setup_start.h"
   reach_main_window_setup_flag_checkbox(this->ui.fieldGrenades,  options.map.flags, 0x01);
   reach_main_window_setup_flag_checkbox(this->ui.fieldShortcuts, options.map.flags, 0x02);
   reach_main_window_setup_flag_checkbox(this->ui.fieldAbilities, options.map.flags, 0x04);
   reach_main_window_setup_flag_checkbox(this->ui.fieldPowerups,  options.map.flags, 0x08);
   reach_main_window_setup_flag_checkbox(this->ui.fieldTurrets,   options.map.flags, 0x10);
   reach_main_window_setup_flag_checkbox(this->ui.fieldIndestructibleVehicles, options.map.flags, 0x20);
   {  // Weapon Set
      QComboBox* widget = this->ui.fieldWeaponSet;
      //
      // -2 = Map Default
      // -1 = No Weapons
      //  0 = Human
      //  1 = Covenant
      //
      QObject::connect(widget, QOverload<int>::of(&QComboBox::currentIndexChanged), [](int index) {
         auto data = ReachEditorState::get().multiplayerData();
         if (!data)
            return;
         int8_t value;
         switch (index) {
            case 0: // Map Default
               value = -2; // Map Default
               break;
            case 16:
               value = -1; // No Weapons
               break;
            default:
               value = index - 1;
         }
         data->options.map.weaponSet = value;
      });
   }
   {  // Vehicle Set
      QComboBox* widget = this->ui.fieldVehicleSet;
      //
      // -2 = Map Default
      //  0 = Mongooses
      //  1 = Warthogs
      // 12 = No Vehicles
      //
      QObject::connect(widget, QOverload<int>::of(&QComboBox::currentIndexChanged), [](int index) {
         auto data = ReachEditorState::get().multiplayerData();
         if (!data)
            return;
         int8_t value;
         switch (index) {
            case 0: // Map Default
               value = -2; // Map Default
               break;
            default:
               value = index - 1;
         }
         data->options.map.vehicleSet = value;
      });
   }
   reach_main_window_setup_spinbox(this->ui.fieldPowerupDurationRed,    options.map.powerups.red.duration);
   reach_main_window_setup_spinbox(this->ui.fieldPowerupDurationBlue,   options.map.powerups.blue.duration);
   reach_main_window_setup_spinbox(this->ui.fieldPowerupDurationYellow, options.map.powerups.yellow.duration);
   #include "widget_macros_setup_end.h"
}
void PageMPSettingsMapAndGame::updateFromVariant(GameVariant* variant) {
   auto mp = variant->get_multiplayer_data();
   if (!mp)
      return;
   #include "widget_macros_update_start.h"
   reach_main_window_update_flag_checkbox(this->ui.fieldGrenades, options.map.flags, 0x01);
   reach_main_window_update_flag_checkbox(this->ui.fieldShortcuts, options.map.flags, 0x02);
   reach_main_window_update_flag_checkbox(this->ui.fieldAbilities, options.map.flags, 0x04);
   reach_main_window_update_flag_checkbox(this->ui.fieldPowerups, options.map.flags, 0x08);
   reach_main_window_update_flag_checkbox(this->ui.fieldTurrets, options.map.flags, 0x10);
   reach_main_window_update_flag_checkbox(this->ui.fieldIndestructibleVehicles, options.map.flags, 0x20);
   {  // Weapon Set
      QComboBox* widget = this->ui.fieldWeaponSet;
      const QSignalBlocker blocker(widget);
      auto value = mp->options.map.weaponSet;
      int  index;
      switch (value) {
         case -2:
            index = 0;
            break;
         case -1:
            index = 16;
            break;
         default:
            index = value + 1;
      }
      widget->setCurrentIndex(index);
   }
   {  // Vehicle Set
      QComboBox* widget = this->ui.fieldVehicleSet;
      const QSignalBlocker blocker(widget);
      auto value = mp->options.map.vehicleSet;
      int  index;
      switch (value) {
         case -2:
            index = 0;
            break;
         default:
            index = value + 1;
      }
      widget->setCurrentIndex(index);
   }
   reach_main_window_update_spinbox(this->ui.fieldPowerupDurationRed,    options.map.powerups.red.duration);
   reach_main_window_update_spinbox(this->ui.fieldPowerupDurationBlue,   options.map.powerups.blue.duration);
   reach_main_window_update_spinbox(this->ui.fieldPowerupDurationYellow, options.map.powerups.yellow.duration);
   #include "widget_macros_update_end.h"
}