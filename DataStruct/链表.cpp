#include<iostream>
#include<cstdlib>
#include<string.h>
#include<fstream>
using namespace std;
#define FALSE 0
#define OK 1
#define FLAG 2
#define ERROR -1
typedef int status;
typedef struct student{
	long long int num;
	char name[20];
	int score;
	student* next;
}student;

class Linklist{
	private:
		student* head;//ͷ��� 
	public:
		Linklist();
		~Linklist();
		int Length();
		status Add(long long int,const char*,int);
		status ReadFile();
		void TraversePrint();
		status Delete(long long int,long long int);
};
Linklist::Linklist(){
	head=(student*)malloc(sizeof(student));
	if(head)
	head->next=NULL;
}
Linklist::~Linklist(){
	student* p=NULL;
	while(head){
		p=head->next;
		free(head);
		head=p;
	}
}
int Linklist::Length(){
	if(!head)return ERROR;
	student* p=head->next;
	int temp=0;
	while(p){
		temp++;
		p=p->next;
	}
	return temp;
}

status Linklist::Add(long long int num,const char* name,int score){
	student* temp=(student*)malloc(sizeof(student));
	if(!temp) return ERROR;
	temp->num=num;
	temp->score=score;
	strcpy(temp->name,name);
	student* p=head;//����ǰ�� 
	student* q=head->next;
	while(q){
		if(num<q->num){//��λ�������λ�� 
			p->next=temp;
			temp->next=q;
			return OK;
		}
		if(num==q->num){//���ѧ����ͬ �򸲸� 
			q->score=score;
			strcpy(q->name,name);
			return FLAG;
		}
		
		p=p->next;//λ�� 
		q=q->next;
	}
	p->next=temp;//������������������������� 
	temp->next=NULL;
	return OK;
	
}
void Linklist::TraversePrint(){
	student* p=head->next;
	while(p){
		cout<<p->num<<"\t"<<p->name<<"\t"<<p->score<<endl;
		p=p->next;
	}
}

status Linklist::ReadFile(){
	fstream f;
	f.open("info.txt");
	long long int num;
	char name[20];
	int score;
	while(!f.eof()){
		f>>num>>name>>score;
		Add(num,name,score);
	}
}
status Linklist::Delete(long long int mink,long long int maxk){
	if(maxk<mink)return ERROR;
	student* p=head;
	student* q=head->next;
	while(q){
		if(q->num>mink){//��ʱ��p����Ҫ���� 
			student* r;  
			while(q){
				r=q->next;//������ 
				if(q->num<maxk){//mink��maxk֮���  free 
					free(q);
					q=r;//����q 
				} 
				else{//���Ա���ʣ�µ� 
					p->next=q;
					return OK;	
				}				
//				r=q->next;
//				if(q->num>maxk){
//					p->next=q;
//					return OK;
//				}
//				if(p->num==maxk){
//					p->next=q->next;
//					free(q);
//					return OK;
//				}
//				free(q);
//				q=r;
			} 
			p->next=NULL;//num�ر��  ��mink�����ȫ����Ҫ�� 
			return OK;
		}
		
		p=p->next;
		q=q->next;
	}
	return ERROR;
}

main(){
	long long int num;
	char name[20];
	int score;
	Linklist l;
	l.ReadFile();
	int i=4;
	long long int mink,maxk;
	while(i){
		cout<<"������\n1������³�Ա\n2��������г�Ա\n3��ɾ��һ����Χ�ڵĳ�Ա\n0���˳�"<<endl; 
		cin>>i; 
		switch(i){
			case 1:
				cout<<"������ѧ�� ���� �ɼ�"<<endl;
				cin>>num>>name>>score;
				status tempstatus;
				tempstatus=l.Add(num,name,score);
				if(tempstatus==OK)
				cout<<"����ɹ�"<<endl;
				if(tempstatus==FLAG)
				cout<<"ѧ���Ѵ��ڣ����Ǿ���Ϣ�ɹ�"<<endl; 
				break;
			case 2:
				cout<<"---------------"<<endl;
				cout<<"��������"<<endl;
				l.TraversePrint();
				cout<<"---------------"<<endl;
				break;
			case 3:
				cout<<"������ɾ����Χ���½���Ͻ磬�ո�ָ�"<<endl;
				cin>>mink>>maxk;
				if(l.Delete(mink,maxk)>0)
				cout<<"success"<<endl;
				else
				cout<<"wrong"<<endl;
				break;
			case 0:exit(0);break;
		}
	}
	
}
