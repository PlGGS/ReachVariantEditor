#pragma once
#include <cstdint>

#include <QtWidgets/QMainWindow>
#include "ui_ReachVariantTool.h"

class ReachLoadoutPalette;
class ReachPlayerTraits;
class ReachTeamData;

class ReachVariantTool : public QMainWindow {
   Q_OBJECT
   //
   public:
      ReachVariantTool(QWidget* parent = Q_NULLPTR); // needs to be public for Qt? but do not call; use the static getter
      //
      static ReachVariantTool& get(); // done differently because the usual "static singleton getter" approach causes Qt to crash on exit if applied to the main window
      //
   private slots:
      void updateDescriptionCharacterCount();
      //
   private:
      void _saveFileImpl(bool saveAs);
      //
      void openFile();
      void saveFile()   { this->_saveFileImpl(false); }
      void saveFileAs() { this->_saveFileImpl(true); }
      void onSelectedPageChanged();
      //
      void switchToLoadoutPalette(ReachLoadoutPalette*);
      void switchToPlayerTraits(ReachPlayerTraits*);
      //
      void refreshWidgetsFromVariant();
      void refreshWidgetsForLoadoutPalette();
      void refreshWidgetsForPlayerTraits();
      void refreshScriptedPlayerTraitList();
      void refreshWindowTitle();
      //
      void setupWidgetsForScriptedOptions();
      //
      template<int N> void _setupComboboxForUnsafeOption(QComboBox* widget) {
         QObject::connect(widget, QOverload<int>::of(&QComboBox::currentIndexChanged), [widget](int value) {
            bool allow = true;
            if (!ReachINI::Editing::bAllowUnsafeValues.current.b)
               allow = (value != N);
            ReachVariantTool::get().setStateForWidgetForUnsafeOption(widget, !allow);
         });
      }
      template<int N> inline void _refreshComboboxForUnsafeOption(QComboBox* widget) {
         bool allow = true;
         if (!ReachINI::Editing::bAllowUnsafeValues.current.b)
            allow = (widget->currentIndex() != N);
         this->setStateForWidgetForUnsafeOption(widget, !allow);
      }
      void setupWidgetsForUnsafeOptions();
      void setStateForWidgetForUnsafeOption(QWidget*, bool disable);
      void refreshWidgetsForUnsafeOptions();
      //
      int8_t currentTeam = -1;
      void switchToTeam(int8_t team);
      void refreshTeamColorWidgets();
      ReachTeamData* _getCurrentTeam() const noexcept;
      //
   private:
      Ui::ReachVariantToolClass ui;
};
