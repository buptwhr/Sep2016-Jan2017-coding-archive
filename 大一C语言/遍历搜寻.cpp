#include<stdio.h>
main()
{
	int a,b,c,i,j,max,cha,time=0,flag=0;
	scanf("%d%d%d",&a,&b,&c);
	for(i=a;i<=b;i++)
	{
		max=0;
		for(j=1;j<i;j++)
		{
			if(i%j==0)
			max=max+j;
		}
		cha=i-max;
		if(cha<0)
		cha=-cha;
		if(cha<=c)
		{	time++;
			if(time%5!=1)
			printf("\t");
			printf("%d",i);
		
		flag=1;
		if((time%5==0)&&(flag==1))
		printf("\n");
	
		
		}
		
		
	}
	if(flag==0)
	printf("There is no proper number in the interval.");
	if(time%5!=0&&flag==1)
	printf("\n");
 } 
