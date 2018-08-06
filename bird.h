#ifndef BIRD_H
#define BIRD_H
#include<QMainWindow>
#include<QObject>
#include<QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include<QKeyEvent>
#include<QTimer>
#include<QDebug>

class bird:public QObject,public QGraphicsEllipseItem
{
    Q_OBJECT

    static int pos_x;
    static int pos_y;

public:
    bird();
    ~bird();
    void start();
    static int get_x();
    static int get_y();
    static void set_x(int pos);
    static void set_y(int pos);


public slots:
    void up ();

void keyPressEvent(QKeyEvent *event);
};

#endif // BIRD_H
