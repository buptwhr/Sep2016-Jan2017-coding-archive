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

#define INCREMENT 2//每次扩展容量 
#define MAXSIZE 12//表容量 
typedef struct{
		long long int num;
		char name[20];
		int score;
}student;
class List{//object-oriented using constructor and destructor 
	private:
		//线性表数据
		student* Elem;//线性表指针 
		int size;//表长 
		int length;//数据长度 
	public:
		List();//list初始化 
		~List();//析构 
		void Clear();//清空所有学生数据 
		status isEmpty();//判断是否为空 
		int Length();//求表长 
		status Add(long long int num,const char* name,int score);//新增学生 
		status ReadFile();//读取文件里的学生信息 
		void TraversePrint();//遍历输出所有学生信息 
};
List::List(){//构造函数 分配固定空间 初始化表 
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
status List::Add(long long int num,const char* name,int score){//按照num排序插入 位移 控制空间  空表等情况 
	if(!Elem)return ERROR;
	if(length==size){//扩展表 
		student* newElem=(student*)realloc(Elem,(size+INCREMENT)*sizeof(student));
		if(!newElem)return OVERFLOW;
		Elem=newElem;
		size+=INCREMENT; 
	}
	
	if(length==0){//如果长度为0 直接赋 
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
		if(num==ptr->num){//如果学号相同 则覆盖旧信息 长度不变 
			strcpy(ptr->name,name);
			ptr->score=score;
			return FLAG;//标记 
		}
	}
}//如果学号最大
	Elem[length].num=num;
	Elem[length].score=score;
	strcpy(Elem[length].name,name);
	length++;
	return OK; 
}

status List::ReadFile(){//读取文件信息 
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
void List::TraversePrint(){//遍历输出 
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
		cout<<"请输入\n1、添加新成员\n2、输出所有成员\n0、退出"<<endl; 
		cin>>flag; 
		switch(flag){
			
			case 1:
			cout<<"请输入学号 姓名 成绩"<<endl;
			cin>>num>>name>>score;
			status tempstatus;
			tempstatus=L.Add(num,name,score);
			if(tempstatus==OK)
			cout<<"输入成功"<<endl;
			if(tempstatus==FLAG)
			cout<<"学号已存在，覆盖旧信息成功"<<endl; 
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
