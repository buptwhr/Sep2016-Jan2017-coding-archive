#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void quanp(int q0[],int q1[],int q2[],int m,int n,int p);
main(){
	int flag,n,m=1,i=0,j;
	scanf("%d",&n);
	int n0[n],n1[n],n2[n];
	for(i=0;i<n;i++)
{
	scanf("%d",&n0[i]);
	n2[i]=0;
}
	n1[0]=n0[0];
	n2[0]++;
	for(i=1;i<n;i++){
	for(j=0,flag=0;j<m&&flag==0;j++){
	if(n0[i]==n1[j])
	flag=1;
	}
	if(flag==1)
	n2[j-1]++;
	else{m++;
	n1[m-1]=n0[i];
	n2[m-1]++;
	}}
	quanp(n0,n1,n2,m,n,0);
}

void quanp(int q0[],int q1[],int q2[],int m,int n,int p)
{	int i,j;
	if(p==n){
	for(i=0;i<n;i++)
	printf("%d ",q0[i]);
	printf("\n");
}
	else{
	for(i=0;i<m;i++){
	if(q2[i]>0){
	q0[p]=q1[i]; 
	q2[i]--;
	quanp(q0,q1,q2,m,n,p+1);
	q2[i]++;
}
	
	}	
}

	
	
}

