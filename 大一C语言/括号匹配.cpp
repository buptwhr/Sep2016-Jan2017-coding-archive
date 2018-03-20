#include<stdio.h>

main(){
	char zhanqu[100];
	char element;
	int i=0,flag=0;
	scanf("%c",&element);
	while(element!='#'&&flag==0){
		if(element=='('){
		zhanqu[i]=element;
		i++;
	}
		else
		if(element==')'){
			if(zhanqu[i-1]=='(')
			i--;
			else
			flag=1;
		}
		
		
		scanf("%c",&element);
	} 
	if(i==0&&flag==0)
	printf("YES");
	else
	
	printf("NO");
}
