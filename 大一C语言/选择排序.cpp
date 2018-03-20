#include<stdio.h>
#include<string.h>
int xiabiao(int[],int);
void selectsort(int[],int);
main(){
	int n,i;
	scanf("%d",&n);
	int array[n];
	for (i=0;i<n;i++){
		scanf("%d",&array[i]);
	}
	selectsort(array,n);
	for(i=0;i<n;i++){
		printf("%d ",array[i]);
	}
}


int xiabiao(int array[],int size){//求出最大值的下标 
	int max=0,i,mark;
	for(i=0;i<size;i++){
		if(array[i]>max){
			max=array[i];
			mark=i;
		}
	}
	return mark;
}
void  selectsort(int array[],int size){//排序 
	int temp,i,j;
	for(i=size-1;i>=0;i--){//i控制下标 
		temp=array[xiabiao(array,i+1)];
		array[xiabiao(array,i+1)]=array[i];
		array[i]=temp;
	}
}







