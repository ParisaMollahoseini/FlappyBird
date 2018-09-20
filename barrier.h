#ifndef BARRIER_H
#define BARRIER_H

#include <QMainWindow>
#include <QObject>
#include <QGraphicsRectItem>
#include <QTimer>
#include "bird.h"
#include<QMessageBox>
#include <QPainter>

class barrier : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit barrier();
    ~barrier();
    void start ();
    virtual void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget=0);
    QTimer * timer;

public slots:
    void setBarrier ();
};

#endif // BARRIER_H
