#include<iostream>
#include<cstdlib>

using namespace std;
void init(int array[][5]);
void print(int array[][5]);
void array_plus(int A1[][5],int A2[][5],int A3[][5]);
void array_minus(int A1[][5],int A2[][5],int A3[][5]);
main(){
	int A1[4][5],A2[4][5],A3[4][5];
	cout<<"input the first matrix"<<endl;
	init(A1);
	cout<<"input the second matrix"<<endl;
	init(A2);
	array_plus(A1,A2,A3);
	print(A3);
}

void init(int array[][5]){//初始化 
	for (int i=0;i<4;i++){
		for (int j=0;j<5;j++){
			cout<<"please input row "<<i+1<<" column "<<j+1<<endl;
			cin>>array[i][j];
		}
	}	
}

void print(int array[][5]){//打印 
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			cout<<array[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void array_plus(int A1[][5],int A2[][5],int A3[][5]){//相加 
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			A3[i][j]=A1[i][j]+A2[i][j];
		}
	}

}

void array_minus(int A1[][5],int A2[][5],int A3[][5]){
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			A3[i][j]=A1[i][j]-A2[i][j];
		}
	}
}
