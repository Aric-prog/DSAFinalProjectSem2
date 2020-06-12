#include <iostream>
#include <QGraphicsItem>
using namespace std;

template <typename U>
class edge{
	private:
        QGraphicsItem* edgeUI;
		U* destination;
		double weight;
	public:
		edge(double weight, U* dest,QGraphicsItem* edgeUI){
			this->destination = dest;
			this->weight = weight;
			this->edgeUI = edgeUI;
		}
		U* getDestination(){
			return destination;
		}
		
		int getWeight(){
			return weight;
		}
		
		void setDestination(U* dest){
            destination = dest;
		}
        void setWeight(int w){
            weight = w;
		}

		QGraphicsItem* getEdgeUI(){
			return edgeUI;
		}
};
