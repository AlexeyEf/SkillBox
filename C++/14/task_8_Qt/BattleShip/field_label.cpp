#include "field_label.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

namespace battleship
{
     FieldLabel::FieldLabel(QWidget *parent) : QLabel(parent), twinkleTurn(false), startStopPaintShip(false)
     {
         pxmp = new QPixmap(300, 270);
         pxmp->fill(Qt::white);

         setPixmap(*pxmp);

         paintGrid();

         twinkleTimer = new QTimer(this);

         connect(twinkleTimer, SIGNAL(timeout()), this, SLOT(twinklePoint()));
     }

     void FieldLabel::paintGrid()
     {
         QPainter painter;
         if(!painter.begin(pxmp))
         {
             return;
         }
         painter.setPen(Qt::black);

         int beginX = 45;
         int beginY = 35;

         int fieldWidth = pxmp->width() - 20;
         int fieldHeight = pxmp->height() - 20;

         //рисование рамки поля
         QRect rect(beginX, beginY, 200, 200);
         painter.drawRect(rect);
         //рисование сетки поля
         ///вертикальные полосы
         for(int i = 1; i < 11; ++i)
         {
             painter.drawLine(beginX + 20*i, beginY, beginX + 20*i, beginY + 200);
             painter.drawText(beginX + 20*i - 10, beginY - 5, QString::number(i-1));
         }
         ///горизонтальные полосы
         for(int i = 1; i < 11; ++i)
         {
             painter.drawLine(beginX, beginY + 20*i, beginX + 200, beginY + 20*i);
             painter.drawText(beginX - 10, beginY + 20*i - 5, QString::number(i-1));
         }

         painter.end();
         setPixmap(*pxmp);
     }

     QPoint FieldLabel::getCoordOnGrid(QPoint mouseCoord)
     {
           QPoint beginPoint = QPoint(45,35);
           QPoint indx((mouseCoord.x() - beginPoint.x())/20, (mouseCoord.y() - beginPoint.y())/20);
           qDebug() << "current indx = " << indx;
           return indx;
     }

     QRect FieldLabel::getIndxRect(QPoint indxPoint)
     {
         QRect indxRect(indxPoint.x()*20 + 45, indxPoint.y()*20 + 35, 20, 20);
         qDebug() << "indxRect = " << indxRect.topLeft().x() << " " << indxRect.topLeft().y();
         return indxRect;
     }

     void FieldLabel::mouseReleaseEvent(QMouseEvent *event)
     {
         if(startStopPaintShip)
         {
             stopSetShip(getCoordOnGrid(event->pos()));
         }
         else
         {
             startSetShip(getCoordOnGrid(event->pos()));
         }
     }

     void FieldLabel::startSetShip(QPoint point)
     {
         if(point.isNull())
         {
             return;
         }
         paintingPoint = point;
         twinkleTimer->start(200);
         paintRect(getIndxRect(point));
         startStopPaintShip = true;
         show_message("Установите конечную координату корабля");
     }

     void FieldLabel::stopSetShip(QPoint point)
     {
         if(point.isNull())
         {
             return;
         }
         twinkleTimer->stop();
         QRect rect(getIndxRect(paintingPoint).topLeft(), getIndxRect(point).bottomRight());
         qDebug() << rect.topLeft().x() << rect.topLeft().y()
                  << rect.bottomRight().x() << rect.bottomRight().y();
         paintRect(rect);
         paintingPoint = point;
         startStopPaintShip = false;
         show_message("Корабль установлен");
     }

     void FieldLabel::paintRect(QRect rect, QColor color)
     {
         QPainter painter;

         if(!painter.begin(pxmp))
         {
             return;
         }
         QBrush brush(twinkleColor);
         qDebug() << twinkleColor.name();
         QPen pen(brush, 2.5);
         painter.setPen(pen);
         painter.drawRect(rect);

         painter.end();
         setPixmap(*pxmp);
     }

     void FieldLabel::twinklePoint()
     {
         if(twinkleTurn)
         {
             twinkleColor=Qt::black;
             twinkleTurn = false;
         }
         else
         {
             twinkleColor=Qt::darkGreen;
             twinkleTurn = true;
         }
         paintRect(getIndxRect(paintingPoint));
     }

}
