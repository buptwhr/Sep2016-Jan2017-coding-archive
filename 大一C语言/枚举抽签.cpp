#include<stdio.h>
main()
{	
	int x=0,i=0;
	char a,b,c,d;
	printf("There are %d ways to assign the players.\n",7); 

	for(a='W';a<='Z';a++)
		for (b='W';b<='Z';b++)
			for(c='W';c<='Z';c++)
				for(d='W';d<='Z';d++)
				{
					if(a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d&&a!='X'&&c!='X'&&c!='Z'&&d!='W')
					{
					i++;
					printf("Group %d:\n",i);
					printf("A VS %c\n",a);
					printf("B VS %c\n",b);
					printf("C VS %c\n",c);
					printf("D VS %c\n",d);
					}
				}
	
}
