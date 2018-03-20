#include<stdio.h>

main(){
	char sentence[10000];
	gets(sentence); 
	char *word[1001];
	char* sPtr=sentence;
	char ** wPtr=word;
	int i=1;
	*wPtr=sentence;
	for(;*sPtr;sPtr++){
		if(*sPtr==' '){
		*sPtr='\0';
		*(wPtr+i++)=sPtr+1;
	}
	}
	for(int j=0;j<i;j++)
	puts(*(wPtr+j));
	
}
