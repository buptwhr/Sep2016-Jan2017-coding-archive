#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int  arr[]={99,94,100,95,93,92,91,88,97,89};
	int i,j;
	for(i=0;i<=9;i++)
	{
		if (i!=9)
		printf("%d ",arr[i]);
		else
		printf("%d",arr[i]);
	}
	for(i=8;i>=0;i--)//
	{
		for(j=0;j<=i;j++)
		{
			if(arr[j]>arr[j+1])
			{  /*int temp;
				temp=arr[j];
				arr[j]=arr[j+1];     »¥»» 
				arr[j+1]=temp;
				*/
				arr[j]=arr[j+1]-arr[j];
				arr[j+1]=arr[j+1]-arr[j];
				arr[j]=arr[j]+arr[j+1];//Ææ¼¼ÒùÇÉ 
				
			 } 
		}
		
	}

printf("\n-------ÅÅĞòÖ®ºó---------\n");
for(i=0;i<10;i++)
{
	printf("%d ",arr[i]);
}
}
