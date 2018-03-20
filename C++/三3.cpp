#include<cstdlib>
#include<iostream>
using namespace std;

class Matrix{
	private:
		int lines,rows;
		int **ptr;
	public:
		Matrix();
		Matrix(int lines,int rows);
		~Matrix();
		Matrix(Matrix& anotherMatrix);
		void init();
		void print();
		Matrix& operator =(const Matrix&);
		friend Matrix operator +(Matrix A1,Matrix A2);
		friend Matrix operator -(Matrix A1,Matrix A2);
};

Matrix::Matrix():lines(0),rows(0){ptr=NULL;};//默认构造 
Matrix::Matrix(int lines,int rows){
			this->lines=lines;
			this->rows=rows;
			ptr=new int *[lines];// 指向一个指针数组 每一个元素 指向 一个 一维数组 
			for(int i=0;i<lines;i++){
				ptr[i]=new int[rows];
				for(int j=0;j<rows;j++){
					ptr[i][j]=0;//
				}
			}
		}
Matrix::~Matrix(){
	for(int j=0;j<rows;j++){
				delete []ptr[j];
			}
	delete []ptr;
}
Matrix::Matrix(Matrix& anotherMatrix){
	lines=anotherMatrix.lines;
	rows=anotherMatrix.rows;
	ptr=new int*[lines] ;
	for(int i=0;i<lines;i++){
				ptr[i]=new int[rows];
				for(int j=0;j<rows;j++){
					ptr[i][j]=anotherMatrix.ptr[i][j];
				}
			}
}

void Matrix::init(){
	for (int i=0;i<lines;i++){
		for (int j=0;j<rows;j++){
			cout<<"please input line "<<i+1<<" row "<<j+1<<endl;
			cin>>ptr[i][j];
		}
	}	
}

void Matrix::print(){
		for(int i=0;i<lines;i++){
		for(int j=0;j<rows;j++){
			cout<<ptr[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}

Matrix& Matrix::operator =(const Matrix& anotherMatrix){
	if(this!=&anotherMatrix){
		
		for(int j=0;j<lines;j++){//删掉原有空间 
				delete []ptr[j];
			}
		delete []ptr;
		lines=anotherMatrix.lines;//复制size 
		rows=anotherMatrix.rows;
		//重新申请和=右边大小一样的空间 并复制
		ptr=new int*[lines];

		for(int i=0;i<lines;i++){
			ptr[i]=new int[rows];
			for(int j=0;j<rows;j++){
				ptr[i][j]=anotherMatrix.ptr[i][j];
			}
		}
	}
	return *this; 
}

Matrix operator +(Matrix A1,Matrix A2){
	Matrix A3;
	if(A1.lines==A2.lines&&A1.rows==A2.rows){
		A3.lines=A1.lines;
		A3.rows=A1.rows;
		A3.ptr=new int*[A3.lines];
		for(int i=0;i<A3.lines;i++){
			A3.ptr[i]=new int[A3.rows];
			for(int j=0;j<A1.rows;j++){
				A3.ptr[i][j]=A1.ptr[i][j]+A2.ptr[i][j];
			}
		}
		return 	A3;
	}
	else{
		cout<<"this two matrix dong have the same size,can not be plus"<<endl;
	}
}

Matrix operator -(Matrix A1,Matrix A2){
	Matrix A3;
	if(A1.lines==A2.lines&&A1.rows==A2.rows){
		A3.lines=A1.lines;
		A3.rows=A2.rows;
		A3.ptr=new int*[A3.lines];
		for(int i=0;i<A3.lines;i++){
			A3.ptr[i]=new int[A3.rows];
			for(int j=0;j<A3.rows;j++){
				A3.ptr[i][j]=A1.ptr[i][j]-A2.ptr[i][j];
			}
		}
		return A3;
	}
	else{
		cout<<"this two matrix dong have the same size,can not be minus"<<endl;
	}
}
 
main(){
	Matrix A3;
	int lines,rows;
	cout<<"input your first matrix'size "<<endl;
	cin>>lines>>rows;
	Matrix A1(lines,rows);
	A1.init();
	cout<<"input your second matrix'size "<<endl;
	cin>>lines>>rows;
	Matrix A2(lines,rows);
	A2.init();
	//以上初始化过程 
	A1.print();
	cout<<endl;
	A2.print();
	cout<<endl;
	//
	A3=A1+A2;
	A3.print();
	A3=A1-A2;
	A3.print();
	//----------------------------
	
	cout<<"input your first matrix'size "<<endl;
	cin>>lines>>rows;
	Matrix *pA1=new Matrix(lines,rows);
	pA1->init();
	cout<<"input your second matrix'size "<<endl;
	cin>>lines>>rows;
	Matrix *pA2=new Matrix(lines,rows);
	pA2->init();
	//以上 初始化 
	Matrix *pA3=new Matrix;
	*pA3=*pA1+*pA2;
	pA3->print();
	*pA3=*pA1-*pA2;
	pA3->print();
	
}
