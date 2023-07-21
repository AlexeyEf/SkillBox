#include "central_widget.h"
#include <QBoxLayout>
#include <QPainter>

namespace battleship
{
    CentralWidget::CentralWidget(QWidget *parent) : QFrame(parent)
    {
        QVBoxLayout *mainVLayout = new QVBoxLayout(this);
        mainVLayout->setMargin(9);

        QHBoxLayout *hLayout = new QHBoxLayout();
        hLayout->setMargin(9);

        QVBoxLayout *vLayout1 = new QVBoxLayout();
        vLayout1->setMargin(9);

        QVBoxLayout *vLayout2 = new QVBoxLayout();
        vLayout2->setMargin(9);

        hLayout->addLayout(vLayout1);
        hLayout->addLayout(vLayout2);

        nameGame = new QLabel("Игра Морской бой", this);
        mainVLayout->addWidget(nameGame);

        mainVLayout->addLayout(hLayout);

        field1Label = new QLabel("Свое поле", this);
        field2Label = new QLabel("Поле противника", this);

        buttonPlayer1 = new QPushButton("Сделать ход", this);

        fieldPlayer1 = new FieldLabel(this);
        fieldPlayer2 = new FieldLabel(this);

        vLayout1->addWidget(field1Label);
        vLayout2->addWidget(field2Label);

        vLayout1->addWidget(fieldPlayer1);
        vLayout2->addWidget(fieldPlayer2);

        vLayout1->addWidget(buttonPlayer1);

        connect(fieldPlayer1, SIGNAL(show_message(QString)), this, SIGNAL(show_message(QString)));
    }


    QPoint CentralWidget::getCoordOnField(QPoint mouseCoord)
    {

    }

}
