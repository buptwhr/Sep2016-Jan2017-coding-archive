#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int judge(int[],int ,int);
void quanp(int q[],int n,int p);
void swap(int*a,int*b);
main()
{	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	quanp(arr,n,0);
}
void quanp(int q[],int n,int p)
{	if(p==n)
	{int i;
	for(i=0;i<n;i++)
	printf("%d",q[i]);
	printf("\n");
}
	else{
	int i;
	for(i=p;i<n;i++){
	if(i==p||judge(q,p,i)!=0){
	swap(&q[i],&q[p]);
	quanp(q,n,p+1);
	swap(&q[i],&q[p]);}

}}}

void swap(int*a,int*b)
{	int p;
	p=*a;
	*a=*b;
	*b=p;
}
int judge(int m[],int p,int i){
	int flag=1;
	for(;flag==1&&p<i;p++){
	if(m[p]==m[i])
	flag=0;
}
	return	flag;
	}	

