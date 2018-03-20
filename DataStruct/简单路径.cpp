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
		VNode vertex[MaxVertex+1];//0下标不用 
		void DFS(int,int,int,int,Status*,stack<int>);
	public:
		Graph();
		void output();
		void simplepath(int length,int from,int to); 
};
Graph::Graph(){
	cout<<"输入节点和边的数量"<<endl;
	cin>>vertexnum>>edgenum;
	for(int i=1;i<=vertexnum;i++)
	vertex[i].firstedge=NULL;
	cout<<"输入邻接节点，用空格分隔，无向图不用重复输入"<<endl;
	int v1,v2;
	Edge* p1,*p2,*temp;
	for(int i=0;i<edgenum;i++){//头插法，v2接到v1后面，v1接到v2后面 
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
	Status visit[vertexnum+1];//记录是否遍历过 0下标不用
	for(int i=1;i<=vertexnum;i++)
	visit[i]=FALSE;
	stack<int> q;
	visit[from]=TRUE;
	DFS(length,0,from,to,visit,q);
}
void Graph::DFS(int length,int currentlength,int from,int to,Status* visit,stack<int> q){//深度优先 
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
				visit[p->num]=TRUE;//结点临时进去 
				q.push(from);
				
				DFS(length,currentlength+1,p->num,to,visit,q);
				
				visit[p->num]=FALSE;//还原结点 
				q.pop();
			}
			p=p->next;
		}
	}
}

main(){
	Graph g;
	cout<<endl;
	cout<<"输入起始点的下标 和 长度"<<endl;
	int i,j,w;
	cin>>i>>j>>w; 
	g.simplepath(w,i,j);
	cout<<"共有"<<count<<"条简单路径"<<endl; 
}
