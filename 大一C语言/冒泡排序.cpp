#include<stdio.h>

main(){
	int i,j,size,temp;
	scanf("%d",&size);
	int array[size];
	for(i=0;i<size;i++)
	scanf("%d",&array[i]);
	
	for(i=0;i<size;i++)
		for(j=0;j<size-1-i;j++){
			if(array[j]>=array[j+1]){
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	for(i=0;i<size;i++)
	printf("%d ",array[i]);
} 
