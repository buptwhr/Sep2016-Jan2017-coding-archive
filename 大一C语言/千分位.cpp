#include <stdio.h>
#include <math.h>
int len(int);
int main(){
	int num,a;
	scanf("%d",&num);
	while(num>=1000){
		if(len(num)%3==0){
			a=num/pow(10,len(num)-3);
			printf("%d,",a);
			num=num%(int)(pow(10,len(num)-3));
			
		}
		else{
			a=num/pow(10,len(num)-len(num)%3);
			printf("%d,",a);
			num=num%(int)(pow(10,len(num)-len(num)%3));
			
		}
	}
	printf("%d",num);
}

int len(int num)
{
	int i;
	for(i=0;num!=0;i++){
		num=num/10;
	}
	return i;
}
