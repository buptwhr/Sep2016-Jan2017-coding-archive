#include<cstdio>
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct stackNode{//栈节点 
	int address;
	int parameter;
	stackNode* next;
}stackNode;
class stack{
	private:
		stackNode* top;
	public:
		stack();
		~stack();
		int isEmpty();
		stackNode pop();
		stackNode getTop();
		int push(int,int);
		friend fib3(int);
};

stack::stack(){
	top=NULL;
}
stack::~stack(){
	stackNode* p;
	while(top){
		p=top;
		top=top->next;
		delete p;
	}
}
int stack::isEmpty(){
	if(top)
	return 0;
	else
	return 1;
}
int stack::push(int address,int parameter){
	stackNode* p=new stackNode;
	if(!p)return 0;
	p->address=address;

	p->parameter=parameter;
	p->next=top;
	top=p;
	return 1;
}
stackNode stack::getTop(){
	if(top)
	return *top;
}
stackNode stack::pop(){
	if(top){
		stackNode temp;
		stackNode* p;
		p=top;
		temp=*top;
		top=top->next;
		delete p;
		return temp;
	}

	
}
int fib1(int);
int fib2(int);
int fib3(int);
main(){
	int n;
	cout<<"输入n 得出第n项斐波那契";
	cin>>n; 
	cout<<fib1(n)<<endl<<fib2(n)<<endl<<fib3(n)<<endl;
	
} 
int fib1(int n){//递归 
	if(n==0||n==1)
	return n;
	else
	return fib1(n-1)+fib1(n-2);
}

int fib2(int n){ 
	int a=0,b=1,c;
	if(n==0||n==1)
	return n;
	n=n-1;
	while(n--){
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}

int fib3(int n){
	stack s;
	stackNode a;
	int sum=0;
	int address;
	l0:
	if(n==0||n==1){
		sum+=n;
	}
	else{
		l1:
			s.push(2,n);
			n=n-1;
			goto l0;
		l2:
			s.push(3,n);
			n=n-2;
			goto l0;
		l3:
			; 
			
	}
	if(!s.isEmpty()){
		a=s.pop();
		n=a.parameter;
		switch(a.address){
			case 0:goto l0;break;
			case 1:goto l1;break;
			case 2:goto l2;break;
			case 3:goto l3;break;
		}
	}
	return sum;
	
}
