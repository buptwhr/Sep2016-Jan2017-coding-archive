#include<stdio.h>
#include<string.h>

main(){
	int num,i,max=0,min=100;
	double sum=0,average;
	scanf("%d",&num);
	int score[num];
	for (i=0;i<num;i++)
	scanf("%d",&score[i]);
	for(i=0;i<num;i++){
		if(score[i]>=max)
		max=score[i];
		
		if(score[i]<=min)
		min=score[i];
		sum=sum+score[i];
	}
	printf("%.2lf %d %d",sum/num,max,min);
}
