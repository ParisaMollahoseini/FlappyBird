#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QDebug>
#include <QGraphicsScene>
#include <QVector>
#include "barrier.h"
#include "bird.h"
#include <QTimer>
#include <QMessageBox>
#include"gameover.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Ui::MainWindow *ui;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGraphicsScene *sc;
    QGraphicsView *v;
    bird *mybird;
    QVector <barrier *>barriers;
    gameover *gmover;
    QTimer * timer;
    void firstthings();
    void barrierSize();

public slots:
    void check();
    void startagain();




public slots:
    void endprogram();
};

#endif // MAINWINDOW_H
