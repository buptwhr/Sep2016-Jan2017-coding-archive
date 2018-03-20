#include<cstdio>
#include<iostream>
#include<stack>
#define infinite INT_MAX
#define MaxVertex 20
using namespace std;
int count = 0;
typedef enum{TRUE,FALSE}Status;
typedef struct Edge{
	int num;
	Edge* next;
}Edge;
typedef struct VNode{
	char data;
	Edge* firstedge;
}VNode;

class Graph{
	private:
		int vertexnum,edgenum;
		VNode vertex[MaxVertex+1];//0�±겻�� 
		void DFS(int,int,int,int,Status*,stack<int>);
	public:
		Graph();
		void output();
		void simplepath(int length,int from,int to); 
};
Graph::Graph(){
	cout<<"����ڵ�ͱߵ�����"<<endl;
	cin>>vertexnum>>edgenum;
	for(int i=1;i<=vertexnum;i++)
	vertex[i].firstedge=NULL;
	cout<<"�����ڽӽڵ㣬�ÿո�ָ�������ͼ�����ظ�����"<<endl;
	int v1,v2;
	Edge* p1,*p2,*temp;
	for(int i=0;i<edgenum;i++){//ͷ�巨��v2�ӵ�v1���棬v1�ӵ�v2���� 
		cin>>v1>>v2;
		p1=new Edge;
		p2=new Edge;
		p1->num=v1;
		p2->num=v2;
		temp=vertex[v1].firstedge;
		vertex[v1].firstedge=p2;
		p2->next=temp;
		temp=vertex[v2].firstedge;
		vertex[v2].firstedge=p1;
		p1->next=temp;	
	} 
}
void Graph::output(){
	Edge* p;
	for(int i=1;i<=vertexnum;i++){
		cout<<i<<" ";
		p=vertex[i].firstedge;
		while(p){
			cout<<p->num<<" ";
			p=p->next;
		}
		cout<<endl;
	}
}
void Graph::simplepath(int length,int from,int to){
	Status visit[vertexnum+1];//��¼�Ƿ������ 0�±겻��
	for(int i=1;i<=vertexnum;i++)
	visit[i]=FALSE;
	stack<int> q;
	visit[from]=TRUE;
	DFS(length,0,from,to,visit,q);
}
void Graph::DFS(int length,int currentlength,int from,int to,Status* visit,stack<int> q){//������� 
	Edge* p;
	stack<int> temp;
	if(currentlength==length&&from==to){
		count++;
		while(q.size()!=0){
			temp.push(q.top());
			q.pop();
		}
		while(temp.size()!=0){
			q.push(temp.top());
			cout<<temp.top()<<" ";
			temp.pop();
		}
		cout<<to<<endl;
	}
	else if(currentlength<length){
		p=vertex[from].firstedge;
		while(p){
			if(visit[p->num]==FALSE){
				visit[p->num]=TRUE;//�����ʱ��ȥ 
				q.push(from);
				
				DFS(length,currentlength+1,p->num,to,visit,q);
				
				visit[p->num]=FALSE;//��ԭ��� 
				q.pop();
			}
			p=p->next;
		}
	}
}

main(){
	Graph g;
	cout<<endl;
	cout<<"������ʼ����±� �� ����"<<endl;
	int i,j,w;
	cin>>i>>j>>w; 
	g.simplepath(w,i,j);
	cout<<"����"<<count<<"����·��"<<endl; 
}
