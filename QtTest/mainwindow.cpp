#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QPen blackpen(Qt::black);
    blackpen.setWidth(6);




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
QBrush redBrush(Qt::red);
QBrush blueBrush(Qt::blue);
QPen blackpen(Qt::black);
blackpen.setWidth(6);
ellipse = scene->addEllipse(10,10,100,100,blackpen,redBrush);
QGraphicsTextItem *text = scene->addText("Test");
text->setPos(ellipse->x() + 100, ellipse->y() + 100);
ellipse->setFlag(QGraphicsItem::ItemIsMovable);
}
