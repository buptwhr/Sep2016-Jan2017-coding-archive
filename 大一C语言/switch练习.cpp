#include <stdio.h>


int main(){
	int mark;
	scanf("%d",&mark);
	switch(mark/10)
	{
		case 9:case 10:
		printf("A");break;
		case 8:
		printf("B");break;
		case 7:
		printf("C");break;
		case 6:
		printf("D");break;
		default:
		printf("E");
	}
}
