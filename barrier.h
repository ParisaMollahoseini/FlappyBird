#ifndef BARRIER_H
#define BARRIER_H

#include <QMainWindow>
#include <QObject>
#include <QGraphicsRectItem>
#include <QTimer>
#include "bird.h"
#include<QMessageBox>

class barrier : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit barrier();
    ~barrier();
    void start ();
    QTimer * timer;
public slots:
    void setBarrier ();
};

#endif // BARRIER_H
