#include<cstdlib> 
#include<iostream>
using namespace std;

class Shape{
	private:
		int Area;
	public:
		Shape();
		Shape(Shape&);
		~Shape();
		double computeArea();
};
Shape::Shape():Area(0){
	cout<<"Shape constructor"<<endl;
}
Shape::Shape(Shape& s){
	Area=s.Area;
	cout<<"Shape copy constructor"<<endl;
} 
Shape::~Shape(){
	cout<<"Shape destructor"<<endl;
}
double Shape::computeArea(){
	
	cout<<"Shape computeArea"<<endl;
	return Area;
}

class Rectangle:public Shape{
		
	private:
		double length,width;
	public:
		Rectangle();
		Rectangle(Rectangle&);
		Rectangle(double,double);
		~Rectangle();
		double computeArea();
};
Rectangle::Rectangle():length(0),width(0){
	cout<<"Rectangle constructor 1"<<endl;
}
Rectangle::Rectangle(double len,double wid):length(len),width(wid){
	cout<<"Rectangle constructor 2"<<endl;
}
Rectangle::Rectangle(Rectangle& r){
	length=r.length;
	width=r.width;
	cout<<"Rectangle copy constructor"<<endl;
}
Rectangle::~Rectangle(){
	cout<<"Rectangle destructor"<<endl;
}
double Rectangle::computeArea(){
	cout<<"Rectangle computeArea"<<endl;
	return length*width;
}
class Circle:public Shape{
	private:
		double radius;
	public:
		Circle();
		Circle(double);
		Circle(Circle&);
		~Circle();
		double computeArea();
};
Circle::Circle():radius(0){
	cout<<"Circle constructor 1"<<endl;
}
Circle::Circle(double r):radius(r){
	cout<<"Circle constructor 2"<<endl;
}
Circle::Circle(Circle& c){
	radius=c.radius;
	cout<<"Circle copy constructor "<<endl;
}
Circle::~Circle(){
	cout<<"Circle destructor"<<endl;
}
double Circle::computeArea(){
	cout<<"Circle computeArea"<<endl;
	return 3.14*radius*radius;
}

class Square:public Rectangle{
	public:
		Square();
		Square(int);
		Square(Square&);
		~Square();
};
Square::Square(){
	cout<<"Square constructor 1"<<endl;
}
Square::Square(int i):Rectangle(i,i){
	cout<<"Square constructor 2"<<endl;
}
Square::Square(Square& s):Rectangle(s){//派生类对象可以用来初始化基类的引用 
	cout<<"Square copy constructor"<<endl;
}
Square::~Square(){
	cout<<"Square destructor"<<endl;
}

main(){
	Shape s;                        //s对象 
	Rectangle r(3,4);              //构造矩形 
	cout<<r.computeArea()<<endl;
	Circle c(5);                  //构造原型 
	cout<<c.computeArea()<<endl;
	Square sq(5);                //构造正方形 
	cout<<sq.computeArea()<<endl;
	cout<<"------------"<<endl;//验证拷贝构造函数 
	Square sss=sq; 
	cout<<sss.computeArea()<<endl;
	cout<<"-----------\n";
	Shape *s_ptr=&r;             //指针  区别虚函数 
	cout<<s_ptr->computeArea()<<endl;
	s_ptr=&sq;
	 cout<<s_ptr->computeArea()<<endl;
}
