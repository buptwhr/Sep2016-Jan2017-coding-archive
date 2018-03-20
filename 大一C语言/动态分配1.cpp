#include<stdio.h>
#include<stdlib.h>
int *Create1(int n);
main(){
	int n,num;
	scanf("%d",&n);
	int *p=Create1(n);
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		*(p+i)=num*(-10);
	}
	printf("%d",*(p));
	for(int i=1;i<n;i++)
	printf(" %d",*(p+i));
	
	free(p);
	p=NULL;
}
int *Create1(int n){
	int *p;
	p=(int*)malloc(sizeof(int)*n);
	return p;
}
