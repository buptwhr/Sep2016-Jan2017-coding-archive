#include<stdio.h>
main()
{
	int a,b,c,d;
	float x1,x2,x;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	x2=1;
	x=1;
	while(x<-0.00001||x>0.00001)
	{
		x1=x2;
		x2=x1-(a*x1*x1*x1+b*x1*x1+c*x1+d)/(3*a*x1*x1+2*b*x1+c);
		x=x2-x1;
	}
	printf("%f",x2);
}
