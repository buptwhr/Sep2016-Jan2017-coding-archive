/*
2017年9月11日 22:41:14 
2017年9月13日 13:41:41 
2017年9月14日 11:40:54 
*/
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;
class Point{
	public:
		Point();//constryctor
		Point(float iX,float iY);
		Point(Point& anotherPoint);
		~Point();
		float distance(float anotherX,float anotherY);//compute distance
		float getX();
		float getY();
	private:
		float X,Y;
}; 
inline float Point::distance(float anotherX,float anotherY){return sqrt((anotherX-X)*(anotherX-X)+(anotherY-Y)*(anotherY-Y));}
inline float Point::getX() {return X;}
inline float Point::getY() {return Y;}
inline Point::Point(){
			cout<<"point generate 1"<<endl;
			X=0;
			Y=0;
		}
inline 	Point::Point(float iX,float iY){
			X=iX;
			Y=iY;
			cout<<"point generate 2"<<endl;
		}
inline 	Point::Point(Point& anotherPoint){
			X=anotherPoint.getX();
			Y=anotherPoint.getY();
			cout<<"point copy constructor"<<endl;
		}
inline Point::~Point(){
	cout<<"point destroy"<<endl;
}

class Rectangle{
	private:
		Point leftUp,rightDown;
	public:
		Rectangle();//constructor
		Rectangle(int leftUpX,int leftUpY,int rightDownX,int rightDownY);
		Rectangle(Point A,Point B);
		Rectangle(Rectangle& anotherRectangle);
		~Rectangle();//destructor
		float square();//compute area
				
};
inline Rectangle::Rectangle(){
	cout<<"rectangle generate 1"<<endl;
}
inline Rectangle::Rectangle(int leftUpX,int leftUpY,int rightDownX,int rightDownY):leftUp(leftUpX,leftUpY),rightDown(rightDownX,rightDownY){
	cout<<"rectangle generate 2"<<endl;
}
inline Rectangle::Rectangle(Point A,Point B):leftUp(A),rightDown(B){
	cout<<"rectangle generate 3"<<endl;
}
inline Rectangle::Rectangle(Rectangle& anotherRectangle):leftUp(anotherRectangle.leftUp),rightDown(anotherRectangle.rightDown){
	cout<<"rectangle copy constructor"<<endl;
}
inline float Rectangle::square(){
	return (rightDown.getX()-leftUp.getX())*(leftUp.getY()-rightDown.getY());
}
inline Rectangle::~Rectangle(){
	cout<<"rec destroy"<<endl;
}


main(){
	int iX,iY;
	cout<<"please input leftup coordinate:\n";
	cin>>iX>>iY;//get first coordinate
	Point leftUp(iX,iY);
	cout<<"input rightdown coordinate:\n";
	cin>>iX>>iY;//get second coordinate
	Point rightDown(iX,iY);
	cout<<"-------------------------"<<endl;
	Rectangle myRectangle(leftUp,rightDown);
	cout<<"------------------------"<<endl;
	cout<<"your rectangle leftup coordinate is ("<<leftUp.getX()<<","<<leftUp.getY()<<")\n";
	cout<<"your rectangle rightdown coordinate is ("<<rightDown.getX()<<","<<rightDown.getY()<<")\n";
	cout<<"your rectangle's area is "<<myRectangle.square()<<endl;
}



