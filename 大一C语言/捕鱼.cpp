#include<stdio.h>
main()
{
	int i,flag,time,x1,x2;
	i=1;
	flag=0;
	while(flag==0)
	{
		x1=i;
		time=1;
		while(time<=5&&(x1-1)%5==0&&(x1-1)>0)
		{
			x2=4*(x1-1)/5;
			x1=x2;
			time++;
		}
		if(time==6)
		{
			printf("%d",i);
			flag=1;
		}
		else
		i++;
	}
	
}
