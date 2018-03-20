#include<stdio.h>
#include<stdlib.h>
int **Create2(int n,int m);
main(){
	int num,n,m;
	scanf("%d %d",&n,&m);
	int **p=Create2(n,m);
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++){
		scanf("%d",(*(p+i)+j));
		*(*(p+i)+j)=*(*(p+i)+j)*(-10);
	}
	for(int i=0;i<n;i++){
	printf("%d",*(*(p+i)+0));
	for(int j=1;j<m;j++){
	printf(" %d",*(*(p+i)+j));
	}
	printf("\n");
}
}

int **Create2(int n,int m){
	int **p;
	p=(int**)malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++)
	*(p+i)=(int*)malloc(sizeof(int)*m);
	return p;
}
