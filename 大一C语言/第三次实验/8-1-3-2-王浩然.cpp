#include<stdio.h>
#include<stdlib.h>
#define initial 0
#define statei 1
#define statein 2
#define stateint 3
#define intspace 4
#define name 5
#define named 6
#define equality 7
#define number 8
#define semicolons 9
#define YES 10
#define NO 11
main(){
	char ch;
	int state=initial;
	printf("Please input a string:");
	ch=getchar();
	for(;1;ch=getchar()){
		switch(state){
			case initial:
				if(ch=='i')
				state=statei;
				else if(ch==' ')
				; 
				else
				{
					printf("NO");
					return 0;
				}
				
				break;
			case statei:
				if(ch=='n')
				state=statein;
				else
				{
					printf("NO");
					return 0;
				}
				break;
			case statein:
				if(ch=='t')
				state=stateint;
				else
				{
					printf("NO");
					return 0;
				}
				break;
			case stateint:
				if(ch==' ')
				state=intspace;
				else
				{
					printf("NO");
					return 0;
				}
				break;
			case intspace:
				if(ch=='_'||(ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
				state=name;
				else
				if(ch==' ')
				;
				else
				{
					printf("NO");
					return 0;
				}
				break;
			case name:
				if(ch=='=')
				state=equality;
				else
				if(ch=='_'||(ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||(ch>='0'&&ch<='9'))
				;
				else
				if(ch==' ')
				state=named;
				else 
				if(ch==';')
				state=semicolons;
				else
				{
					printf("NO");
					return 0;
				}
				break;
			case named:
				if(ch=='=')
				state=equality;
				else
				if(ch==';')
				state=semicolons;
				else
				if(ch==',')
				state=intspace;
				else
				if(ch==' ')
				;
				else
				{
					printf("NO");
					return 0;
				}
				break;
			case equality:
				if(ch==' ')
				;
				else
				if(ch>='0'&&ch<='9')
				state=number;
				else
				{
					printf("NO");
					return 0;
				}
				break;
			case number:
				if(ch>='0'&&ch<='9')
				;
				else
				if(ch==' ')
				state=named;
				else
				if(ch==',')
				state=intspace;
				else
				if(ch==';')
				state=semicolons;
				else
				{
					printf("NO");
					return 0;
				}
				break;
			case semicolons:
				if(ch=='\n')
				{
					printf("YES");
					return 0;
				}
				else
				{
					printf("NO");
					return 0;
				}
				break;
				}
		}
		
	}

