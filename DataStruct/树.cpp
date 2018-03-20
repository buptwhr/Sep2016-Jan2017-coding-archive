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

queue<char> inputPre();//读入先序 
Node* prePlusIn(queue<char> q,string s);//根据先序中序生成树 
main(){
	int c;
	cout<<"1.先序遍历输入 2.线序中序输入"<<endl; 
	cin>>c;
	Node* t;
		switch(c){
			case 1:
				cout<<"输入先序序列，空结点用*表示"<<endl;
				t=pre_init();
				break;
			case 2:
				cout<<"输入先序，中序序列，用两序列用回车分隔"<<endl; 
				queue<char> q;
				q=inputPre();
				string s;
				cin>>s;
				t=prePlusIn(q,s);
				break;
		}
		
	indentation(t,0);
	
	cout<<endl<<"数的叶子节点数目"<<leaf_num(t)<<endl; 
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


int leaf_num(Node* T){//计算叶子节点数目 
	static int num=0;//静态变量 
	if(T==NULL) return 0;//递归遍历 
	if(T->lchild)
	leaf_num(T->lchild);
	if(T->rchild)
	leaf_num(T->rchild);
	if((!T->lchild)&&(!T->rchild)){//满足条件 为叶子节点 自加 
		num++;
	}
	return num;
}

void indentation(Node* T,int lines=0){//凹入表  lines代表当前节点的深度 
	if(T==NULL)
	return;
	for(int i=0;i<lines;i++){//根据深度输出空格 
		cout<<"  ";
	}
	cout<<T->data;
	for(int i=0;i<(20-lines);i++){//输出横线 
		cout<<"--";
	}
	cout<<endl;
	if(T->lchild)//递归 
	indentation(T->lchild,lines+1);
	if(T->rchild)
	indentation(T->rchild,lines+1);
}



queue<char> inputPre(){//读入线序序列 存入一个队列queue中 
	queue<char> q;
	string pre; 
	cin>>pre;//读入字符串 
	for(int i=0;i<pre.length();i++){//遍历字符串 放入队列 
		q.push(pre[i]);
	}
	return q;
}


Node* prePlusIn(queue<char> p,string s){
	static queue<char> q=p;//线序序列设成静态变量 
	if(q.size()!=0){
		char c;
		string left;
		string right;
		c=q.front();
		q.pop();//线序的第一个 一定是当前节点数据 
		
		Node* T=new Node;
		T->data=c;
		
		int pos=s.find(c);//在中序中找到当前节点，并把节点前后 分为两个字符串 left right 
		left=s.substr(0,pos);
		right=s.substr(pos+1);
		
		T->lchild=left.size()>0?prePlusIn(q,left):NULL;//递归过程 ，如果中序中，该节点左边还有序列，说明有左子树，而线序的第一个，正是左子树的根节点 
		T->rchild=right.size()>0?prePlusIn(q,right):NULL;
		return T;
	}
}

Node* pre_copy(Node *n){//复制一棵树 
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
int post_height(Node* T){//求数的高度 
	if(T==NULL)
	return 0;
	else{
		int h1=post_height(T->lchild)+1;
		int h2=post_height(T->rchild)+1;
		return h1>h2?h1:h2;
	}
}
