#include<cstdlib> 
#include<iostream>
using namespace std;
class Point{
	private:
		float x,y;
	public:
		Point();
		Point(int,int);
		Point(Point&);
		~Point();
		Point& operator++();//���ز��� 
		Point operator ++(int);
		Point& operator--();
		Point operator--(int);
		friend ostream& operator <<(ostream& Ostr,const Point&);//��Ԫ����<<����� 


		double getX(){return x;};
		double getY(){return y;};
};
Point::Point():x(0),y(0){cout<<"1"<<endl;}
Point::Point(int X,int Y):x(X),y(Y){cout<<"2"<<endl;}
Point::Point(Point& p):x(p.x),y(p.y){cout<<"copy"<<endl;}
Point::~Point(){}
Point& Point::operator++(){
	x+=1;
	y+=1;
	return *this;
}
Point Point::operator++(int){
	Point temp=*this;
	++*this;
	return temp;
}
Point& Point::operator--(){
	x-=1;
	y-=1;
	return *this;
}
Point Point::operator--(int){
	Point temp=*this;
	--*this;
	return temp;
}
ostream& operator <<(ostream& Ostr,const Point& p){
 		return Ostr << "(" << p.x<<","<< p.y <<")";
};
main(){
	Point p(3,4);//���죨3��4�������Լ��Լ� 
	cout<<p<<endl;
	cout<<p++<<endl;
	cout<<++p<<endl; 

}
