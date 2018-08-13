#include "barrier.h"

barrier::barrier()
{


}

barrier::~barrier()
{
    qDebug()<<"barrier destructor";

}

void barrier::start()
{
    timer= new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(setBarrier()));
    timer->start(10);
}

void barrier::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setFlag(QGraphicsItem::ItemUsesExtendedStyleOption);
    QPen * pen = new QPen(Qt::green);
    pen->setWidth(5);
    pen->setBrush(Qt::SolidPattern);

    painter->fillRect(300, 0, 60, 200, Qt::green);
    painter->fillRect(290, 200, 80, 50, Qt::green);
    painter->fillRect(300, 500, 60, 400, Qt::green);
    painter->fillRect(290, 450, 80, 50, Qt::green);

    painter->fillRect(480, 0, 60, 300, Qt::green);
    painter->fillRect(470, 300, 80, 50, Qt::green);
    painter->fillRect(480, 600, 60, 300, Qt::green);
    painter->fillRect(470, 550, 80, 50, Qt::green);

    painter->fillRect(660, 0, 60, 450, Qt::green);
    painter->fillRect(650, 450, 80, 50, Qt::green);
    painter->fillRect(660, 750, 60, 150, Qt::green);
    painter->fillRect(650, 700, 80, 50, Qt::green);

    painter->fillRect(840, 0, 60, 350, Qt::green);
    painter->fillRect(830, 350, 80, 50, Qt::green);
    painter->fillRect(840, 650, 60, 250, Qt::green);
    painter->fillRect(830, 600, 80, 50, Qt::green);

    painter->setViewTransformEnabled(1);
}

void barrier::setBarrier()
{
        setX(pos().x()-1);
        //qDebug()<<"barrier x : "<<pos().x()<<" xx:"<<rect().x();
       // qDebug()<<"barrier y : "<<pos().y();

    if (pos().x()<-856)
    {
        setX(pos().x()+945);
    }
}
