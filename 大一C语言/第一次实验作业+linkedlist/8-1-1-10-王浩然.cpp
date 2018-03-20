#include<stdio.h>
#include<stdlib.h>
struct link{
	int data;
	struct link* nextPtr;
};
void FreeFucntion(struct link* p);//释放内存 
int len(struct link* p);//计算链表长度 
void shuchuFucntion(struct link* head);//输出函数 
main(){
	struct link* current=NULL,*last=NULL,*head=NULL;
	int data;
	printf("Please input a list(end by -1):");
	scanf("%d",&data); 
	while(data!=-1){                           //-1结尾 
		current=(struct link*)malloc(sizeof(struct link));
		if(current==NULL){
			printf("Wrong!");
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
}	/*冒泡排序*/
		
		struct link* initial;
		initial=(struct link*)malloc(sizeof(struct link));
		initial->nextPtr=head;//第一个节点前放置一个空节点，便于交换操作
		struct link* previous;
		previous=initial;//随current一起移动 
		current=head;
		
		
		int length=len(head)+1;
		while(length--) {//有多少个节点 就循环多少次 不是很会控制大循环 
		
		//内循环
		while(current->nextPtr!=NULL){
			if(current->data>current->nextPtr->data){
				previous->nextPtr=current->nextPtr;
				current->nextPtr=current->nextPtr->nextPtr;
				previous->nextPtr->nextPtr=current;
				previous=previous->nextPtr;
			}
			else{
				previous=current;
				current=current->nextPtr;
			}
		} //内循环结束 
		previous=initial;
		current=previous->nextPtr;
	}
	printf("The new list is:");
	shuchuFucntion(initial->nextPtr);
	FreeFucntion(initial);
	initial=head=last=current=previous=NULL; 
		
}

void FreeFucntion(struct link* p){
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

void shuchuFucntion(struct link* head){
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->nextPtr;
	}
}
