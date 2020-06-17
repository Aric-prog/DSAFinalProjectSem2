#include <iostream>
#include <unordered_set>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsEllipseItem>
#include "VertexList.h"
#include "PriorityQueue.h"
#include <windows.h>
#include <QDebug>

using namespace std;

class dijkstra{
public:
	unordered_set<node<string>*> visitedNodes;
    PriorityQueue<node<string>> pq;
    VertexList <string> vl;

	void addNode(string s,QGraphicsItem* uiPointer,int x, int y,bool start = false){
		vl.addNode(s, uiPointer,x,y,start);
    }
	bool addEdge(double weight,node<string>* src, node<string>* dest, QGraphicsItem* item){
		return vl.addEdge(weight,src,dest, item);
    }

    void show(){
    //	Shows the adjacency list
        cout<<"Node"<<"\t"<<"Weight -> Destination";
        cout<<endl;
        for(int i = 0; i < vl.size(); i++){
            cout << vl.at(i)->data << "\t";
            vl.displayEdges(vl.at(i));
            cout << endl;
        }
    }

    //  Enqueue a node into the priority queue
    void enqueue(node<string>* n){
    //	Checks if node has been visited or not
        if(visitedNodes.find(n) == visitedNodes.end()){
            visitedNodes.insert(n);
            pq.add(n);
        }
    }

//    Gets a node from its graphical representation
	node<string>* findGraphicItem(QGraphicsItem* item){
		for(int i = 0; i < vl.size(); i++){
			if(item == vl.at(i)->nodeUI){
				return vl.at(i);
			}
		}
		return NULL;
	}

	void clearVertexList(){
		for(int i = 0; i < vl.size(); i++){
			vl.deleteNode(0);
		}
	}

    //	Later, this function will accept two node* parameter, one for start and one for end
    //	Name is dijkstraRun so that this does not become a constructor
	void dijkstraRun(node<string>* start, node<string>* dest){
		enqueue(start);
    //	Auto automatically knows the datatype from its initializer
		auto* currNode = pq.popFront();
		while(currNode != NULL){
            auto currEdge = vl.getEdges(currNode);
    //		Iterates through all the edges from a node
			for(unsigned int i = 0; i < currEdge.size(); i++){
//				qgraphicsitem_cast<QGraphicsLineItem *>(currEdge.at(i).getEdgeUI())->setPen(*new QPen(Qt::red));

                auto* checkedDest = currEdge.at(i).getDestination();

                if(currNode->distanceFromStart + currEdge.at(i).getWeight() < checkedDest->distanceFromStart){
                    checkedDest->distanceFromStart = currNode->distanceFromStart + currEdge.at(i).getWeight();
                    checkedDest->cameFrom = currNode;
                }

                enqueue(checkedDest);
            }
			currNode = pq.popFront();
        }

    //	This at data is the destination
    //	Replace this with other data to check the path to that node
    //	This can be replaced with a function argument.
		currNode = dest;
		if(!currNode->cameFrom){
			cout << "Path to destination doesn't exist!" << endl;
		}
		else{
			while(currNode != NULL){
				cout << "( Node : ";
				cout << currNode->data;
				cout << " , Distance to node : " << currNode->distanceFromStart;
				cout << " , Came from : ";
				if(currNode->distanceFromStart != 0){
					cout << currNode->cameFrom->data;
				}
				else{
					cout << "-";
				}
				cout << " )"<< endl;
				for(int i = 0; i < currNode->edgeList.size(); i++){
					if(currNode->cameFrom != NULL){
						if(currNode->edgeList.at(i).getDestination()->data == currNode->cameFrom->data){
							qgraphicsitem_cast<QGraphicsLineItem *>(currNode->edgeList.at(i).getEdgeUI())->setPen(*new QPen(Qt::green));
						}
					}
				}
				currNode = currNode->cameFrom;
			}
		}
    }
};

