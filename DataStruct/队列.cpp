#include<cstdio>
#include<iostream>

using namespace std;
typedef struct LNode{
	int num;
	LNode* next;
}LNode; 
class Queue{
	private:
		LNode* tail;
	public:
		Queue();
		~Queue();
		int state();
		int EnQueue(int);
		int DeQueue();
};
Queue::Queue(){//初始化，准备头节点 
	tail=new LNode;
	tail->next=tail;
}
Queue::~Queue(){
	LNode* p;
	while(tail!=tail->next){
		p=tail->next->next;
		delete tail->next;
		tail=p;
	}
	delete tail;
}
int Queue::state(){//返回长度  空则返回0 
	if(tail==tail->next)
	return 0;
	int num=0;
	LNode* p=tail->next;
	while(p!=tail){
		num++;
		p=p->next;
	}
	return num;
}
int Queue::EnQueue(int n){//入队操作 
	LNode* p=new LNode;
	if(!p) return 0;
	LNode* head=tail->next;//保存头 
	p->num=n;
	tail->next=p;
	tail=p;
	tail->next=head;
	cout<<tail->num<<"进队 元素数量: "<<this->state()<<endl; 
	return 1;
} 
int Queue::DeQueue(){//出队操作 
	if(tail==tail->next){
		cout<<"已空，无法删除"<<endl;
		return 0; 
	}
	int n;
	LNode* p;
	p=tail->next->next;
	n=p->num;
	if(p==tail){
		tail=tail->next;
		tail->next=tail;
		delete p;
	}
	else{
		tail->next->next=p->next;
		delete p;
	}
	cout<<n<<"被删除"<<"队列长度"<<this->state() <<endl; 
	
}

main(){
	Queue q;
	q.EnQueue(5);
	q.EnQueue(7);
	q.EnQueue(3);
	q.EnQueue(8);
	q.EnQueue(55);
	q.DeQueue();
	q.DeQueue();
	q.DeQueue();
	q.DeQueue();
	q.DeQueue(); 
	q.DeQueue();
}
