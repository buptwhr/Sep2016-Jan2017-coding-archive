#include<stdio.h>
int convert(int n);
main(){
	int num;
	scanf("%d",&num);
	printf("%d",convert(num));
}


int convert(int n){
	if(n==1||n==0)
	return n;
	else
	return n%10+convert(n/10)*2;
}
