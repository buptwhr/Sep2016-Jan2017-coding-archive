#include<stdio.h>
int countBinary(int n);
main(){
	int num; 
	scanf("%d",&num);
	printf("%d",countBinary(num));
} 

int countBinary(int n){
 	if(n==1||n==0)
	 return 1;
	 else
	 return	countBinary(n/2)+1;
}

