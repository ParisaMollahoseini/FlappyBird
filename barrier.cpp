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
    if (pos().x()==0 && pos().y() == bird::get_y())
    {
        qDebug()<<"you lose";
    }

    else
    {
        setX(pos().x()-1);
        qDebug()<<"barrier x : "<<pos().x()<<" xx:"<<rect().x();
        qDebug()<<"barrier y : "<<pos().y();
    }

    if (pos().x()<-856)
    {
        setX(pos().x()+945);
    }
}
