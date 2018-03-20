#include<stdio.h>
main()
{
	int z=0,n,p=10;
	float x=0; 
	char ch;
	scanf("%c",&ch);
	while(ch!='#'&&ch!='.') 
	{
		n=ch-'0';
		z=z*10+n;
		scanf("%c",&ch);
	}
		scanf("%c",&ch);
	while(ch!='#')
	{
	
		n=ch-'0';
		x=x+(float)n/p;
		p=10*p;
			scanf("%c",&ch);
	}
	
	
	printf("%f",z+x);
	
}
