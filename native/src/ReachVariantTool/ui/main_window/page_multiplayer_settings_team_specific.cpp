#include "page_multiplayer_settings_team_specific.h"
#include <QColorDialog>
#include "../../game_variants/components/teams.h"
#include "../localized_string_editor.h"

namespace {
   QColor _colorFromReach(uint32_t c) {
      return QColor((c >> 0x10) & 0xFF, (c >> 0x08) & 0xFF, c & 0xFF);
   }
   uint32_t _colorToReach(const QColor& c) {
      return ((c.red() & 0xFF) << 0x10) | ((c.green() & 0xFF) << 0x08) | (c.blue() & 0xFF);
   }
}

PageMPSettingsTeamSpecific::PageMPSettingsTeamSpecific(QWidget* parent) : QWidget(parent) {
   ui.setupUi(this);
   //
   auto& editor = ReachEditorState::get();
   QObject::connect(&editor, &ReachEditorState::switchedMultiplayerTeam, this, &PageMPSettingsTeamSpecific::updateFromVariant);
   QObject::connect(&editor, &ReachEditorState::teamColorModified,       this, &PageMPSettingsTeamSpecific::updateTeamColor);
   //
   QObject::connect(this->ui.buttonName, &QPushButton::clicked, [this]() {
      auto& editor = ReachEditorState::get();
      auto  team   = editor.multiplayerTeam();
      if (!team)
         return;
      bool  created = false;
      auto* string  = team->get_name();
      if (!string) {
         created = true;
         string  = team->name.add_new(); // add a temporary string; if the user confirms changes, then we'll keep it
         if (!string)
            return;
      }
      auto index = string->index; // should always be zero
      if (LocalizedStringEditorModal::editString(this, ReachStringFlags::SingleLanguageString | ReachStringFlags::IsNotInStandardTable, string)) {
         auto& english = string->get_content(reach::language::english);
         this->ui.fieldName->setText(QString::fromUtf8(english.c_str()));
         if (!english.size())
            //
            // I suspect the game would actually support zero-length team names, but don't allow that. If the 
            // name is cleared, revert to using the engine default.
            //
            if (index >= 0)
               team->name.remove(index);
      } else {
         if (created && index >= 0)
            team->name.remove(index);
      }
   });
   //
   #include "widget_macros_setup_start.h"
   reach_team_pane_setup_flag_checkbox(this->ui.fieldEnabled,              flags, ReachTeamData::Flags::enabled);
   reach_team_pane_setup_flag_checkbox(this->ui.fieldEnableColorPrimary,   flags, ReachTeamData::Flags::override_color_primary);
   reach_team_pane_setup_flag_checkbox(this->ui.fieldEnableColorSecondary, flags, ReachTeamData::Flags::override_color_secondary);
   reach_team_pane_setup_flag_checkbox(this->ui.fieldEnableColorText,      flags, ReachTeamData::Flags::override_color_text);
   reach_team_pane_setup_combobox(this->ui.fieldSpecies, spartanOrElite);
   reach_team_pane_setup_spinbox(this->ui.fieldFireteamCount, fireteamCount);
   reach_team_pane_setup_spinbox(this->ui.fieldInitialDesignator, initialDesignator);
   QObject::connect(this->ui.fieldButtonColorPrimary, &QPushButton::clicked, [this]() {
      auto& editor = ReachEditorState::get();
      auto  team   = editor.multiplayerTeam();
      if (!team)
         return;
      auto color = QColorDialog::getColor(_colorFromReach(team->colorPrimary), this->window());
      if (!color.isValid())
         return;
      team->colorPrimary = _colorToReach(color);
      editor.teamColorModified(team);
   });
   QObject::connect(this->ui.fieldButtonColorSecondary, &QPushButton::clicked, [this]() {
      auto& editor = ReachEditorState::get();
      auto  team   = editor.multiplayerTeam();
      if (!team)
         return;
      auto color = QColorDialog::getColor(_colorFromReach(team->colorSecondary), this->window());
      if (!color.isValid())
         return;
      team->colorSecondary = _colorToReach(color);
      editor.teamColorModified(team);
   });
   QObject::connect(this->ui.fieldButtonColorText, &QPushButton::clicked, [this]() {
      auto& editor = ReachEditorState::get();
      auto  team   = editor.multiplayerTeam();
      if (!team)
         return;
      auto color = QColorDialog::getColor(_colorFromReach(team->colorText), this->window());
      if (!color.isValid())
         return;
      team->colorText = _colorToReach(color);
      editor.teamColorModified(team);
   });
   #include "widget_macros_setup_end.h"
}
void PageMPSettingsTeamSpecific::updateFromVariant(GameVariant* variant, int8_t teamIndex, ReachTeamData* team) {
   if (!team) {
      this->ui.buttonName->setDisabled(true);
      return;
   }
   #include "widget_macros_update_start.h"
   {
      auto name = team->get_name();
      if (name)
         this->ui.fieldName->setText(QString::fromUtf8(name->get_content(reach::language::english).c_str()));
      else
         this->ui.fieldName->setText("");
      this->ui.buttonName->setDisabled(false);
   }
   reach_team_pane_update_flag_checkbox(this->ui.fieldEnabled,              flags, ReachTeamData::Flags::enabled);
   reach_team_pane_update_flag_checkbox(this->ui.fieldEnableColorPrimary,   flags, ReachTeamData::Flags::override_color_primary);
   reach_team_pane_update_flag_checkbox(this->ui.fieldEnableColorSecondary, flags, ReachTeamData::Flags::override_color_secondary);
   reach_team_pane_update_flag_checkbox(this->ui.fieldEnableColorText,      flags, ReachTeamData::Flags::override_color_text);
   reach_team_pane_update_combobox(this->ui.fieldSpecies, spartanOrElite);
   reach_team_pane_update_spinbox(this->ui.fieldFireteamCount, fireteamCount);
   reach_team_pane_update_spinbox(this->ui.fieldInitialDesignator, initialDesignator);
   #include "widget_macros_update_end.h"
   this->updateTeamColor(team);
}
void PageMPSettingsTeamSpecific::updateTeamColor(ReachTeamData* team) {
   if (!team)
      return;
   const QString style("QPushButton { background-color : %1; }");
   this->ui.fieldButtonColorPrimary->setStyleSheet(style.arg(_colorFromReach(team->colorPrimary).name()));
   this->ui.fieldButtonColorSecondary->setStyleSheet(style.arg(_colorFromReach(team->colorSecondary).name()));
   this->ui.fieldButtonColorText->setStyleSheet(style.arg(_colorFromReach(team->colorText).name()));
}