#include<stdio.h>
#include<stdlib.h>
struct link{
	int data;
	struct link* nextPtr;
};
void FreeFucntion(struct link* p);//�ͷ��ڴ� 
int len(struct link* p);//���������� 
void shuchuFucntion(struct link* head);//������� 
main(){
	struct link* current=NULL,*last=NULL,*head=NULL;
	int data;
	printf("Please input a list(end by -1):");
	scanf("%d",&data); 
	while(data!=-1){                           //-1��β 
		current=(struct link*)malloc(sizeof(struct link));
		if(current==NULL){
			printf("Wrong!");
		}
		else{                                //�ɹ������ڴ�� 
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
			scanf("%d",&data);                 //����������¼������ 
		}		
}	/*ð������*/
		
		struct link* initial;
		initial=(struct link*)malloc(sizeof(struct link));
		initial->nextPtr=head;//��һ���ڵ�ǰ����һ���սڵ㣬���ڽ�������
		struct link* previous;
		previous=initial;//��currentһ���ƶ� 
		current=head;
		
		
		int length=len(head)+1;
		while(length--) {//�ж��ٸ��ڵ� ��ѭ�����ٴ� ���Ǻܻ���ƴ�ѭ�� 
		
		//��ѭ��
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
		} //��ѭ������ 
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
