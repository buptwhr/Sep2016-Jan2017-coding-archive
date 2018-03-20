#include<stdio.h>

main(){
	FILE* ptr=NULL;
	int capital=0,lowercase=0,digit=0,others=0;
	int line=1,longest=0,shortest=999999999,currentLine=0;
	int CAPITAL[26]={0},LOWERCASE[26]={0};
	int c;
	ptr=fopen("p1.txt","r");
	if(ptr==NULL){
		printf("Wrong!");
	}
	else{
		while((c=fgetc(ptr))!=EOF){//not end yet
			if(c>='A'&&c<='Z'){
				capital++;
				CAPITAL[c-'A']++;
				currentLine++;
			}
			else
			if(c>='a'&&c<='z'){
				lowercase++;
				LOWERCASE[c-'a']++;
				currentLine++;
			}
			else
			if(c>='0'&&c<='9'){
				digit++;
				currentLine++;
			}
			else{
				others++;
				if(c==10){
					longest=currentLine>longest?currentLine:longest;
					shortest=currentLine<shortest?currentLine:shortest;//比较 最短 
					currentLine=0;
					line++;
				}
				else{
					currentLine++;
				}
			}
		}
	longest=currentLine>longest?currentLine:longest;
	shortest=currentLine<shortest?currentLine:shortest;//把最后一行比较一下 
	printf("The result is:\nTask1:\n");
	printf("capital:%d\nlowercase:%d\ndigit:%d\nothers:%d\n\n",capital,lowercase,digit,others);
	printf("Task2:\nline:%d\n%d characters in max line.\n%d characters in min line.\n\n",line,longest,shortest);
	printf("Task3:\nCAPITAL:\n");
	for(int n=0;n<26;n++){
		printf("%c:%d",n+'A',CAPITAL[n]);
		if((n+1)%4==0){
			printf("\n"); 
		}
		else{
			printf(" ");
		}
	}
	printf("\nLOWERCASE:\n");
	for(int n=0;n<26;n++){
		printf("%c:%d",n+'a',LOWERCASE[n]);
		if((n+1)%4==0){
			printf("\n"); 
		}
		else{
			printf(" ");
		}
	}
	
	}
	
	
	fclose(ptr);
}


