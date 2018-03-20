#include<stdio.h>
#include<math.h>
long long reverse(long long,long long);
main(){
	printf("%d",reverse(1838,4));
}

long long reverse(long long num,long long len){
	
	if(len==1)
	return num;
	else
	return num/(long long)pow(10,len-1)+reverse((num%(long long)pow(10,len-1)),len-1)*10;
}
