#ifndef PLAY_MANAGER_H
#define PLAY_MANAGER_H

#include <QObject>
#include <QPoint>
#include <QVector>

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
            void set_all_player_ships();
            void set_all_opponent_ships();
            void set_all_ships();


        public slots:
            void setShip(QPoint indxBegin, QPoint indxEnd);
            void setShip(QPoint indxBegin, QPoint indxEnd, bool& checkingShip);
            //void goTurn(QPoint indxTurn);

        private:
            QVector<QVector<bool>> playerField;
            QVector<QVector<bool>> opponentField;
            bool playerFieldSet;
            bool opponentFieldSet;

            QVector<int> countShips;

            QVector<QVector<bool>> getOpponentField() const;
            void setOpponentField(const QVector<QVector<bool>> &value);

            bool checkShip(QPoint indxBegin, QPoint indxEnd);
            void setShipOnField(QPoint indxBegin, QPoint indxEnd);
    };
}

#endif // PLAY_MANAGER_H
