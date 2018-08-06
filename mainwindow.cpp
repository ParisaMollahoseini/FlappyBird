#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QGraphicsPixmapItem>

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

    sc->setSceneRect(v->pos().x(),v->pos().y(),900,900);//scene pos
    QPixmap pix(":/new/prefix1/sky111.jpg");
    sc->addPixmap(pix);
    mybird->setZValue(1);
    barriers[0]->setZValue(1);
    barriers[1]->setZValue(1);
    //scene
    ///from site
//    QGraphicsPixmapItem item( QPixmap::fromImage(image));
//       QGraphicsScene* scene = new QGraphicsScene;
//       scene->addItem(&item);
    ///from site
    v->setScene(sc);
    qDebug()<<"view "<<mybird->brush().color();
    v->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    v->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    mybird->setRect(70,70,25,25);
    mybird->setBrush(Qt::red);
    mybird->update();

    barriers[0]->setRect(500, 500, 60, 400);
    barriers[0]->setBrush(Qt::green);
    barriers[0]->update();

    barriers[1]->setRect(500, 0, 60, 400);
    barriers[1]->setBrush(Qt::green);
    barriers[1]->update();


    sc->update();
    v->update();
    mybird->start();
    barriers[0]->start();
    barriers[1]->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
