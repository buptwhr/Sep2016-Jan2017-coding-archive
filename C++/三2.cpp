/*
2017年9月18日 22:12:49 
*/ 
#include<cstdlib>
#include<iostream>
using namespace std;
void init(int matrix[][5]);
void print(int matrix[][5]);
void matrix_sum(int A1[][5],int A2[][5],int A3[][5]);
void matrix_minus(int A1[][5],int A2[][5],int A3[][5]);
main(){
	int (*A1)[5]=new int[4][5];//申请空间 
	int (*A2)[5]=new int[4][5];
	int (*A3)[5]=new int[4][5];
	cout<<"init the first matrix"<<endl;
	init(A1);
	cout<<"init the second matrix"<<endl;
	init(A2);
	cout<<"A1-----"<<endl;
	print(A1);
	cout<<"A2-----"<<endl;
	print(A2);
	matrix_sum(A1,A2,A3);
	cout<<"A1+A2-----"<<endl;
	print(A3);
	matrix_minus(A1,A2,A3);
	cout<<"A1-A2-----"<<endl;
	print(A3); 
	delete []A1;//释放空间 
	delete []A2;
	delete []A3;
}


void init(int matrix[][5]){
	for (int i=0;i<4;i++){
		for (int j=0;j<5;j++){
			cout<<"please input row "<<i+1<<" column "<<j+1<<endl;
			cin>>matrix[i][j];
		}
	}	
}

void print(int matrix[][5]){
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			cout<<matrix[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void matrix_sum(int A1[][5],int A2[][5],int A3[][5]){
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			A3[i][j]=A1[i][j]+A2[i][j];
		}
	}
}

void matrix_minus(int A1[][5],int A2[][5],int A3[][5]){
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			A3[i][j]=A1[i][j]-A2[i][j];
		}
	}
}
