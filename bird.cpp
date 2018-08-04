#include "bird.h"
#include<QDebug>
#include<QGraphicsEffect>
#include<QPainter>
bird::bird()
{
}

bird::~bird()
{
    qDebug()<<"bird destructor";
}

void bird::start()
{
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(up()));
    timer->start(150);
}

int bird::get_x()
{
    return pos_x;
}

int bird::get_y()
{
    return pos_y;
}

void bird::set_x(int pos)
{
    pos_x=pos;
}

void bird::set_y(int pos)
{
    pos_y=pos;
}

void bird::up()
{
    if (pos().y()>=900)
    {
        qDebug()<<"you lose";
        this->~bird();

    }

        setY(pos().y()+40);
        set_y(pos().y());
}

void bird::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Up)
    {
        setY(pos().y()-60);
        set_y(pos().y());
    }
}

int bird::pos_x=0;
int bird::pos_y=0;
