#include<stdio.h>
#include<math.h>
main()
{
	double x,a,b;
	int i=1;
	scanf("%lf",&x);
	a=1.0;
	b=a;
	while(fabs(a)>=1e-8)
	{
	a=a*x/i;
	b=b+a;
	i++;
	
	}
	printf("%.4f",b);
	
 } 
