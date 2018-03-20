#include<cstdlib>
#include<string.h>
#include<iostream>
#include<fstream>
using namespace std;
typedef int status; 
#define OK 1
#define ERROR -1
#define FALSE 0
#define OVERFLOW -2
#define FLAG 2 

#define INCREMENT 2//ÿ����չ���� 
#define MAXSIZE 12//������ 
typedef struct{
		long long int num;
		char name[20];
		int score;
}student;
class List{//object-oriented using constructor and destructor 
	private:
		//���Ա�����
		student* Elem;//���Ա�ָ�� 
		int size;//�� 
		int length;//���ݳ��� 
	public:
		List();//list��ʼ�� 
		~List();//���� 
		void Clear();//�������ѧ������ 
		status isEmpty();//�ж��Ƿ�Ϊ�� 
		int Length();//��� 
		status Add(long long int num,const char* name,int score);//����ѧ�� 
		status ReadFile();//��ȡ�ļ����ѧ����Ϣ 
		void TraversePrint();//�����������ѧ����Ϣ 
};
List::List(){//���캯�� ����̶��ռ� ��ʼ���� 
	Elem=(student*)malloc(MAXSIZE*sizeof(student));
	size=MAXSIZE;
	length=0;
} 
List::~List(){
	if(Elem){
		free(Elem);
		size=0;
		length=0;
	}
}

void List::Clear(){
	if(Elem) length=0;
}
status List::isEmpty(){
	if(!Elem)return ERROR;
	if(length)return OK;
	return FALSE;
}
int List::Length(){
	if(!Elem) return ERROR;
	return length;
}
status List::Add(long long int num,const char* name,int score){//����num������� λ�� ���ƿռ�  �ձ����� 
	if(!Elem)return ERROR;
	if(length==size){//��չ�� 
		student* newElem=(student*)realloc(Elem,(size+INCREMENT)*sizeof(student));
		if(!newElem)return OVERFLOW;
		Elem=newElem;
		size+=INCREMENT; 
	}
	
	if(length==0){//�������Ϊ0 ֱ�Ӹ� 
		Elem->num=num;
		Elem->score=score;
		strcpy(Elem->name,name);
		length++;
		return OK;
		
	}
	else{//else 
		
	for(student* ptr=Elem;ptr<=Elem+length-1;ptr++){
	
		if(num<ptr->num){
			for(student* ptr2=&Elem[length-1];ptr2>=ptr;ptr2--){
				*(ptr2+1)=*(ptr2);
			}
			
			ptr->num=num;
			ptr->score=score;
			strcpy(ptr->name,name);
			length++;
			return OK;
		}
		if(num==ptr->num){//���ѧ����ͬ �򸲸Ǿ���Ϣ ���Ȳ��� 
			strcpy(ptr->name,name);
			ptr->score=score;
			return FLAG;//��� 
		}
	}
}//���ѧ�����
	Elem[length].num=num;
	Elem[length].score=score;
	strcpy(Elem[length].name,name);
	length++;
	return OK; 
}

status List::ReadFile(){//��ȡ�ļ���Ϣ 
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
void List::TraversePrint(){//������� 
	for(int i=0;i<length;i++){
		cout<<Elem[i].num<<"\t"<<Elem[i].name<<"\t"<<Elem[i].score<<endl;
	}
}
main(){
	long long int num;
	char name[20];
	int score;
	List L;
	L.ReadFile();
	int flag=3;
	while(flag){
		cout<<"������\n1������³�Ա\n2��������г�Ա\n0���˳�"<<endl; 
		cin>>flag; 
		switch(flag){
			
			case 1:
			cout<<"������ѧ�� ���� �ɼ�"<<endl;
			cin>>num>>name>>score;
			status tempstatus;
			tempstatus=L.Add(num,name,score);
			if(tempstatus==OK)
			cout<<"����ɹ�"<<endl;
			if(tempstatus==FLAG)
			cout<<"ѧ���Ѵ��ڣ����Ǿ���Ϣ�ɹ�"<<endl; 
			break;
			case 2:	
			cout<<"---------------"<<endl;
			L.TraversePrint();
			cout<<"---------------"<<endl;
			break;
			case 0:exit(0); 
		}
	} 

}
