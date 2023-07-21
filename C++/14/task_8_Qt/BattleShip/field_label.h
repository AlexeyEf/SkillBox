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

        public slots:
            void startSetShip(QPoint point);
            void stopSetShip(QPoint point);
            void twinklePoint();

        protected:
            virtual void mouseReleaseEvent(QMouseEvent *event);

        private:
            QPixmap* pxmp;
            QTimer *twinkleTimer;
            QPoint paintingPoint;
            QColor twinkleColor;
            bool twinkleTurn;
            bool startStopPaintShip;
            bool paintTwinkle;
            bool killTwinkle;

            //void paintRect(QRect rect);
            void paintRect(QRect rect, QColor color = Qt::black);
            void paintGrid();
            QPoint getCoordOnGrid(QPoint mouseCoord);
            QRect getIndxRect(QPoint indxPoint);
    };

}

#endif // FIELD_LABEL_H
