#include <iostream>
#include <vector>
#include "edge.h"

using namespace std;

template <typename T>
struct node{
//	Number on that node
	T data;
	
//	Index of the node inside the list
	int index;
	
//	Distance of the path from the starting node
	int distanceFromStart;
	
//	Edge coming out of a node
	vector<edge<node>> edgeList;
	node* cameFrom;
	node* next;
};

template <typename T>
class VertexList{
	private:
		node<T>* head;
		node<T>* tail;
		
	public:
//	Iterator for the class
	class iterator{
		private:
			node<T>* current;
		public:
			iterator(){current = NULL;}
			iterator(node<T>* tmp){this->current = tmp;}
			void operator ++ (int){
				this->current = this->current->next;
			}
			
			bool operator == (iterator tmp){
				return (this->current == tmp.current);
			}
			bool operator != (iterator tmp){
				return (this->current != tmp.current);
			}
			T operator * (){
				return this->current->data;
			}
	};
	
	iterator begin(){
		return iterator(this->head);
	}
	iterator end(){
		return NULL;
	}
	
//	Constructor, creates an empty linked list
	VertexList(){
		head = NULL;
		tail = NULL;
	}
	
//	Adds a node accepting an input for the data
	void addNode(T input, bool start = false){
		node<T>* tmp = new node<T>;
		
		tmp->data = input;
		tmp->next = NULL;
		tmp->cameFrom = NULL;
		tmp->distanceFromStart = start ? 0 : 10000;
		
		if(head == NULL){
			head = tmp;
			head->index = 0;
			tail = tmp;	
		}
		else{
			tmp->index = tail->index + 1;
			tail->next = tmp;
			tail = tmp;
		}
	}
	
//	Adds an edge to a node, giving a pointer destination to the destination node
//	Doesn't matter if you give source or destination first, it's a two way line
	bool addEdge(int weight, node<T>* src, node<T>* dest){
//		Checks if linked node is the same
		if(src == dest){
			cout << "Cannot link to itself" << endl;
			return false;
		}
//		Checks if node has already been linked
		for(edge<node<T>> i : src->edgeList){
			if(dest == i.getDestination()){
				cout << "Already have edge to that node" << endl;
				return false;
			}
		}
		
		src->edgeList.push_back(edge<node<T>>(weight, dest));
		dest->edgeList.push_back(edge<node<T>>(weight, src));
		return true;
	}

	node<T>* getTail(){
		return tail;
	}
	node<T>* getHead(){
		return head;
	}
	node<T>* at(int index){
		node<T>* tmp = head;
		
		if(index > tail->index){
			throw "Index out of bounds";
		}
		
		while(index != tmp->index){
			tmp = tmp->next;
		}
		return tmp;
	}
	node<T>* atData(T data){
		node<T>* tmp = head;
		
		while(tmp != NULL){
			if(data == tmp->data){
				return tmp;
			}
			tmp = tmp -> next;
		}
		cout << "Can't find the node" << endl;
		return NULL;
	}
	
//	accepts an index as the location of the node
//	Inserts a node based on the index
	void insertNode(int inputIndex, T inputData){
		if(inputIndex > size()){
			cout << "Index exceeds array size" << endl; 
		}
		else if(inputIndex == 0){
			
		}
		else if(inputIndex == size()){
			addNode(inputData);	
		} 
		else{
			node<T>* tmp = new node<T>;
			node<T>* nextNode;
			
			tmp->data = inputData;
			tmp->index = inputIndex;
			node<T>* previous = this->head;
			
			while(previous->index != inputIndex - 1){
				
				previous = previous->next;
			}
			nextNode = previous->next;
			
			tmp->next = nextNode;
			previous->next = tmp;
			
			updateNodeIndex(tmp);
		}
	}
	
//	Gives the size of the linked list
	int size(){
		if(head == NULL){
			return 0;
		}
		return tail->index + 1;
	}
	
//	Displays all node in CLI
	void displayNode(){
		node<T>* tmp;
		tmp = head;
		while(tmp != NULL){
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
	}
	
//	Shows the edges of a given node in CLI
	void displayEdges(node<T>* src){
		for(int i = 0; i < src->edgeList.size(); i++){
			cout << src->edgeList.at(i).getWeight() << " -> " << src->edgeList.at(i).getDestination()->data << "\t";
		}
	}
	vector<edge<node<T>>> getEdges(node<T>* src){
		return src->edgeList;
	}
	
	void viewNode(node<T>* n){
		cout << "Data" << n->data << " , Distance : " << n->distanceFromStart;
	}

//	Deletes a node at a given index
	void deleteNode(int inputIndex){
		if(inputIndex > size() - 1){
			cout << "Index exceeds list size" << endl;
		}
		
//		Checks if the inputIndex is at head
		else if(inputIndex == 0){
			node<T>* tmp = head;
			head = head->next;
			tmp = NULL;
		}
//		Checks if the inputIndex is equals to tail
		else if(inputIndex == tail->index){
			node<T>* tailTmp = head;
			
			while(tailTmp->index != tail->index - 1){
				tailTmp = tailTmp->next;
			}
			tail = tailTmp;
			tail->next = NULL;
		}
		
		else{
//			Decreases the inputIndex by 1
			--inputIndex;
			node<T>* tmp;
			node<T>* link;
			tmp = head;
		
//			get the node before the node you want to delete
			while(inputIndex != tmp->index){
				tmp = tmp->next;
			}
			link = tmp->next;
			
			
			if(link->next != NULL){
				tmp->next = NULL;
				tmp->next = link->next;
				updateNodeIndex(tmp);
			}
			else{
				tmp->next = NULL;
			}
		}
	}
	
//	Updates the node index at all nodes
	void updateNodeIndex(node<T>* tmp){
		while(tmp->next != NULL){
			tmp->next->index = tmp->index + 1;
			tmp = tmp->next;
		}
	}
};
