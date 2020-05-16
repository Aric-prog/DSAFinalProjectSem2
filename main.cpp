#include <iostream>
#include <vector>
#include "VertexList.h"
#include "PriorityQueue.h"

using namespace std;

vector<node<int>*> visitedNodes;
PriorityQueue<node<int>> asdf;
VertexList <int>a;

int main(){ 
	
	a.addNode(0);
	a.addNode(1);
	a.addNode(2);
	
	a.addEdge(3, a.at(0), a.at(1));
	a.displayEdges(a.at(0));
//	a.addEdge(5, a.at(0), a.at(2));
//	a.addEdge(3, a.at(1), a.at(2));
//	asdf.add(a.at(0));
//	asdf.add(a.at(1));
//	
//	asdf.updateDist(a.at(0));
//	asdf.show();
	
//	cout<<"Node"<<"\t"<<"Weight -> Destination";
//	cout<<endl;
	
//	for(int i = 0; i < a.size(); i++){
//		cout << a.at(i)->index << "\t";
//		a.displayEdges(a.at(i));
//		cout << endl;
//	}
}

void enqueue(node<int>* n){
	bool visited = false;
	for(int i = 0; i < visitedNodes.size(); i++){
		if(n == visitedNodes.at(i)){
			visited = true;
		}
	}
	if(!visited){
		visitedNodes.push_back(n);
		asdf.add(n);	
	}
}


