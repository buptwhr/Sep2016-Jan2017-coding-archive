#include<stdio.h>
#include<stdlib.h>
#define Q0 0
#define Q1 1
#define Q2 2
#define Q3 3
#define Q4 4

main(){
	FILE* ptr1,*ptr2;
	int state=Q0;
	int ch;
	ptr1=fopen("p12in.c","r");
	ptr2=fopen("p12out.c","w");
	if(ptr1==NULL||ptr2==NULL){
		printf("Wrong!");
	}
	else{
		while((ch=fgetc(ptr1))!=EOF){
			switch(state){
				case Q0:
					if(ch=='/'){
						state=Q1;
					}
					else{
						fputc(ch,ptr2);
					}
					break;
				case Q1:
					if(ch=='/'){
						state=Q2;
					} 
					else
					if(ch=='*'){
						state=Q3;
					}
					else{
						fputc('/',ptr2);
						fputc(ch,ptr2);
						state=Q0;
					}
					break;
				case Q2:
					if(ch=='\n'){
						state=Q0;
						fputc(ch,ptr2);
					}
					
					break;
				case Q3:
					if(ch=='*'){
						state=Q4;
					}
					break;
				case Q4:
					if(ch=='/'){
						state=Q0;
					}
					else{
						state=Q3;
					}
					break;
			}
		}
		fclose(ptr1);
		fclose(ptr2);
	}
}
