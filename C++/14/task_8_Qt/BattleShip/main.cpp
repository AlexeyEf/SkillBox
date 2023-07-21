#include "mainwindow.h"
#include "application.h"

int main(int argc, char *argv[])
{
    battleship::Application a(argc, argv);
    battleship::MainWindow w;
    w.show();
    return a.exec();
}
