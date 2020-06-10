#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <iostream>

QBrush redBrush(Qt::red);
QBrush blueBrush(Qt::blue);
QPen blackpen(Qt::black);

QBrush brush = Qt::SolidPattern;
QColor clr = Qt::blue;
bool adding = false;
bool connecting = false;
int i = 2;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    blackpen.setWidth(1);
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//    id;
//    Pointer* node backend;
//    Pointer ke ellipsis;
//    Arrylist Pointer edges;

void MainWindow::on_pushButton_clicked()
{
    adding = true;
    connecting = false;
}
void MainWindow::on_pushButton_2_clicked()
{
    connecting = true;
    adding = false;
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    ui->label->setText("X : " + QString::number(ev->x()) + ", Y : " + QString::number(ev->y()));
    if(adding){

       qDebug() << scene->addEllipse(ev->x() - 25,ev->y() - 50,50,50,blackpen,redBrush);

       adding = false;
    }
    else if(connecting){
        auto* temp = qgraphicsitem_cast<QGraphicsEllipseItem *>(scene->itemAt(ev->pos(), QTransform()));
        if(temp){
           temp->setBrush(brush);
           --i;
//           x,y lingkaran1
//           x,y lingkaran2
        }

        // I'm not proud of this.
        if(i == 0){
            connecting = false;
            i = 2;
        }
    }
}



