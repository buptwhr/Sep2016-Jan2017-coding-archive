/*
2017��9��14�� 18:11:25 
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
	Car aCar(9);//��������Ϊ9�ĳ� 
	Boat aBoat(89);//����89�Ĵ� 
	cout<<TotalWeight(aBoat,aCar);
}

double TotalWeight(Boat& b, Car& c){
	 return b.weight+c.weight;
}
