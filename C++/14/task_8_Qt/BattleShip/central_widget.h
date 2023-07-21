#ifndef CENTRAL_WIDGET_H
#define CENTRAL_WIDGET_H

#include <QFrame>
#include <QPixmap>
#include <QPushButton>
#include "field_label.h"

namespace battleship
{
    class CentralWidget : public QFrame
    {
        Q_OBJECT

        public:
           CentralWidget(QWidget* parent = nullptr);
           virtual ~CentralWidget() {}

        signals:
           void show_message(QString message);

        private:
           FieldLabel* fieldPlayer1;
           FieldLabel* fieldPlayer2;
           QLabel* field1Label;
           QLabel* field2Label;
           QLabel* nameGame;
           QLabel* labelPlayer1;
           QLabel* labelPlayer2;
           QPushButton* buttonPlayer1;

           QPoint getCoordOnField(QPoint mouseCoord);
    };

}

#endif // CENTRAL_WIDGET_H
