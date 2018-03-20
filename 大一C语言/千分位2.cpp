#include<stdio.h>
#include<math.h>
int len(int num);

int main(){
	int i,num,a,flag=0;
	scanf("%d",&num);
	for(i=len(num);i>0;i--){
		a=num/(int)pow(10,i-1)%10;
		if(flag==0||i%3!=0)
		{
		printf("%d",a);
		flag=1;}
		else
	{
			printf(",%d",a);
		flag=1;
	}
	}
}


int len(int num)
{
	int i;
	for(i=0;num!=0;i++){
		num=num/10;
	}
	return i;
}
