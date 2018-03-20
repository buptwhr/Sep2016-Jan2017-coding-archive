#include<iostream>
#include<fstream>
#define MAXSIZE 30
using namespace std;
typedef struct studentlist{//˳��ṹ ��Ա 
	string num;
	string name;
	int score;
}studentlist;
typedef struct student{//��ʽ�ṹ��Ա 
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
		void quicksort_(student* low,student* high);//�����ڲ����� 
		student* partition(student*,student*);//�����ڲ����� 
		
		studentlist list[MAXSIZE];//ת��˳��� 
		int length;//˳����� 
	public:
		LUT();//���� 
		void output();//��� 
		void quicksort(); //����ֱ�Ӳ����Ŀ��� 
		void listed();//ת�浽˳���list�� 
		void lookup(int);//˳��������ĳһ�ɼ�������� 
};
LUT::LUT(){//�ļ���ȡ 
	fstream f;
	f.open("student.txt");
	student* pre=&head;
	student* s;
	while(!f.eof()){
		s=new student;
		f>>s->num>>s->name>>s->score;
		pre->next=s;//�������� 
		s->pre=pre;
		pre=s;
	}
	pre->next=&tail;
	tail.pre=pre;
	tail.next=NULL;//β������ 
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
	student *temp1=low->pre;//��¼ͷָ��ǰ��βָ����ָ�� 
	student *temp2=high->next;
	if(!(low==high||low==high->next)){
	
		student* pivot=partition(low,high);
		quicksort_(temp1->next,pivot->pre);
		quicksort_(pivot->next,temp2->pre);	
	}

}
student* LUT::partition(student* low,student* high){//��lowΪ����  ����ƶ� high��ǰ�ƶ�
	student* pivot=low;
	low=pivot->next;
	low->pre=pivot->pre;
	pivot->pre->next=low;
	//������lowǰ high��
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
	cout<<"�ɼ�"<<score<<"������"<<endl; 
}
main(){
	LUT l;
	cout<<"ԭ˳��Ϊ\n"; 
	l.output();
	cout<<endl;
	
	l.quicksort();	
	cout<<"���ź�˳��Ϊ"<<endl; 
	l.output();
	cout<<endl;
	
	l.listed();
	cout<<"������Ҫ���ҵĳɼ�,����0�˳�"<<endl;
	int score;
	cin>>score; 
	while(score!=0){
		l.lookup(score);
		cout<<"������Ҫ���ҵĳɼ�,����0�˳�"<<endl;
		cin>>score;
	}
	
}


