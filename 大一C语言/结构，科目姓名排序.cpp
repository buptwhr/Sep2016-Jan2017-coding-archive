#include<stdio.h>
#include<string.h>
struct student{
	char name[21];
	int score;
};
typedef struct student Student;
void sort(Student xuesheng[],int n);
main(){
	int n,i=0,j=0;
	char ch;
	scanf("%d",&n);
	Student xuesheng[n];
	getchar();
	scanf("%c",&ch);
	xuesheng[i].score=0;
	while(i<n){
		if(ch>='0'&&ch<='9'){
		xuesheng[i].name[j-1]='\0';
		xuesheng[i].score=xuesheng[i].score*10+(ch-'0');
	}
		else{
		if(ch=='\n'){
			i++;
			j=0;
			if(i<n)
			xuesheng[i].score=0;
		}
		else{	xuesheng[i].name[j]=ch;
		j++;
		}
	
	}
		
		if(i<n)
		scanf("%c",&ch);
	}
	sort(xuesheng,n);
	puts(xuesheng[0].name);
	printf("%d",xuesheng[0].score);
	for(int m=1;m<n;m++){
		printf("\n\n");
		puts(xuesheng[m].name);
		printf("%d",xuesheng[m].score);
	}
	
}

void sort(Student xuesheng[],int n){
	Student temp;
	for(int i=0;i<n;i++)
	for(int j=0;j<n-1;j++){
		if(xuesheng[j].score<xuesheng[j+1].score){
			temp=xuesheng[j];
			xuesheng[j]=xuesheng[j+1];
			xuesheng[j+1]=temp;
		}
		else
		if(xuesheng[j].score==xuesheng[j+1].score){
			if(strcmp(xuesheng[j].name,xuesheng[j+1].name)>0){
			temp=xuesheng[j];
			xuesheng[j]=xuesheng[j+1];
			xuesheng[j+1]=temp;
			}
		}
	}
}


