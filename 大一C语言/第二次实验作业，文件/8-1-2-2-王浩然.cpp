#include<stdio.h>
#include<stdlib.h>
void commentDelete(const char* inputFileName,const char* outputFileName);
main(){
	commentDelete("p12in.c","p12out.c");
} 
void commentDelete(const char* inputFileName,const char* outputFileName){
	FILE* ptr1=NULL,*ptr2=NULL;
	ptr1=fopen(inputFileName,"r");
	ptr2=fopen(outputFileName,"w");
	if(ptr1==NULL||ptr2==NULL){
		printf("Wrong!");
	}
	else{
		int c;
		int flag=0; //0������1�Ѿ���һ����/����2 A��ע�ͣ�3 B��ע�� ,4 /**״̬ 
		while((c=fgetc(ptr1))!=EOF){
			if(flag==0){
				if(c=='/'){
					flag=1;
				}
				else{
					fputc(c,ptr2);
				}
			}
			else
			if(flag==1){
				if(c=='/'){
					flag=2;
				}
				else
				if(c=='*'){
					flag=3;
				}
				else{
					flag=0;
					fputc('/',ptr2);
					fputc(c,ptr2);
				}
			}
			else
			if(flag==2){
				if(c==10){
					flag=0;
					fputc(c,ptr2);
				}
			}
			else
			if(flag==3){
				if(c=='*'){
					flag=4;
				}
			}
			else
			if(flag==4){
				if(c=='/'){
					flag=0;
				}
				else{
					flag=3;
				}
			} 
			
			
		}
	}
	fclose(ptr1);
	fclose(ptr2);
}
