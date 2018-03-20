#include <stdio.h>
#include<time.h>
double f(double num);
int main(){
	int num,t1,t2;
	t1=time(NULL);
	scanf("%d",&num);
    printf("%lf\n",f(num));
    t2=time(NULL);
    printf("%d s",t2-t1);
}



double f(double num)//ì³²¨ÄÇÆõ 
{
	if(num==1||num==2)
	return 1.0;
	else
	return f(num-1)+f(num-2);
}
