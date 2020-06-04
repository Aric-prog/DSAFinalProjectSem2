#include <iostream>
#include <unordered_set>
#include "VertexList.h"
#include "PriorityQueue.h"

using namespace std;

unordered_set<node<string>*> visitedNodes;
PriorityQueue<node<string>> pq;
VertexList <string> a;

//	Function declaration
void show();
void enqueue(node<string>* n);
void dijkstra();
void enqueueEdges(node<string>* n);

int main(){ 
	a.addNode("S",true);
	a.addNode("A");
	a.addNode("B");
	a.addNode("C");
	a.addNode("D");
	a.addNode("E");
	a.addNode("F");
	a.addNode("G");
	a.addNode("H");
	a.addNode("I");
	a.addNode("J");
	a.addNode("K");
	a.addNode("L");
	 
	a.addEdge(7, a.atData("S"), a.atData("A"));
	a.addEdge(2, a.atData("S"), a.atData("B"));
	a.addEdge(3, a.atData("A"), a.atData("B"));
	a.addEdge(3, a.atData("S"), a.atData("C"));
	a.addEdge(4, a.atData("B"), a.atData("D"));
	a.addEdge(4, a.atData("A"), a.atData("D"));
	a.addEdge(5, a.atData("D"), a.atData("F"));
	a.addEdge(3, a.atData("F"), a.atData("H"));
	a.addEdge(1, a.atData("B"), a.atData("H"));
	a.addEdge(2, a.atData("G"), a.atData("H"));
	a.addEdge(2, a.atData("G"), a.atData("E"));
	a.addEdge(5, a.atData("E"), a.atData("K"));
	a.addEdge(4, a.atData("K"), a.atData("J"));
	a.addEdge(4, a.atData("K"), a.atData("I"));
	a.addEdge(6, a.atData("J"), a.atData("I"));
	a.addEdge(4, a.atData("L"), a.atData("I"));
	a.addEdge(4, a.atData("J"), a.atData("L"));
	a.addEdge(2, a.atData("C"), a.atData("L"));

	
	cout<<"Node"<<"\t"<<"Weight -> Destination";
	cout<<endl;
	show();
	
	for(int i = 0; i < a.size(); i++){
		cout << a.at(i)->data << "\t";
		a.displayEdges(a.at(i));
		cout << endl;
	}
	
	enqueue(a.atData("S"));
	dijkstra();
}

void show(){
	for(int i = 0; i < a.size(); i++){
		cout << a.at(i)->data << "\t";
		a.displayEdges(a.at(i));
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

//	Later, this function will accept two node* parameter, one for start and one for end
void dijkstra(){

//	Auto automatically knows the datatype from its initializer
	auto* currNode = pq.popFront();
	while(currNode != NULL){
		auto currEdge = a.getEdges(currNode);
//		Iterates through all the edges from a node
		for(int i = 0; i < currEdge.size(); i++){
			auto* checkedDest = currEdge.at(i).getDestination();
			
			if(currNode->distanceFromStart + currEdge.at(i).getWeight() < checkedDest->distanceFromStart){
				checkedDest->distanceFromStart = currNode->distanceFromStart + currEdge.at(i).getWeight();
				checkedDest->cameFrom = currNode;
			}
				
			enqueue(checkedDest);
		}
		currNode = pq.popFront();
	}
	cout << endl;
	
//	This at data is the destination
//	Replace this with other data to check the path to that node
//	This can be replaced with a function argument.
	currNode = a.atData("E");
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
		currNode = currNode->cameFrom;
	}
}
