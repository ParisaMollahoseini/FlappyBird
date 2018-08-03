#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsRectItem>
#include<QGraphicsView>
#include<QDebug>
#include<QGraphicsScene>
//bird
#include"bird.h"
//bird
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
QGraphicsScene *sc;
QGraphicsView *v;
 bird *mybird;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
