#include<stdio.h>
void niubi(int [],int ,int); 
main(){
	int num,i=0,mark;
	scanf("%d",&num);
	int array[num];
	for(i=0;i<num;i++)
	scanf("%d",&array[i]);
	i=0;
	for(mark=0;mark<num;mark++){
		if(array[i]%2==1)
		niubi(array,i,num);
		else
		i++;
	
	}
	printf("%d",array[0]);
	for(i=1;i<num;i++)
	printf(" %d",array[i]);
	printf("\n");
	
}

void niubi(int a[],int i,int num){
	int temp;
	temp=a[i];
	for(;i<num-1;i++)
	a[i]=a[i+1];
	a[i]=temp;
	
}
