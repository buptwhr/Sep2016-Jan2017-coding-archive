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
		student* head;//头结点 
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
	student* p=head;//保存前驱 
	student* q=head->next;
	while(q){
		if(num<q->num){//定位到插入的位置 
			p->next=temp;
			temp->next=q;
			return OK;
		}
		if(num==q->num){//如果学号相同 则覆盖 
			q->score=score;
			strcpy(q->name,name);
			return FLAG;
		}
		
		p=p->next;//位移 
		q=q->next;
	}
	p->next=temp;//如果遍历完链表，则接在链表最后 
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
		if(q->num>mink){//此时的p不需要动了 
			student* r;  
			while(q){
				r=q->next;//保存后继 
				if(q->num<maxk){//mink与maxk之间的  free 
					free(q);
					q=r;//后移q 
				} 
				else{//可以保留剩下的 
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
			p->next=NULL;//num特别大  则mink后面的全都不要了 
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
		cout<<"请输入\n1、添加新成员\n2、输出所有成员\n3、删除一定范围内的成员\n0、退出"<<endl; 
		cin>>i; 
		switch(i){
			case 1:
				cout<<"请输入学号 姓名 成绩"<<endl;
				cin>>num>>name>>score;
				status tempstatus;
				tempstatus=l.Add(num,name,score);
				if(tempstatus==OK)
				cout<<"输入成功"<<endl;
				if(tempstatus==FLAG)
				cout<<"学号已存在，覆盖旧信息成功"<<endl; 
				break;
			case 2:
				cout<<"---------------"<<endl;
				cout<<"链表数据"<<endl;
				l.TraversePrint();
				cout<<"---------------"<<endl;
				break;
			case 3:
				cout<<"请输入删除范围的下界和上界，空格分割"<<endl;
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
