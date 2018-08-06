#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QGraphicsPixmapItem>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setGeometry(500,100,900,900);
   setFixedSize(900,900);
    v=new QGraphicsView(this);
    v->setFixedSize(900,900);//view pos
    v->setGeometry(0,0,900,900);
   mybird=new bird;
   mybird->setFlag(QGraphicsItem::ItemIsFocusable);
   mybird->setFocus();
   //scene
   sc=new QGraphicsScene;
    sc->addItem(mybird);
     sc->setSceneRect(v->pos().x(),v->pos().y(),900,900);//scene pos
    QPixmap pix(":/new/prefix1/sky111.jpg");
    sc->addPixmap(pix);
    mybird->setZValue(1);
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

mybird->setRect(v->rect().width()/2-300,v->rect().height()/2,100,100);
mybird->setBrush(Qt::red);
mybird->update();
sc->update();
 v->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}
