#include<stdio.h>
main()
{
	int n,i,sum,s;
	sum=0;
	
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		if(i%21==0)
		sum=sum+i;
	}
	s=sum*sum;
	printf("%d",s);
 } 
