#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QMouseEvent>
#include <iostream>
QBrush redBrush(Qt::red);
QBrush blueBrush(Qt::blue);
QPen blackpen(Qt::black);
bool adding = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    adding = true;
    blackpen.setWidth(1);
    QGraphicsTextItem *text = scene->addText("Test");
}

void MainWindow::mousePressEvent(QMouseEvent *ev){
    ui->label->setText("X : " + QString::number(ev->x()) + ", Y : " + QString::number(ev->y()));
    if(adding){

       scene->addEllipse(ev->x() - 25,ev->y() - 50,50,50,blackpen,redBrush);
       adding = false;

    }
}
