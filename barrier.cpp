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
    timer->start(250);
}

void barrier::setBarrier()
{
    if (pos().x()==bird::get_x() && pos().y()== bird::get_y())
    {
        qDebug()<<"you lose";
        this->~barrier();
    }

    else
    {
        setX(pos().x()-20);
    }
        qDebug()<<"here";
}
