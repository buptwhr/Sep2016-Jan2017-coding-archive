#include<iostream>
#include<fstream>
#define MAXSIZE 30
using namespace std;
typedef struct studentlist{//顺序结构 成员 
	string num;
	string name;
	int score;
}studentlist;
typedef struct student{//链式结构成员 
	string num;
	string name;
	int score;
	student *pre;
	student *next;
}student;
class LUT{//look up table
	private:
		student head;
		student tail;
		void quicksort_(student* low,student* high);//快排内部函数 
		student* partition(student*,student*);//快排内部函数 
		
		studentlist list[MAXSIZE];//转存顺序表 
		int length;//顺序表长度 
	public:
		LUT();//构造 
		void output();//输出 
		void quicksort(); //链表直接操作的快排 
		void listed();//转存到顺序表list里 
		void lookup(int);//顺序表里查找某一成绩，并输出 
};
LUT::LUT(){//文件读取 
	fstream f;
	f.open("student.txt");
	student* pre=&head;
	student* s;
	while(!f.eof()){
		s=new student;
		f>>s->num>>s->name>>s->score;
		pre->next=s;//链结相连 
		s->pre=pre;
		pre=s;
	}
	pre->next=&tail;
	tail.pre=pre;
	tail.next=NULL;//尾部封上 
	f.close();
}
void LUT::output(){
	student *s;
	for(s=head.next;s->next!=NULL;s=s->next){
		cout<<s->num<<" "<<s->name<<" "<<s->score<<endl;
	}
}
void LUT::quicksort(){
	quicksort_(head.next,tail.pre);
}
void LUT::quicksort_(student* low,student* high){
	student *temp1=low->pre;//记录头指针前和尾指针后的指针 
	student *temp2=high->next;
	if(!(low==high||low==high->next)){
	
		student* pivot=partition(low,high);
		quicksort_(temp1->next,pivot->pre);
		quicksort_(pivot->next,temp2->pre);	
	}

}
student* LUT::partition(student* low,student* high){//以low为枢轴  向后移动 high向前移动
	student* pivot=low;
	low=pivot->next;
	low->pre=pivot->pre;
	pivot->pre->next=low;
	//插入在low前 high后
	student *temp;
	while(high!=low){
		while(high!=low&&high->score>=pivot->score) high=high->pre;
		if(high!=low){
		temp=high->pre;
		temp->next=high->next;
		high->next->pre=high->pre;
		
		high->pre=low->pre;
		low->pre->next=high;
		high->next=low;
		low->pre=high;
		
		low=high;
		high=temp;
		}
		
		
		while(high!=low&&low->score<=pivot->score) low=low->next;
		if(high!=low){
		temp=low->next;
		temp->pre=low->pre;
		low->pre->next=low->next;
		
		low->next=high->next;
		high->next->pre=low;
		high->next=low;
		low->pre=high;
		
		high=low;
		low=temp;
		}
		
	} 
	if(high->score>pivot->score){
		pivot->pre=high->pre;
		high->pre->next=pivot;
		pivot->next=high;
		high->pre=pivot;
	}
	else{
		pivot->next=high->next;
		high->next->pre=pivot;
		high->next=pivot;
		pivot->pre=high;
	}
	
	return pivot;
	 
}
void LUT::listed(){
	length=0;
	student *s=head.next;
	for(int i=0;s->next!=NULL;i++,s=s->next,length++){
		list[i].num=s->num;
		list[i].name=s->name;
		list[i].score=s->score;
	}
}
void LUT::lookup(int score){
	int low=1,high=length;
	int core; 
	while(low<=high){
		if(list[(low+high)/2].score==score){
			cout<<list[(low+high)/2].num <<" "<<list[(low+high)/2].name<<" "<<list[(low+high)/2].score<<endl;
			core=(low+high)/2;
			for(int i=core-1;list[i].score==score;i--){
				cout<<list[i].num <<" "<<list[i].name<<" "<<list[i].score<<endl;
			}
			for(int i=core+1;list[i].score==core;i++){
				cout<<list[i].num <<" "<<list[i].name<<" "<<list[i].score<<endl;
			}
			return;
		}
		else if(list[(low+high)/2].score>score)
		high=(low+high)/2-1;
		else
		low=(low+high)/2+1;
	} 
	cout<<"成绩"<<score<<"不存在"<<endl; 
}
main(){
	LUT l;
	cout<<"原顺序为\n"; 
	l.output();
	cout<<endl;
	
	l.quicksort();	
	cout<<"快排后顺序为"<<endl; 
	l.output();
	cout<<endl;
	
	l.listed();
	cout<<"请输入要查找的成绩,输入0退出"<<endl;
	int score;
	cin>>score; 
	while(score!=0){
		l.lookup(score);
		cout<<"请输入要查找的成绩,输入0退出"<<endl;
		cin>>score;
	}
	
}


