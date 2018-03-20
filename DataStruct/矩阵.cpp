#include<iostream>
#define MAXSIZE 1000
using namespace std;

typedef struct Triple{
	int i,j;//非0元素的位置 
	int n;//非零元素 
}Triple; 
class sMatrix{
	private:
		Triple t[MAXSIZE];
		int m,n,num;//矩阵长宽 非零元素个数 
	public:
		sMatrix();
		sMatrix(int,int);
		void dataRead();
		void print(); 
		sMatrix Trans(); 
		friend int plus1(sMatrix,sMatrix,sMatrix* &);
		friend int multiply(sMatrix m1,sMatrix m2,sMatrix &m3);
};
sMatrix::sMatrix(int m,int n){//构造长宽矩阵 
	this->m=m;
	this->n=n;
}
sMatrix::sMatrix(){
	;
}
void sMatrix::dataRead(){
	num=0;
	cin>>num;//读非零元素个数 
	for(int i=0;i<num;i++){
		cin>>t[i].i>>t[i].j>>t[i].n;
	}	
}
void sMatrix::print(){
	int Tmark=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(Tmark<num&&t[Tmark].i==i&&t[Tmark].j==j){
				cout<<t[Tmark].n<<" ";
				Tmark++;
			}
			else{
				cout<<0<<" ";
			}
		}
		cout<<endl;
	}
}

sMatrix sMatrix::Trans(){
	sMatrix TMatrix(n,m);//构造一个转置后的矩阵size 
	TMatrix.num=num;
	int nzn[n+1];//non-zero's num  start with subscrip 1
	int sp[n+1];//start position  start with subscrip 1
	for(int i=1;i<=n;i++)
	nzn[i]=0;
	for(int i=0;i<num;i++){
		nzn[t[i].j]++;
	}
	sp[1]=0;
	for(int i=2;i<=n;i++){
		sp[i]=sp[i-1]+nzn[i-1];
	}
	for(int i=0;i<num;i++){
		TMatrix.t[sp[t[i].j]].i=t[i].j;
		TMatrix.t[sp[t[i].j]].j=t[i].i;
		TMatrix.t[sp[t[i].j]].n=t[i].n;	
		sp[t[i].j]++;
	}
	return TMatrix;
}
int plus1(sMatrix m1,sMatrix m2,sMatrix* &);
int multiply(sMatrix m1,sMatrix m2,sMatrix &m3);

main(){
	int m,n;
	cout<<"输入矩阵的行和列"<<endl; 
	cin>>m>>n;
	sMatrix m1(m,n);
	cout<<"输入非零元素个数，按照行，列，数值的顺序输入"<<endl; 
	m1.dataRead();
	cout<<"输入矩阵的行和列"<<endl; 
	cin>>m>>n;
	sMatrix m2(m,n);
	cout<<"输入非零元素个数，按照行，列，数值的顺序输入"<<endl; 
	m2.dataRead();
	cout<<"矩阵1为"<<endl; 
	m1.print();
	cout<<"矩阵2为"<<endl;
	m2.print();
	sMatrix m3;
	if(multiply(m1,m2,m3)!=0){
		cout<<"矩阵相乘"<<endl;
		m3.print();
	}
	else
	cout<<"两矩阵不能相乘"<<endl;
	sMatrix *m4;
	if(plus1(m1,m2,m4)!=0){
		cout<<"矩阵相加"<<endl;
		m4->print();
	}
	else{
		cout<<"两矩阵不能相加"<<endl; 
	}


}

int plus1(sMatrix m1,sMatrix m2,sMatrix* &m3){
	if(m1.m==m2.m&&m1.n==m2.n){
		m3=new sMatrix(m1.m,m1.n);
		
		m3->num=0;
		int i=0,j=0,k=0;//分别在m1,m2，m3位移
		while(i<m1.num&&j<m2.num){
			if(m1.t[i].i>m2.t[j].i){
				m3->t[k]=m2.t[j];
				m3->num++;
				j++;
				k++;
			}
			else if(m1.t[i].i<m2.t[j].i){
				m3->t[k]=m1.t[i];
				m3->num++;
				i++;
				k++;
			}
			else{
				if(m1.t[i].j>m2.t[j].j){
					m3->t[k]=m2.t[j];
					m3->num++;
					j++;
					k++;
				}
				else if(m1.t[i].j<m2.t[j].j){
					m3->t[k]=m1.t[i];
					m3->num++;
					i++;
					k++;
				} 
				else{
					m3->t[k]=m1.t[i];
					m3->t[k].n+=m2.t[j].n;
					m3->num++;
					i++;j++;k++;
				}				
			}
		}
		if(i==m1.num){
			while(j<m2.num){
				m3->t[k]=m2.t[j];
				m3->num++;
				j++;k++;
			}
		}
		if(j==m2.num){
			while(i<m1.num){
				m3->t[k]=m1.t[i];
				m3->num++;
				i++;
				k++;
			}
		}
	
		return 1;
	}
	else
	return 0;
}

int multiply(sMatrix m1,sMatrix m2,sMatrix &m3){
	if(m1.n==m2.m){
		m3.m=m1.m;
		m3.n=m2.n;
		m2=m2.Trans();
		int mark1=0,mark2=0,mark3=0;//在m1,m2上的位移标识 
		int temp=0;//临时存放m2每个元素的值 
		//////////////position数组 存放A矩阵每行在三元组里的起始位置
		int nzn[(m1.m)+1];//non-zero's num  start with subscrip 1
		int sp[(m1.m)+1];//start position  start with subscrip 1
		for(int i=1;i<=m1.m;i++)//统计每行有几个非零元素
		nzn[i]=0;
		for(int i=0;i<m1.num;i++){	
			nzn[m1.t[i].i]++;
		}
			sp[1]=0;
		for(int i=2;i<=m1.m;i++){
			sp[i]=sp[i-1]+nzn[i-1];
		}
		//////////////////////
		
		
		for(int i=1;i<=m3.m;i++){
			for(int j=1;j<=m3.n;j++){
				while(m1.t[mark1].i==i&&m2.t[mark2].i==j){
					if(m1.t[mark1].j==m2.t[mark2].j){
						temp+=(m1.t[mark1].n*m2.t[mark2].n);
						mark1++;mark2++;
					}
					else{
						if(m1.t[mark1].j<m2.t[mark2].j)
						mark1++;
						if(m1.t[mark1].j>m2.t[mark2].j)
						mark2++;
					}
				}
				m3.t[mark3].i=i;
				m3.t[mark3].j=j;
				m3.t[mark3].n=temp;
				temp=0;
				mark3++;
				m3.num++;
				if(j==m3.n)
				mark1=sp[i+1];
				else
				mark1=sp[i];
			}
			mark2=0;
		} 
		
		return 1;
		
	}
	else{
		return 0;
	}
}
