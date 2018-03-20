#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct link{
	int data;
	struct link* nextPtr;
};
void FreeFucntion(struct link* p);
main(){
	struct link* current=NULL,*last=NULL,*head=NULL;
	int data;
	printf("Please input a series of integers:");
	scanf("%d",&data); 
	while(data!=-1){
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
		/*遍历链表 寻找max,min,sum*/
	} 
	int max=0,sum=0,min=999999999;
	struct link* p=head; 
	while(p!=NULL){// 移动p遍历 
		sum+=p->data;
		max=max>p->data?max:p->data;
		min=min<p->data?min:p->data;
		p=p->nextPtr;
	}
	printf("The maximum,minum and the total are:%d %d %d",max,min,sum);
	FreeFucntion(head);
	current=last=head=NULL; 
}

void FreeFucntion(struct link* p){
	struct link* temp;
	while(p!=NULL){
		temp=p->nextPtr;
		free(p);
		p=temp;
		
	}
	
} 


