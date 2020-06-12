#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Dijkstra/dijkstra.h"
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
double pythagoras(double x1, double y1, double x2, double y2);

QBrush redBrush(Qt::red);
QBrush blueBrush(Qt::blue);
QPen blackPen(Qt::black);
dijkstra d;

bool adding = false;

bool settingDest = false;
bool settingStart = false;
bool hasSetStart = false;
bool hasSetDest = false;

QGraphicsItem* startNodeUI = NULL;
QGraphicsItem* destNodeUI = NULL;

int i = 2;
char idGenerator = 'a';

QGraphicsItem* selected[2];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
	blackPen.setWidth(2);
    ui->setupUi(this);
    scene = new QGraphicsScene(this);

	ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{
	adding = true;
}
void MainWindow::on_setStart_pressed()
{
	if(!hasSetStart){
		settingStart = true;
	}
	else if(!hasSetDest){
		settingDest = true;
	} else{
		d.dijkstraRun(d.findGraphicItem(startNodeUI), d.findGraphicItem(destNodeUI));
	}
}

void MainWindow::mousePressEvent(QMouseEvent *ev){
	QGraphicsItem* clickedItem = scene->itemAt(QPoint(ev->x(),ev->y() - 25), QTransform());
	auto* castedGraphicItem = qgraphicsitem_cast<QGraphicsEllipseItem *>(clickedItem);
	if(adding){
		string s(1,idGenerator);
		idGenerator += 1;
		QPointF posWithOffset(ev->x() - 7,ev->y());

		auto* tempEllipse = scene->addEllipse(ev->x() - 25, ev->y() - 50,50,50,blackPen,redBrush);
		scene->addText(QString::fromStdString(s))->setPos(posWithOffset);

		tempEllipse->setZValue(1);
		d.addNode(s,tempEllipse,ev->x(),ev->y() - 25);
		adding = false;
	}

//	Checks if the cast was succesful, ensuring that the clicked item is an ellipse
	if(castedGraphicItem){
		if(settingStart){
			d.findGraphicItem(castedGraphicItem)->distanceFromStart = 0;
			startNodeUI = clickedItem;
			hasSetStart = true;
			settingStart = false;
			castedGraphicItem->setBrush(*new QBrush(Qt::green));
			ui->setStart->setText("Set Destination Node");
		}
		else if(settingDest){
			destNodeUI = clickedItem;
			castedGraphicItem->setBrush(*new QBrush(Qt::yellow));
			hasSetDest = true;
			settingDest = false;
		}
		else{
//			Makes sure that the start node's color doesn't get changed
			if(!(clickedItem == startNodeUI || clickedItem == destNodeUI)){
				castedGraphicItem->setBrush(blueBrush);
			}
			--i;
			selected[i] = castedGraphicItem;

//			I'm not proud of this.
			if(i == 0){
//				src and dest will be the node pointer, to be used for the edge argument
				auto* src = d.findGraphicItem(selected[0]);
				auto* dest = d.findGraphicItem(selected[1]);
				double weight = pythagoras(src->nodeX,src->nodeY,dest->nodeX,dest->nodeY);

				QGraphicsItem* tempLine = scene->addLine(src->nodeX,src->nodeY,dest->nodeX,dest->nodeY);

				if(!d.addEdge(weight, src, dest, tempLine)){
					delete tempLine;
				}

				i = 2;
			}
		}
	}
}

void revertColor(QGraphicsItem* selectedNode){
	qgraphicsitem_cast<QGraphicsEllipseItem *>(selectedNode)->setBrush(redBrush);
	qgraphicsitem_cast<QGraphicsEllipseItem *>(selectedNode)->setPen(blackPen);
}
double pythagoras(double x1, double y1, double x2, double y2){
//	pythagoras without the square root, to save on computing power, while basically doing the same thing
	return  sqrt(pow((x2 - x1) , 2.0) + pow((y2-y1) , 2.0));
}
