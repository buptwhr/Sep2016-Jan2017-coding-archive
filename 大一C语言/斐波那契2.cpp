#include <stdio.h>

int main(){
	int i,n;
	double fenzi=2,fenmu=1,sum;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		
		
		sum=sum+fenzi/fenmu;
		double temp;
		temp=fenmu;
		fenmu=fenzi;
		fenzi=fenzi+temp;
	}
	printf("%.2lf",sum);
} 
