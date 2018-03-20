#include <stdio.h>
#include<string.h> 
#include<stdlib.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    double result;
    double score[n];
    double xuefen[n];
    for(int i=0;i<n;i++){
	scanf("%lf",&score[i]);
    scanf("%lf",&xuefen[i]);
}
	double sum_xuefen=0;
	for(int i=0;i<n;i++)
	sum_xuefen+=xuefen[i];
	double GPA=0;
	for(int i=0;i<n;i++){
		GPA=GPA+score[i]*xuefen[i]/sum_xuefen;
	}
	printf("%lf",GPA);
	system("pause") ;
}

