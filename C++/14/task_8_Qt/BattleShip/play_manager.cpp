#include "play_manager.h"
#include <QDebug>

namespace battleship
{
    PlayManager::PlayManager(QObject* parent) : QObject(parent), playerField(10, QVector<bool>(10, false)),
                                                                 playerFieldSet(false),
                                                                 opponentFieldSet(false),
                                                                 countShips(4,0)
    {

    }

    void PlayManager::setShip(QPoint indxBegin, QPoint indxEnd)
    {
        bool successSetShip = false;
        //проверка на корректность нового введенного корабля
        if(checkShip(indxBegin, indxEnd))
        {
            //установка нового корабля на поле
            setShipOnField(indxBegin, indxEnd);
            successSetShip = true;
        }
    }

    void PlayManager::setShip(QPoint indxBegin, QPoint indxEnd, bool& checkingShip)
    {
        //проверка на корректность нового введенного корабля
        if(checkShip(indxBegin, indxEnd))
        {
            //установка нового корабля на поле
            setShipOnField(indxBegin, indxEnd);
            checkingShip = true;
        }
        else
        {
            int sum = 0;
            for(int i = 0; i < 3; ++i)
            {
                sum += countShips[i];
            }
            if(sum == 10)
            {
                playerFieldSet = true;
                if(opponentFieldSet)
                {
                    emit set_all_ships();
                }
                else
                {
                    emit set_all_player_ships();
                }
            }
        }
    }

    QVector<QVector<bool>> PlayManager::getOpponentField() const
    {
        return opponentField;
    }

    void PlayManager::setOpponentField(const QVector<QVector<bool>> &value)
    {
        opponentField = value;
    }

    bool PlayManager::checkShip(QPoint indxBegin, QPoint indxEnd)
    {
        //проверка на корректность нового введенного корабля
        int xLength = indxEnd.x() - indxBegin.x();
        int yLength = indxEnd.y() - indxBegin.y();
        //проверка что на одной линии
        if(indxBegin.x() == indxEnd.x() ||
           indxBegin.y() == indxEnd.y()    )
        {
            //проверка размера
            if(indxBegin.x()-indxEnd.x() < 4 &&
               xLength < 4                   &&
               indxBegin.y()-indxEnd.y() < 4 &&
               yLength < 4                       )
            {
                //проверка что не превышен лимит кораблей
                //однопалубник
                if(!(xLength || yLength))
                {
                    if(countShips[0] >= 4)
                    {
                        return false;
                    }
                    else
                    {
                        ++countShips[0];
                    }
                }
                //двухпалубник
                else if(xLength == 1 || yLength == 1)
                {
                    if(countShips[1] >= 3)
                    {
                        return false;
                    }
                    else
                    {
                        ++countShips[1];
                    }
                }
                //трехпалубник
                else if(xLength == 2 || yLength == 2)
                {
                    if(countShips[2] >= 2)
                    {
                        return false;
                    }
                    else
                    {
                        ++countShips[2];
                    }
                }
                //четырехпалубник
                else if(xLength == 3 || yLength == 3)
                {
                    if(countShips[3] >= 1)
                    {
                        return false;
                    }
                    else
                    {
                        ++countShips[3];
                    }
                }
                qDebug() << "indxBegin.x() = " << indxBegin.x();
                qDebug() << "indxEnd.x() = "   << indxEnd.x();
                //проверка что устанавливается на свободное поле
                for(int i = indxBegin.x(); i <= indxEnd.x(); ++i)
                {
                    for(int j = indxBegin.y(); j <= indxEnd.y(); ++j)
                    {
                        if(playerField.at(i).at(j))
                        {
                            return false;
                        }
                    }
                }

                return true;
            }
        }
        return false;
    }

    void PlayManager::setShipOnField(QPoint indxBegin, QPoint indxEnd)
    {
        for(int i = indxBegin.x(); i <= indxEnd.x(); ++i)
        {
            for(int j = indxBegin.y(); j <= indxEnd.y(); ++j)
            {
                playerField[i][j] = true;
                qDebug() << "field[" << i << "][" << j << "]" << playerField[i][j];
            }
        }
    }

}
