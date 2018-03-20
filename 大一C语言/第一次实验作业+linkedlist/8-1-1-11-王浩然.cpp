#include<stdio.h>
#include<stdlib.h>
struct link{
	int data;
	struct link* nextPtr;
};
void FreeFunction(struct link* p);//释放内存 
int len(struct link* p);//计算链表长度  返回int长度 
void shuchuFunction(struct link* head);//输出函数 
struct link* shengchengFunction();//生成链表  返回头指针 

main(){
	struct link* Ahead,*Bhead;
	printf("Please input list A(end by -1):");
	Ahead=shengchengFunction();
	printf("Please input list B(end by -1):");
	Bhead=shengchengFunction();
	struct link* moveA,*moveB,*sequenceStart;
	sequenceStart=Ahead;
	int flag=0,flagg=1;
	while(sequenceStart!=NULL&&flag==0){
	if(sequenceStart->data==Bhead->data){			
		moveB=Bhead;
		moveA=sequenceStart;
		for(;moveA->data==moveB->data;){
			moveA=moveA->nextPtr;
			moveB=moveB->nextPtr;		
	
			if((moveB==NULL||moveA==NULL))
			break; 
		}
		if(moveB==NULL){
			flag=1;
		}
	}
	sequenceStart=sequenceStart->nextPtr;	 
	}	
	if(flag==1)
	printf("ListB is the sub sequence of ListA.");
	else
	printf("ListB is not the sub sequence of ListA.");
	FreeFunction(Ahead);
	FreeFunction(Bhead);
	Ahead=Bhead=moveA=moveB=sequenceStart=NULL;
}
void FreeFunction(struct link* p){
	struct link* temp;
	while(p!=NULL){
		temp=p->nextPtr;
		free(p);
		p=temp;
	}
}
int len(struct link* p){
	int n=0;
	while(p!=NULL){
		n++;
		p=p->nextPtr;
	}
	return n;
} 

void shuchuFunction(struct link* head){
	
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->nextPtr;
	}
}
struct link* shengchengFunction(){
	struct link* current=NULL,*last=NULL,*head=NULL;
	int data;
	
	scanf("%d",&data); 
	while(data!=-1){                           //-1结尾 
		current=(struct link*)malloc(sizeof(struct link));
		if(current==NULL){
			printf("Wrong!");
			return 0;
		}
		else{                                //成功分配内存后 
			current->data=data;              
			current->nextPtr=NULL;
			if(head==NULL){                  //header 
				head=current;
				last=current;
			}
			else{                             //APPEND
				last->nextPtr=current;
				current=NULL;
				last=last->nextPtr;				
			}
			scanf("%d",&data);                 //建立链表，并录入数据 
		}		
}
		return head;
} 
