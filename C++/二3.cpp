/*
2017年9月14日 18:11:25 
*/
#include<iostream>
#include<cstdlib>
using namespace std;
class Car;
class Boat{
	friend double TotalWeight(Boat& b, Car& c);
	private:
		double weight;
	public:
		Boat(){
			weight=0;
		}
		Boat(int weight){
			this->weight=weight;
		}
		Boat(Boat& aBoat){
			weight=aBoat.weight;
		}
}; 

class Car{
	friend double TotalWeight(Boat& b, Car& c);
	private:
		double weight;
	public:
		Car(){
			weight=0;
		}
		Car(int weight){
			this->weight=weight;
		}
		Car(Car& aCar){
			weight=aCar.weight;
		}
};

double TotalWeight(Boat& b,Car& c);

main(){
	Car aCar(9);//构造质量为9的车 
	Boat aBoat(89);//质量89的船 
	cout<<TotalWeight(aBoat,aCar);
}

double TotalWeight(Boat& b, Car& c){
	 return b.weight+c.weight;
}
