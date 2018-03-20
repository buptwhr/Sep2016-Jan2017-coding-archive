#include<iostream>
#define MAXSIZE 1000
using namespace std;

typedef struct Triple{
	int i,j;//��0Ԫ�ص�λ�� 
	int n;//����Ԫ�� 
}Triple; 
class sMatrix{
	private:
		Triple t[MAXSIZE];
		int m,n,num;//���󳤿� ����Ԫ�ظ��� 
	public:
		sMatrix();
		sMatrix(int,int);
		void dataRead();
		void print(); 
		sMatrix Trans(); 
		friend int plus1(sMatrix,sMatrix,sMatrix* &);
		friend int multiply(sMatrix m1,sMatrix m2,sMatrix &m3);
};
sMatrix::sMatrix(int m,int n){//���쳤����� 
	this->m=m;
	this->n=n;
}
sMatrix::sMatrix(){
	;
}
void sMatrix::dataRead(){
	num=0;
	cin>>num;//������Ԫ�ظ��� 
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
	sMatrix TMatrix(n,m);//����һ��ת�ú�ľ���size 
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
	cout<<"���������к���"<<endl; 
	cin>>m>>n;
	sMatrix m1(m,n);
	cout<<"�������Ԫ�ظ����������У��У���ֵ��˳������"<<endl; 
	m1.dataRead();
	cout<<"���������к���"<<endl; 
	cin>>m>>n;
	sMatrix m2(m,n);
	cout<<"�������Ԫ�ظ����������У��У���ֵ��˳������"<<endl; 
	m2.dataRead();
	cout<<"����1Ϊ"<<endl; 
	m1.print();
	cout<<"����2Ϊ"<<endl;
	m2.print();
	sMatrix m3;
	if(multiply(m1,m2,m3)!=0){
		cout<<"�������"<<endl;
		m3.print();
	}
	else
	cout<<"�����������"<<endl;
	sMatrix *m4;
	if(plus1(m1,m2,m4)!=0){
		cout<<"�������"<<endl;
		m4->print();
	}
	else{
		cout<<"�����������"<<endl; 
	}


}

int plus1(sMatrix m1,sMatrix m2,sMatrix* &m3){
	if(m1.m==m2.m&&m1.n==m2.n){
		m3=new sMatrix(m1.m,m1.n);
		
		m3->num=0;
		int i=0,j=0,k=0;//�ֱ���m1,m2��m3λ��
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
		int mark1=0,mark2=0,mark3=0;//��m1,m2�ϵ�λ�Ʊ�ʶ 
		int temp=0;//��ʱ���m2ÿ��Ԫ�ص�ֵ 
		//////////////position���� ���A����ÿ������Ԫ�������ʼλ��
		int nzn[(m1.m)+1];//non-zero's num  start with subscrip 1
		int sp[(m1.m)+1];//start position  start with subscrip 1
		for(int i=1;i<=m1.m;i++)//ͳ��ÿ���м�������Ԫ��
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
