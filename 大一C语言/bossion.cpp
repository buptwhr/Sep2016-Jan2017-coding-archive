#include <stdio.h>
#include <math.h>
#include <time.h>
#include<stdlib.h>
double U_Random();
int possion();
 
 
main()
{
        srand( (unsigned)time( NULL )) ;
        int num[100]={0};
         for(int i=0;i<10000;i++){
         	num[possion()]++;
		 }
		 for(int i=0;i<=99;i++){
		 	printf("%d个数%d\n",i,num[i]);
		 }
 
}

int possion() 
{
        int Lambda = 4, k = 0;
        long double p = 1.0;
        long double l=exp(-Lambda);
        
        while (p>=l)
        {
                double u = U_Random();
                p *= u;
                k++;
        }
        return k-1;
}

double U_Random()   /* 产生一个0~1之间的随机数 */
{
        double f;
        
        f = (float)(rand() % 100);
        /* printf("%fn",f); */
        return (f+1)/100;
}
