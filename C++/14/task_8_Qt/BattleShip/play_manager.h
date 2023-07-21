#ifndef PLAY_MANAGER_H
#define PLAY_MANAGER_H

#include <QObject>
#include <QPoint>

namespace  battleship
{
    class PlayManager : public QObject
    {
        Q_OBJECT

        public:
            PlayManager(QObject* parent = nullptr);
            virtual ~PlayManager() {}

        signals:
            void kill_ship(QPoint indxBegin, QPoint indxEnd);
            void ship_is_set(bool successSetShip);
            void kill_point(QPoint indx);

        public slots:
            void setShip(QPoint indxBegin, QPoint indxEnd);
            //void goTurn(QPoint indxTurn);

        private:
            QVector<QVector<bool>> field;

            bool checkIsOccupied(QPoint indxBegin, QPoint indxEnd);
            void setShipOnField(QPoint indxBegin, QPoint indxEnd);
    };
}

#endif // PLAY_MANAGER_H
