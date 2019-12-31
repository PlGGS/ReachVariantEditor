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
      static ReachVariantTool& get(); // done differently because the usual "static singleton getter" approach apparently causes Qt to crash on exit if applied to the main window
      //
   private slots:
      //
   private:
      void _saveFileImpl(bool saveAs);
      //
      void openFile();
      void saveFile()   { this->_saveFileImpl(false); }
      void saveFileAs() { this->_saveFileImpl(true); }
      void onSelectedPageChanged(QTreeWidgetItem* current, QTreeWidgetItem* previous);
      //
      void regenerateNavigation();
      //
      void switchToLoadoutPalette(ReachLoadoutPalette*);
      void switchToPlayerTraits(ReachPlayerTraits*);
      //
      void refreshWindowTitle();
      //
   private:
      Ui::ReachVariantToolClass ui;
};
