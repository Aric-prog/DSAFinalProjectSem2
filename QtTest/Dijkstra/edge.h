#include <iostream>
#include <QGraphicsItem>
using namespace std;

template <typename U>
class edge{
	private:
        QGraphicsItem* edgeUI;
		U* destination;
		int weight;
	public:
        edge(int weight, U* dest){
			this->destination = dest;
			this->weight = weight;
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
};
