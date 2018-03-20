#include<stdio.h>
#include<math.h>
main()
{
	float a,b,c,d,e;

	scanf("%f %f %f",&a,&b,&c); 
	d=b*b-4*a*c;	
	if(a==0)
	printf("The equation is not quadratic.");
	else
	if(d>0)
	{
		e=sqrt(d);
		printf("The equation has two distinct real roots: %.4f and %.4f.",-b/(2*a)+e/(2*a),-b/(2*a)-e/(2*a));
	}
	else
	if(d==0)
	printf("The equation has two equal roots: %.4f.",-b/(2*a));
	else
	{
		e=sqrt(-d);
		printf("The equation has two complex roots: %.4f+%.4fi and %.4f-%.4fi.",-b/(2*a),e/(2*a),-b/(2*a),e/(2*a));
	}
}
