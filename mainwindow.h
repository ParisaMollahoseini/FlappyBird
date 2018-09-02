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
#include"ui_start.h"
#include "ui_mainwindow.h"
namespace Ui {
class MainWindow;
class Start;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Ui::MainWindow *ui;
    Ui::Start *sui;
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
    void first();
    void check();
    void startagain();




public slots:
    void endprogram();
};

#endif // MAINWINDOW_H
