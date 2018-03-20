#include<stdio.h>
int isPrime(int n);
void printFactor(int n);

main(){
	int max,min,i;
	scanf("%d %d",&min,&max);
	for(i=min;i<=max;i++)	{

	
	
	printFactor(i);
	printf("\n");}
}


int isPrime(int n){
	int i,flag=0;
	for(i=2;i<n&&flag==0;i++){
		if(n%i==0)
		flag=1;
	}
	if(flag==1)
	return 1;
	else
	return 0;
}

void printFactor(int n){
	int flag=0,i;
	printf("%d=",n);
	if(isPrime(n)==0)
	printf("%d",n);
	else{
	
	for(i=2;i<=n&&flag==0;i++){
		if(n%i==0){
		
		printf("%d",i);
		flag=1;
		n=n/i;}
	}
	for(i=2;i<=n;i++){
		if(n%i==0)
		{
		printf("*%d",i);
		n=n/i;
		i=1;}
	}
}
	
}
