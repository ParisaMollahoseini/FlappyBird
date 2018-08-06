#include "bird.h"
#include<QDebug>
#include<QGraphicsEffect>
#include<QPainter>
bird::bird()
{


}

void bird::keyPressEvent(QKeyEvent *event)
{
if(event->key()==Qt::Key_Up)
{
setY(pos().y()-40);
}
else if(event->key()==Qt::Key_Down)
{
setY(pos().y()+40);
}
}

//void bird::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    painter->drawEllipse(pos().x(),pos().y(),10,10);
//    painter->setBrush(Qt::blue);
//}
