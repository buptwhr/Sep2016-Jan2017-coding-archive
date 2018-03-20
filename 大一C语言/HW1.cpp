#include<stdio.h>
main()
{
	int a,b,c,d,e;
	a=0;
	b=0;
	c=0;
	d=0;

	char ch;

	while(scanf("%c",&ch)!=EOF)
	{
		
		if((ch>=65&&ch<=90)||(ch>=97&&ch<=122))
		a++;
		else
		if(ch==32)
		b++;
		else
		if(ch>=48&&ch<=57)
		c++;
		else
		d++;
	
	}
	
	printf("%d %d %d %d",a,b,c,d);
}
