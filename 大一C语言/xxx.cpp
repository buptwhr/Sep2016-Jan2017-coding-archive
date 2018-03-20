#include<stdio.h>
main()
{
	int a=1;
	(++a) += (a++);
	printf("%d", a);
	return 0;
 } 
