#include<stdio.h>

main(){
	int n,m,i,j,flag=0;
	scanf("%d",&n);
	int array1[n];
	for(i=0;i<n;i++)
	scanf("%d",&array1[i]);
	scanf("%d",&m);
	int array2[m];
	for(i=0;i<m;i++)
	scanf("%d",&array2[i]);
	
	
	for(i=0;i<m;i++){
		flag=0;
		for(j=0;j<n&&flag==0;j++){
			if(n==1)
			printf("NULL\n");
			else{
			
			if(array1[j]==array2[i]){
				if (j==0)
				printf("%d\n",array1[1]);
				else
				if(j==n-1)
				printf("%d\n",array1[n-2]);
				else
				printf("%d %d\n",array1[j-1],array1[j+1]);
				flag=1;
			}
			else
			if(j==n-1)
			printf("NULL\n");}
		}
		}
}

