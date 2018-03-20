#include<stdio.h>
#define KEMU 5
void bubblesort(int *score);
struct student{
	char name[21];
	char number[21];
	int score[KEMU];
	double average;
	int sum;
};
typedef struct student Student;
main(){
	Student xuesheng;
	gets(xuesheng.name);
	gets(xuesheng.number);
	for(int i=0;i<KEMU;i++){
		scanf("%d",&xuesheng.score[i]);
	}	
	bubblesort(xuesheng.score);
	xuesheng.sum=0;
	for(int i=0;i<KEMU;i++){
		xuesheng.sum+=xuesheng.score[i];
	}
	xuesheng.average=(double)xuesheng.sum/KEMU;
	Student *ptr;
	ptr=&xuesheng;
	puts(ptr->name);
	puts(ptr->number);
	for(int i=0;i<KEMU-1;i++){
		printf("%d ",xuesheng.score[i]);
	}
	printf("%d\n",xuesheng.score[KEMU-1]);
	printf("%.2lf %d",ptr->average,ptr->sum);
} 

void bubblesort(int *score){
	int i,j,temp;
	for(i=0;i<KEMU;i++)
	for(j=0;j<KEMU-1;j++){
		if(*(score+j)<*(score+j+1)){
			temp=*(score+j);
			*(score+j)=*(score+j+1);
			*(score+j+1)=temp;			 
		}
	}
}
