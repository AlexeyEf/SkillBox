#include "mainwindow.h"
#include <QStackedWidget>
#include <QStatusBar>

namespace battleship
{
    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
    {
        stackWidgets = new QStackedWidget(this);
        fieldPlayer1 = new CentralWidget();
        fieldPlayer2 = new CentralWidget();
        stackWidgets->addWidget(fieldPlayer1);
        stackWidgets->addWidget(fieldPlayer2);
        setCentralWidget(stackWidgets);

        statusBar = new QStatusBar(this);
        setStatusBar(statusBar);

        playManager = new PlayManager(this);

        //connect(playManager, SIGNAL(ship_is_set(bool), fieldPlayer1, SLOT()))
        connect(fieldPlayer1, SIGNAL(show_message(QString)), statusBar, SLOT(showMessage(QString)));
    }

    MainWindow::~MainWindow()
    {
    }
}



