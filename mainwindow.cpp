#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QGraphicsPixmapItem>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    barriers.resize(2);

   setGeometry(500,100,900,900);
   setFixedSize(900,900);
    v=new QGraphicsView(this);
    v->setFixedSize(900,900);//view pos
    v->setGeometry(0,0,900,900);
   mybird = new bird();
   mybird->setFlag(QGraphicsItem::ItemIsFocusable);
   mybird->setFocus();

   barriers[0] = new barrier();
   barriers[1] = new barrier();


   //scene

   sc=new QGraphicsScene;
    sc->addItem(mybird);
    sc->addItem(barriers[0]);
    sc->addItem(barriers[1]);

    sc->setSceneRect(0,0,900,900);//scene pos

    QPixmap pix(":/new/prefix1/sky111.jpg");
    sc->addPixmap(pix);
    mybird->setZValue(2);
    barriers[0]->setZValue(2);
    barriers[1]->setZValue(2);
    //scene
    v->setScene(sc);
    qDebug()<<"view "<<mybird->brush().color();
    v->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    v->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    mybird->setRect(v->pos().x()+50,v->pos().y(),25,25);
    mybird->setX(50);mybird->setY(0);
    qDebug()<<"birddddd  x:"<<mybird->x();
    mybird->setBrush(Qt::red);
    mybird->update();

    barriers[0]->setRect(800,500, 60, 400);
    barriers[0]->setBrush(Qt::blue);
    barriers[0]->update();

    barriers[1]->setRect(800,0, 60, 400);
    barriers[1]->setBrush(Qt::green);
    barriers[1]->update();

    sc->update();
    v->update();
    mybird->start();
    barriers[0]->start(mybird);
    barriers[1]->start(mybird);
    connect(mybird,SIGNAL(end()),this,SLOT(endprogram()));

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(check()));
    timer->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::check()
{
    if (barriers[0]->collidesWithItem(mybird))
        qDebug()<<"ohhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh";

    if (barriers[1]->collidesWithItem(mybird))
        qDebug()<<"ohohohohohohohohohohohohohohohohohohohohohooooooooooooooooooooooooooooo";
}

void MainWindow::endprogram()
{

    delete v;
    delete sc;
    delete barriers[0];
     delete barriers[1];
    delete mybird;
     close();
}
