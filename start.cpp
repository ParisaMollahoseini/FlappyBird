#include "start.h"
#include "ui_start.h"

Start::Start(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
    connect(ui->start,&QPushButton::clicked,this,&Start::StartMainwindow);
}

Start::~Start()
{
    delete ui;
}

void Start::StartMainwindow()
{
    close();
    emit startmainwindow();
}
