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
    QTimer * timer= new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(setBarrier()));
    timer->start(10);
}

void barrier::setBarrier()
{
    if (pos().x()==bird::get_x()-500 && pos().y()+70 == bird::get_y()+500)
    {
        qDebug()<<"you lose";
    }

    else
    {
        setX(pos().x()-1);
        qDebug()<<"barrier x : "<<pos().x();
        qDebug()<<"barrier y : "<<pos().y();
    }

    if (pos().x()<-500)
    {
        setX(pos().x()+430);
    }
}
