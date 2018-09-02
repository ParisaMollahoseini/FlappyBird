#include "bird.h"
#include<windows.h>
#include<QDebug>
#include<QGraphicsEffect>
#include<QPainter>
#include<QStyleOptionGraphicsItem>

bird::bird()
{
    time=new QElapsedTimer;
    time->start();
}

int bird::bestscore=0;

bird::~bird()
{
    qDebug()<<"bird destructor";
}

void bird::start()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(up()));
    timer->start(5);
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

QRectF bird::boundingRect()
{
return QRectF(10,10,50,50);
}

void bird::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setFlag(QGraphicsItem::ItemUsesExtendedStyleOption);

    pen=new QPen(Qt::red);
    pen->setWidth(5);
    pen->setBrush(Qt::SolidPattern);
    pen->setColor(Qt::blue);

    poly=new QPolygon;
    *poly<<QPoint(110,145);
    *poly<<QPoint(120,151);
    *poly<<QPoint(110,152);

    painter->setPen(*pen);
    painter->drawEllipse(80,150,25,25);
    painter->drawEllipse(95,140,15,15);
    painter->setViewTransformEnabled(1);

    pen->setBrush(Qt::yellow);
    painter->setPen(*pen);
    painter->drawPolygon(*poly);
   }

void bird::up()
{
    if (pos().y()>=900)
    {
        emit end();
    }
    if(shomarande==1)
    {
    shomarande=0;
//
    }
        setY(pos().y()+1);
        set_y(pos().y());
}
void bird::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"key event";
    if(event->key()==Qt::Key_Up)
    {
        for(int i=0;i<50;i++)
        {
            setY(pos().y()-1);
            set_y(pos().y());
        }

        shomarande++;
    }
}
int bird::pos_x=0;
int bird::pos_y=0;

