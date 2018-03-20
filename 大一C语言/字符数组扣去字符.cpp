#include<stdio.h>
#include<string.h>
int len;
void delcharfun(char str[],char ch);
main(){
	char str[100],ch;
	scanf("%s",str);
	getchar();
	scanf("%c",&ch);
	delcharfun(str,ch);

	printf("%s",str);
}

void delcharfun(char str[],char ch){
	int i=0,j;
	len=strlen(str);
	
	while(i<=len-1){
		if(str[i]==ch){
			for(j=i;j<=len-1;j++){
				str[j]=str[j+1];
			}
			len--;
		}
		else
		i++;
		
	}

}
