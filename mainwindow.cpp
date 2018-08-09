#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QGraphicsPixmapItem>
#include<QMessageBox>
#include<QPushButton>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    firstthings();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::firstthings()
{
    gmover=new gameover;

    barriers.resize(2);

    ui->gv->setFixedSize(900,900);//view pos
    ui->gv->setGeometry(0,0,900,900);

   mybird = new bird();
   mybird->setFlag(QGraphicsItem::ItemIsFocusable);
   mybird->QGraphicsEllipseItem::setFocus();
//
    ui->gv->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
//
   barriers[0] = new barrier();
   barriers[1] = new barrier();


   //scene

   sc=new QGraphicsScene;
    sc->addItem(mybird);
    sc->addItem(barriers[0]);
    sc->addItem(barriers[1]);

    sc->setSceneRect(0,0,900,900);//scene pos
    QPixmap pix(":/game-background.jpg");

    sc->addPixmap(pix);
    mybird->setZValue(2);
    barriers[0]->setZValue(2);
    barriers[1]->setZValue(2);
    //scene
    ui->gv->setScene(sc);
    qDebug()<<"view "<<mybird->QGraphicsEllipseItem::brush().color();
    ui->gv->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gv->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    mybird->setRect(ui->gv->pos().x()+50,ui->gv->pos().y(),25,25);
    mybird->setX(50);mybird->setY(0);
    qDebug()<<"birddddd  x:"<<mybird->QGraphicsEllipseItem::x();
    mybird->QGraphicsEllipseItem::setBrush(Qt::blue);
    mybird->update();

    ui->gv->setRenderHint(QPainter::Antialiasing);

    barriers[0]->setRect(800,500, 60, 400);
    barriers[0]->setBrush(Qt::blue);
    barriers[0]->update();

    barriers[1]->setRect(800,0, 60, 400);
    barriers[1]->setBrush(Qt::green);
    barriers[1]->update();

    sc->update();
    ui->gv->update();
    mybird->start();
    barriers[0]->start();
    barriers[1]->start();

      //connects
    connect(mybird,SIGNAL(end()),this,SLOT(endprogram()));
    connect(gmover,SIGNAL(emitsignalofstartingmainwindow()),this,SLOT(startagain()));
    //connects

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(check()));
    timer->start(10);
}

void MainWindow::check()
{
    if (barriers[0]->collidesWithItem(mybird))
        this->endprogram();

    if (barriers[1]->collidesWithItem(mybird))
        this->endprogram();
}

void MainWindow::startagain()
{
    qDebug()<<"omad...";
    ui=new Ui::MainWindow;
    ui->setupUi(this);
    firstthings();
    show();
}

void MainWindow::endprogram()
{
    close();

    timer->stop();
    mybird->timer->stop();
    barriers[0]->timer->stop();
    barriers[1]->timer->stop();

    gmover->start();

}
