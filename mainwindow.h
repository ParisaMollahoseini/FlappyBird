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
    QVector <barrier *>barriers;


public slots:
    void check();


private:

    Ui::MainWindow *ui;
public slots:
    void endprogram();
};

#endif // MAINWINDOW_H
