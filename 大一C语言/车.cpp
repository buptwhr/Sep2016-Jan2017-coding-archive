#include<stdio.h>
main()
{
	int max,a,car,time;
	char x;
	car=0;
	time=0;
	max=0;
	a=0;
	scanf("%c",&x);
	while(x!='#')
	{
		if(x=='1')
		{
			car=car+1;
			a=a+1;
		}
		else
		{
			time=time+1;
			if(a>=1)
			{
				if(max<=a)
				max=a;
				else
				max=max;
				a=0;
			}
			
			
		}
		scanf("%c",&x);
	}
	printf("%d %d %d",car,time,max);
 } 
