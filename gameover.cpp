#include "gameover.h"
#include "ui_gameover.h"
#include"mainwindow.h"
gameover::gameover(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gameover)
{
}

gameover::~gameover()
{
    delete ui;
}

void gameover::start(int score,int bestscore)
{
    ui=new Ui::gameover;
    ui->setupUi(this);
    ui->lbest->setText(QString::number(bestscore));
    ui->lscore->setText(QString::number(score));
    show();
}
void gameover::on_again_clicked()
{
    close();
    emit emitsignalofstartingmainwindow();
}

void gameover::on_again_2_clicked()//?????????????????????
{
    close();
    delete ui;

    emit startpage();
}
