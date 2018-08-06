#ifndef BIRD_H
#define BIRD_H
#include<QMainWindow>
#include<QObject>
#include<QGraphicsRectItem>
#include<QPainter>
#include<QKeyEvent>
class bird:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    bird();
void keyPressEvent(QKeyEvent *event);
//void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // BIRD_H
