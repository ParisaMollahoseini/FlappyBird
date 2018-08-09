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

void barrier::setBarrier()
{
        setX(pos().x()-1);
        qDebug()<<"barrier x : "<<pos().x()<<" xx:"<<rect().x();
        qDebug()<<"barrier y : "<<pos().y();

    if (pos().x()<-856)
    {
        setX(pos().x()+945);
    }
}
