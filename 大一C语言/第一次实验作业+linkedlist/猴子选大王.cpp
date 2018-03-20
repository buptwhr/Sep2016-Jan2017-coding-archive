#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define LOSER 4//报数是4的倍数的被淘汰 
struct link* circle(int n);
struct link{
	int data;
	struct link* nextPtr;
};

main(){
	int n;
	printf("input the number of monkeys:");
	scanf("%d",&n);
	struct link *previous,*current;
	previous= circle(n);
	current=previous->nextPtr;
	int num=0;
	while(current!=current->nextPtr){
		num++;
		if(num%LOSER==0){
			previous->nextPtr=current->nextPtr;
			current=current->nextPtr;
		}
		else{
			previous=current;
			current=current->nextPtr;
		}
		
	} 
	printf("\nThe monkey king is:%d",current->data);
}


struct link* circle(int n){//生成一个长度为n的环形链表 ，从head开始，赋值1，2，3... 
	struct link* head=NULL,*current=NULL,*last=NULL;
	int m=n;
	while(n--){
		current=(struct link*)malloc(sizeof(struct link));
		if(current==NULL){
			printf("Wrong!");
			return 0;
		}
		else{
			current->data=m-n;
			current->nextPtr=NULL;
			if(head==NULL){
				head=current;
				last=current;
			}
			else{
				last->nextPtr=current;
				last=current;
				current=NULL;
			}
		}
	}
	last->nextPtr=head;
	return last;
} 

