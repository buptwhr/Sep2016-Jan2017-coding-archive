#include<stdio.h>

main(){
	int m,n,a,b,i,j,k=0,l=0;
	scanf("%d %d",&m,&n);
	for (i=m;i>0;i--)
		for(j=n;j>0;j--)
			for(a=1;a<=i;a++)
				for(b=1;b<=j;b++){
					if(a==b)
					k++;
					else
					l++;
				}
				printf("%d %d",k,l);
}
