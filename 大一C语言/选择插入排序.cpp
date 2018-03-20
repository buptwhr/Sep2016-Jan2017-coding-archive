#include<stdio.h>
void InsertSort(int a[],int n);
void insert(int a[],int to,int from);
main(){
	int n,i;
	scanf("%d",&n);
	int array[n];
	for (i=0;i<n;i++)
	scanf("%d",&array[i]);
	InsertSort(array,n);
	printf("%d",array[0]);
	for(i=1;i<n;i++)
	printf("% d",array[i]);
	printf("\n");
	
}
void insert(int a[],int to,int from){
	int i,temp;
	temp=a[from];
	for(i=from;i>to;i--)
	a[i]=a[i-1];
	a[to]=temp;
}
void InsertSort(int a[],int n){
	int i,j;
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(a[i]<a[j])
			insert(a,j,i);
		}
	}
}
