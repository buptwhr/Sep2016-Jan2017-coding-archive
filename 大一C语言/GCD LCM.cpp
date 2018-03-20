#include <stdio.h>
int GCD(int a,int b);
int LCM(int a,int b);
int min(int,int);

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d %d",GCD(a,b),LCM(a,b));
}

int GCD(int a,int b){  //最大公因数 
	int i,mininum,gcd;
	mininum=min(a,b);
	for(i=1;i<=mininum;i++)
	{
		if(a%i==0&&b%i==0)
		gcd=i;
	}
	return gcd;
}
int LCM(int a,int b){  //最小公倍数 
	return a*b/GCD(a,b);
}
int min(int a,int b){
	if(a<=b)
	return a;
	else
	return b;
}
