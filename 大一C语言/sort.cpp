#include<stdio.h>
int RecurBinarySearch(int array[],int size,int num,int ,int);
main(){
	int i,size,num;
	scanf("%d",&size);
	int array[size];
	for(i=0;i<size;i++)
	scanf("%d",&array[i]);
	scanf("%d",&num);
	
	printf("%d",RecurBinarySearch(array,size,num,0,size-1));
}

int RecurBinarySearch(int array[],int size,int num,int first,int last){
	if(first<=last){
	if(num==array[(first+last)/2])
	return (first+last)/2;
	else
	if(num>array[(first+last)/2])
	return RecurBinarySearch(array,size,num,(first+last)/2+1,last);
	else
	if(num<array[(first+last)/2])
	return RecurBinarySearch(array,size,num,first,(first+last)/2-1);
}
	else
	return -1;
	/*int i,flag=0;
	for(i=0;i<size&&flag==0;i++){
		if (num==array[i])
		flag=1;		
	}
	if(flag==1)
	return i-1;
	else
	return -1;*/
}
