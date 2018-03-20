#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define LOSER 4//������4�ı����ı���̭ 
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


struct link* circle(int n){//����һ������Ϊn�Ļ������� ����head��ʼ����ֵ1��2��3... 
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

