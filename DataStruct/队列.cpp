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
Queue::Queue(){//��ʼ����׼��ͷ�ڵ� 
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
int Queue::state(){//���س���  ���򷵻�0 
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
int Queue::EnQueue(int n){//��Ӳ��� 
	LNode* p=new LNode;
	if(!p) return 0;
	LNode* head=tail->next;//����ͷ 
	p->num=n;
	tail->next=p;
	tail=p;
	tail->next=head;
	cout<<tail->num<<"���� Ԫ������: "<<this->state()<<endl; 
	return 1;
} 
int Queue::DeQueue(){//���Ӳ��� 
	if(tail==tail->next){
		cout<<"�ѿգ��޷�ɾ��"<<endl;
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
	cout<<n<<"��ɾ��"<<"���г���"<<this->state() <<endl; 
	
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
