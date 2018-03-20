#include<stdio.h>
#include<stdlib.h>
char *locatesubstr(char *str1,char *str2);
main(){
	char str1[500];
	char str2[500];
	gets(str1);
	gets(str2);
 
	if(locatesubstr(str1,str2))
	printf("%s",locatesubstr(str1,str2));
	else
	printf("NULL");
	
}
char *locatesubstr(char *str1,char *str2){
	char* chtemp=str2;
	char* kaishibuwei=str1;
	int flag=0;
	while(*str1!='\0'&&flag==0){
		if(*str1==*chtemp){
			str1++;
			chtemp++;
		}
		else
		if(*chtemp!='\0'){
		chtemp=str2;
		str1=kaishibuwei+1;
		kaishibuwei=str1;
		}
		else
		flag=1;
	}
	if(flag==1)
	return kaishibuwei;
	else
	return NULL;
}
