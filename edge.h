#include <iostream>

using namespace std;

template <typename U>
class edge{
	private:
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
			this.destination = dest;
		}
		void setWeight(int weight){
			this.weight = weight;
		}
};
