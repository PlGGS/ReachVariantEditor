#pragma once
#include "ui_localized_string_editor.h"
#include <vector>
#include "../formats/localized_string_table.h"

class LocalizedStringEditorModal : public QDialog {
   public:
   using Flags = ReachStringFlags::type;
   public:
      LocalizedStringEditorModal(QWidget* parent = nullptr);
      //
      static void startEditing(QWidget* parent, uint32_t flags = 0, ReachString* target = nullptr);
      //
   private:
      Ui::LocalizedStringEditorModal ui;
      //
      std::vector<QLineEdit*> languageFields;
      //
      ReachString* _target = nullptr;
      bool _limitToSingleLanguageStrings = false;
      //
      void updateControls();
};