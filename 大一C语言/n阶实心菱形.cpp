#include<stdio.h>
main()
{
	int n,i,j,a,b,c,d;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(a=1;a<=(n-i);a++)
		{printf(" ");
		}
		for(b=1;b<=(2*i-1);b++)
		{printf("*");
		}
		a=0;
		b=0;
		printf("\n"); 
	}
	
	for(j=1;j<=(n-1);j++)
	{
		for(c=1;c<=j;c++)
		{printf(" ");
		}
		for(d=1;d<=(2*n-1-2*j);d++)
		{printf("*");
		}
		c=0;
		d=0;
		printf("\n");
	}
	
	
 } 
