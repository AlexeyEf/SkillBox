#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "central_widget.h"
#include "play_manager.h"

class QStackedWidget;
class QStatusBar;

namespace battleship
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

        public:
            MainWindow(QWidget *parent = nullptr);
            ~MainWindow();

        private:
            QStackedWidget* stackWidgets;
            QStatusBar* statusBar;
            CentralWidget* fieldPlayer1;
            CentralWidget* fieldPlayer2;
            PlayManager* playManager;
    };
}
#endif // MAINWINDOW_H
