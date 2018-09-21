#include "mainwindow.h"
#include<QGraphicsPixmapItem>
#include<QMessageBox>
#include<QPushButton>
#include<QTextStream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(nullptr),
  sui(nullptr)
{
        scorefile=new QFile("score.txt");
        sui=new Ui::Start;
        sui->setupUi(this);
        sui->back->hide();
        sui->scorelist->hide();
        sui->scorelabel->hide();

        setGeometry(500,100,900,900);
        connect(sui->start,&QPushButton::clicked,this,&MainWindow::first);



}

MainWindow::~MainWindow()
{
    delete gmover;
    delete mybird;
    delete sc;
    delete timer;
    delete ui;
}

void MainWindow::firstthings()
{


    qDebug()<<"first things come....\n";


    gmover=new gameover;

    barriers.resize(8);

    ui->gv->setFixedSize(900,900);//view pos
    ui->gv->setGeometry(0,0,900,900);

   mybird = new bird;
   mybird->time->restart();
   mybird->setFlag(QGraphicsItem::ItemIsFocusable);
   mybird->QGraphicsEllipseItem::setFocus();

//
    ui->gv->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);//shape of bird
//

    for (int i=0; i<barriers.size(); i++)
    {
        barriers[i] = new barrier();
    }

   //scene

    sc=new QGraphicsScene;
    sc->addItem(mybird);

    for (int i=0; i<barriers.size(); i++)
    {
        sc->addItem(barriers[i]);
    }

    sc->setSceneRect(0,0,900,900);//scene pos
    QPixmap pix(":/game-background.jpg");

    sc->addPixmap(pix);
    mybird->setZValue(2);

    for (int i=0; i<barriers.size(); i++)
    {
        barriers[i]->setZValue(2);
    }
    //scene

    ui->gv->setScene(sc);

    ui->gv->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gv->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    mybird->setRect(80, 140, 40, 35);

    barrierSize();

    mybird->QGraphicsEllipseItem::setBrush(Qt::blue);
    mybird->update();

    ui->gv->setRenderHint(QPainter::Antialiasing);//paint

    sc->update();
    ui->gv->update();
    mybird->start();

    for (int i=0; i<barriers.size(); i++)
    {
        barriers[i]->update();
        barriers[i]->start();
    }

    //connects
    connect(mybird,SIGNAL(end()),this,SLOT(endprogram()));
    connect(gmover,SIGNAL(emitsignalofstartingmainwindow()),this,SLOT(startagain()));

//    connect(gmover,SIGNAL(startpage()),this,SLOT(on_back_clicked()));

    //connects

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(check()));
    timer->start(10);
}

void MainWindow::barrierSize()
{
    barriers[0]->setRect(290, 0, 80, 250);
    barriers[1]->setRect(290, 450, 80, 450);
    barriers[2]->setRect(470, 0, 80, 350);
    barriers[3]->setRect(470, 550, 80, 350);
    barriers[4]->setRect(650, 0, 80, 500);
    barriers[5]->setRect(650, 700, 80, 200);
    barriers[6]->setRect(830, 0, 80, 400);
    barriers[7]->setRect(830, 600, 80, 300);
}


void MainWindow::first()
{

    delete sui;
    sui=nullptr;
    close();
    ui=new Ui::MainWindow;
    ui->setupUi(this);

    firstthings();

    show();
}

void MainWindow::check()
{
    for (int i=0; i<barriers.size(); i++)
    {
        if (barriers[i]->collidesWithItem(mybird))
        {
            qDebug()<<i;
            this->endprogram();
        }
    }

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

    ////
    scorefile->open(QIODevice::ReadOnly);
    QTextStream in(scorefile);
    in.seek(0);
    while(!in.atEnd())
    {
        qDebug()<<"while";
QString x=in.readLine();
if(x.toInt()>mybird->bestscore)
{
     qDebug()<<"if";
mybird->bestscore=x.toInt();
}
    }
    scorefile->close();
    ////


    mybird->score=mybird->time->elapsed()/1000;//record time
    qDebug()<<"time is"<<mybird->time->elapsed();
    if(mybird->score>mybird->bestscore)
        mybird->bestscore=mybird->score;


//score in file
    scorefile->open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream out(scorefile);
    out<<mybird->score<<endl;
    scorefile->close();
//score in file

    close();

    gmover->start(mybird->score,mybird->bestscore);

    timer->stop();
    mybird->timer->stop();

    for (int i=0; i<barriers.size(); i++)
    {
        barriers[i]->timer->stop();
    }

//    connect(gmover,SIGNAL(startpage()),this,SLOT(on_back_clicked()));
}

void MainWindow::on_newgame_clicked()//click on new game
{
    qDebug()<<"first come newgame....\n";
    close();
    delete sui;
    sui=nullptr;

    QFile::remove("score.txt");
    scorefile=new QFile("score.txt);
    scorefile->open(QIODevice::WriteOnly);
    scorefile->close();

    ui=new Ui::MainWindow;
    ui->setupUi(this);

    firstthings();

    show();
}
void MainWindow::on_yourscore_clicked()
{
    sui->newgame->hide();
    sui->start->hide();
    sui->yourscore->hide();
    sui->back->show();
    sui->scorelist->show();
    sui->scorelist->adjustSize();

    
    scorefile->open(QIODevice::ReadOnly);
    QTextStream in(scorefile);
    int no=0;
    while(!in.atEnd())
    {
        no++;
sui->scorelist->addItem(QString::number(no)+" : "+in.readLine());

    }

    sui->scorelabel->show();
}
void MainWindow::on_back_clicked()
{

    sui->back->hide();
    sui->scorelist->hide();
    sui->newgame->show();
    sui->start->show();
    sui->yourscore->show();
    sui->scorelabel->hide();

}














