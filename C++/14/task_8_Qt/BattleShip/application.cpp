#include "application.h"

namespace battleship
{
    Application::Application(int &argc, char **argv) : QApplication(argc, argv)
    {
        setApplicationName(tr("BattleShip"));
        setApplicationDisplayName(tr("Морской бой"));
    }
}
