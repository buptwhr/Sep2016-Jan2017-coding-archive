#include<cstdio>
#include<iostream>

#include<queue>
#include<string>
using namespace std;

typedef struct Node{
	char data;
	Node* lchild;// 
	Node* rchild;//
}Node; 

Node* pre_copy(Node *n);
int post_height(Node* T); 
Node* pre_init();
int leaf_num(Node* T);
void indentation(Node* T,int lines);

queue<char> inputPre();//�������� 
Node* prePlusIn(queue<char> q,string s);//������������������ 
main(){
	int c;
	cout<<"1.����������� 2.������������"<<endl; 
	cin>>c;
	Node* t;
		switch(c){
			case 1:
				cout<<"�����������У��ս����*��ʾ"<<endl;
				t=pre_init();
				break;
			case 2:
				cout<<"���������������У����������ûس��ָ�"<<endl; 
				queue<char> q;
				q=inputPre();
				string s;
				cin>>s;
				t=prePlusIn(q,s);
				break;
		}
		
	indentation(t,0);
	
	cout<<endl<<"����Ҷ�ӽڵ���Ŀ"<<leaf_num(t)<<endl; 
}

Node* pre_init(){
	char ch;
	cin>>ch;
	if(ch=='*'){
		return NULL;
	}
	else{
		Node* T=new Node;
		T->data=ch;
		T->lchild=pre_init();
		T->rchild=pre_init();
		return T;
	} 
} 


int leaf_num(Node* T){//����Ҷ�ӽڵ���Ŀ 
	static int num=0;//��̬���� 
	if(T==NULL) return 0;//�ݹ���� 
	if(T->lchild)
	leaf_num(T->lchild);
	if(T->rchild)
	leaf_num(T->rchild);
	if((!T->lchild)&&(!T->rchild)){//�������� ΪҶ�ӽڵ� �Լ� 
		num++;
	}
	return num;
}

void indentation(Node* T,int lines=0){//�����  lines����ǰ�ڵ����� 
	if(T==NULL)
	return;
	for(int i=0;i<lines;i++){//�����������ո� 
		cout<<"  ";
	}
	cout<<T->data;
	for(int i=0;i<(20-lines);i++){//������� 
		cout<<"--";
	}
	cout<<endl;
	if(T->lchild)//�ݹ� 
	indentation(T->lchild,lines+1);
	if(T->rchild)
	indentation(T->rchild,lines+1);
}



queue<char> inputPre(){//������������ ����һ������queue�� 
	queue<char> q;
	string pre; 
	cin>>pre;//�����ַ��� 
	for(int i=0;i<pre.length();i++){//�����ַ��� ������� 
		q.push(pre[i]);
	}
	return q;
}


Node* prePlusIn(queue<char> p,string s){
	static queue<char> q=p;//����������ɾ�̬���� 
	if(q.size()!=0){
		char c;
		string left;
		string right;
		c=q.front();
		q.pop();//����ĵ�һ�� һ���ǵ�ǰ�ڵ����� 
		
		Node* T=new Node;
		T->data=c;
		
		int pos=s.find(c);//���������ҵ���ǰ�ڵ㣬���ѽڵ�ǰ�� ��Ϊ�����ַ��� left right 
		left=s.substr(0,pos);
		right=s.substr(pos+1);
		
		T->lchild=left.size()>0?prePlusIn(q,left):NULL;//�ݹ���� ����������У��ýڵ���߻������У�˵������������������ĵ�һ���������������ĸ��ڵ� 
		T->rchild=right.size()>0?prePlusIn(q,right):NULL;
		return T;
	}
}

Node* pre_copy(Node *n){//����һ���� 
	if(n==NULL)
	return NULL;
	else{
		Node* newNode=new Node;
		newNode->data=n->data;
		newNode->lchild=pre_copy(n->lchild);
		newNode->rchild=pre_copy(n->rchild);
		return newNode; 
	}
} 
int post_height(Node* T){//�����ĸ߶� 
	if(T==NULL)
	return 0;
	else{
		int h1=post_height(T->lchild)+1;
		int h2=post_height(T->rchild)+1;
		return h1>h2?h1:h2;
	}
}
