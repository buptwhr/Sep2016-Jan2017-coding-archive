#include<stdio.h> 

main()
{		int n,p=10;
		float x=0;
		char ch;
		scanf("%c",&ch);
		while(ch!='#')
	{
		scanf("%c",&ch);
		n=ch-'0';
		x=x+(float)n/p;
		p=10*p;
	}
	
	
	printf("%f",x);
}
