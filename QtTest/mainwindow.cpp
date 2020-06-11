#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Dijkstra/dijkstra.h"
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>

QBrush redBrush(Qt::red);
QBrush blueBrush(Qt::blue);
QPen blackPen(Qt::black);
QPen whitePen(Qt::gray);
dijkstra d;

bool adding = false;
bool connecting = false;
int i = 2;
char idGenerator = 'a';

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    blackPen.setWidth(1);
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

void MainWindow::on_pushButton_clicked(){
    adding = true;
}
void MainWindow::on_pushButton_2_clicked(){
    connecting = true;
    adding = false;
}

void MainWindow::mousePressEvent(QMouseEvent *ev){
    ui->label->setText("X : " + QString::number(ev->x()) + ", Y : " + QString::number(ev->y()));

    if(adding){
		string s(1,idGenerator);
		d.addNode(s,scene->addEllipse(ev->x() - 25,ev->y() - 50,50,50,blackPen,redBrush));
		adding = false;
    }
    else if(connecting){
		auto* temp = qgraphicsitem_cast<QGraphicsEllipseItem *>(scene->itemAt(QPoint(ev->x(),ev->y() - 25), QTransform()));
		qDebug() << connecting;
		if(temp){
			temp->setBrush(blueBrush);
			temp->setPen(whitePen);
			--i;
//			x,y lingkaran1
//          x,y lingkaran2
//          Compare the two objects, if they're the same, don't establish link
//          Get pointer for the both of them, use that to identify the nodes, draw and establish edge.
        }

        // I'm not proud of this.
        if(i == 0){
//			d.addEdge(weight,src,dest,scene->addLine(args));
			connecting = false;
            i = 2;
        }
    }
}



