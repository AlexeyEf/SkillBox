# include "play_manager.h"

namespace battleship
{
    PlayManager::PlayManager(QObject* parent) : QObject(parent), field(10, QVector<bool>(10, false))
    {

    }

    void PlayManager::setShip(QPoint indxBegin, QPoint indxEnd)
    {
        bool successSetShip = false;
        //проверка на корректность нового введенного корабля
        if(checkIsOccupied(indxBegin, indxEnd))
        {
            //установка нового корабля на поле
            setShipOnField(indxBegin, indxEnd);
            successSetShip = true;
        }
        emit ship_is_set(successSetShip);//как лучше вернуть информацию об успешном или неуспешном
                             //размещении корабля в экземпляр другого класса?
    }

    bool PlayManager::checkIsOccupied(QPoint indxBegin, QPoint indxEnd)
    {
        //проверка на корректность нового введенного корабля

        //проверка что на одной линии
        if(indxBegin.x() == indxEnd.x() ||
           indxBegin.y() == indxEnd.y()    )
        {
            //проверка размера
            if(indxBegin.x()-indxEnd.x() < 5 ||
               indxEnd.x()-indxBegin.x() < 5    )
            {
                //проверка что устанавливается на свободное поле
                for(int i = indxBegin.x(); i < indxEnd.x(); ++i)
                {
                    for(int j = indxBegin.y(); j < indxEnd.y(); ++j)
                    {
                        if(field.at(i).at(j))
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
        for(int i = indxBegin.x(); i < indxEnd.x(); ++i)
        {
            for(int j = indxBegin.y(); j < indxEnd.y(); ++j)
            {
                field[i][j] = true;
            }
        }
    }

}
