#include <iostream>

using namespace std;

template <typename T>
class PriorityQueue{
	struct n{
//		Distance from start
		int priority;
		
//		This info will be will be used to store pointer to a node
		T* info;
		
		n* next;
	};
	private:
		n *head;

	public:
  	PriorityQueue(){
    	head = NULL;
  	}		
  	
  	void add(T* i){
    	n *t, *q;
    	int p = i->distanceFromStart;

		t = new n;
    	t->info = i;
    	t->priority = p;
    	
    	if (head == NULL || p < head->priority){
//   	 	Inserts a node so that it becomes the first
      		t->next = head;
      		head = t;
    	}
    	else{
    		q = head;
      		while (q->next != NULL && q->next->priority <= p)
        		q = q->next;
      		t->next = q->next;
      		q->next = t;
    	}
	}
	
	T* popFront(){
		n *temp = head;
		if(head == NULL){
			return NULL;
		}
		else if(head->next != NULL){
			head = head->next;	
		} else{
			T* node = head->info;
			delete head;
			head = NULL;
			return node;
		}
//		Returns a node pointer
		return temp->info;
	}
	
	void deleteFront(){
		n *t;
    	if (head == NULL) //if queue is null
      		cout << "Queue Underflow\n";
    	else{
      		t = head;
      		head = head->next;
    		free(t);
    	}
  	}
  	
//  	Kinda useless
//  If a distance has been changed, delete the old node and reinsert it.
  	void updateDist(T *updatedNode){
		n *selectedNode = head;
//		Gets the node before the one to be deleted
		if(head->info == updatedNode){
			deleteFront();
		}
		else{
			while(selectedNode->next->info != updatedNode){
				selectedNode = selectedNode->next;

//				Skip the rest of the function in case the searched node isn't found
				if(selectedNode->next == NULL){
					cout << "Node wasn't found";
					return;
				}
			}
			n *toBeDeleted = selectedNode->next;
			selectedNode->next = toBeDeleted->next;
//			Node is deleted
			free(toBeDeleted);	
		}
		add(updatedNode);
  	}
	
	void show(){
		n *ptr;
    	ptr = head;
    	if(head == NULL)
      		cout << "Queue is empty\n";
    	else{
    		cout << "Queue is :\n";
    		cout << "Priority Item\n";
    		while (ptr != NULL){
        		cout << ptr->priority << " " << ptr->info->data << endl;
        		ptr = ptr->next;
    		}
    	}
	}
};

