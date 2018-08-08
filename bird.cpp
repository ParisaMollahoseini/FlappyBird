#include "bird.h"
#include<QDebug>
#include<QGraphicsEffect>
#include<QPainter>
#include<QStyleOptionGraphicsItem>
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
    painter->setPen(*pen);
    painter->drawEllipse(100,100,25,25);
    painter->drawEllipse(115,90,15,15);
    painter->setViewTransformEnabled(1);
   }

void bird::up()
{
    if (pos().y()>=900)
    {
        emit end();
        qDebug()<<"you lose";
        QMessageBox msg;
        msg.setText("lose");
        msg.exec();

    }

        setY(pos().y()+1);
        set_y(pos().y());
        qDebug()<<"bird x : "<<pos().x();
        qDebug()<<"bird y : "<<pos().y();

}
void bird::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Up)
    {
        setY(pos().y()-100);
        set_y(pos().y());
    }
}
int bird::pos_x=0;
int bird::pos_y=0;

