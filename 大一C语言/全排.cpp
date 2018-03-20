#include<stdio.h>
int panding(char array[],int m,int i);
void quanpai(char array[],int m,int n);
int count=0;
main(){
	int n;
	scanf("%d",&n);
	getchar();
	char array[n];
	gets(array);
	quanpai(array,0,n);
	printf("%d",count);
}

void quanpai(char array[],int m,int n){
	char ch;
	if(m==n-1){
	puts(array);
	count++;}
	else
	for(int i=m;(i<n&&panding(array,m,i)==1)||m==i;i++){
		ch=array[m];
		array[m]=array[i];
		array[i]=ch;
		
		quanpai(array,m+1,n);
		ch=array[m];
		array[m]=array[i];
		array[i]=ch;
	}
}

int panding(char array[],int m,int i){
	int flag=1;
	for(;flag==1&&m<i;m++)
	if(array[m]==array[i])
	flag=0;
	return flag;
}
