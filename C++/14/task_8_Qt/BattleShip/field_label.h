#ifndef FIELD_LABEL_H
#define FIELD_LABEL_H

#include <QLabel>
#include <QPixmap>
#include <QTimer>

namespace battleship
{
    class FieldLabel : public QLabel
    {
        Q_OBJECT

        public:
            FieldLabel(QWidget* parent = nullptr);
            virtual ~FieldLabel() {}

        signals:
            void show_message(QString message);
            void set_ship(QPoint paintingPoint, QPoint point, bool& checkShip);

        public slots:
            void startSetShip(QPoint point);
            void stopSetShip(QPoint point);
            void twinklePoint();

        protected:
            virtual void mouseReleaseEvent(QMouseEvent *event);

        private:
            QPixmap* pxmp;
            QPixmap tmpPxmp;
            QTimer *twinkleTimer;
            QPoint paintingPoint;
            QColor twinkleColor;
            bool twinkleTurn;
            bool startStopPaintShip;
            bool paintTwinkle;
            bool killTwinkle;

            void fillRect(QRect rect);
            void paintRect(QRect rect);
            void paintRect(QRect rect, qreal lineSize, QColor color = Qt::black);
            void paintShip(QRect rect);
            void getTmpPxmp();
            void setTmpPxmp();
            void paintGrid();
            QPoint getCoordOnGrid(QPoint mouseCoord);
            QRect getIndxRect(QPoint indxPoint);
    };
}

#endif // FIELD_LABEL_H
