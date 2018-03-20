#include<stdio.h>
#define row1 3
#define col1 4
#define row2 4
#define col2 3
void inputarrayA(int A[][col1]);
void inputarrayB(int B[][col2]);
void multiply(int A[][col1],int B[][col2],int C[][col2]);
main(){
	int A[row1][col1],B[row2][col2],C[row1][col2];
	inputarrayA(A);
	inputarrayB(B);
	multiply(A,B,C);
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			printf("%d ",C[i][j]);
		printf("\n");
	}
}
void inputarrayA(int A[][col1]){
	int i,j;
	for (i=0;i<row1;i++)
		for (j=0;j<col1;j++)
		scanf("%d",&A[i][j]);
}
void inputarrayB(int B[][col2]){
	int i,j;
	for (i=0;i<row2;i++)
		for (j=0;j<col2;j++)
		scanf("%d",&B[i][j]);
}
void multiply(int A[][col1],int B[][col2],int C[][col2]){
	int i,j,k;
	for (i=0;i<row1;i++)
		for (j=0;j<col2;j++){
			C[i][j]=0;
			for(k=0;k<col1;k++)
				C[i][j]+=A[i][k]*B[k][j];
		}
}


