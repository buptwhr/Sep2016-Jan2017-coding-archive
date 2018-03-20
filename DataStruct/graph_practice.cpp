#include<iostream>
#include<queue>
#include<stack> 
#include<cstdlib>
#define infinite INT_MAX
#define MaxVertex 20


using namespace std;

typedef enum{DG,UDG,DN,UDN}Graphkind;
typedef enum{TRUE,FALSE}Status;
typedef struct Edge{
	int content;
}Edge,adjMatrix[MaxVertex][MaxVertex];
class Graph{
	private:
		Graphkind kind;
		int vertexnum,edgenum;
		char vertex[MaxVertex];
		adjMatrix matrix;
	public:
		Graph(Graphkind);
		void outputMatrix();
		void BFS1();
		void BFS2();
		void DFS(); //非递归方法实现 
		void DFS_normal(); //递归实现 
		void DFS_recurtion(Status*,int);//这是递归部分 
		void prim();
		Status toplogicalsort();
		void Dijkstra(int,int); 
};

Graph::Graph(Graphkind g){//参数为图的类型 
	kind=g;
	for(int i=0;i<MaxVertex;i++){
		for(int j=0;j<MaxVertex;j++)
			matrix[i][j].content=(i==j)?0:infinite;
	}
	cout<<"input vertex's and edge's num"<<endl;
	cin>>vertexnum>>edgenum;
	cout<<"input the content of every vertex(char)"<<endl;
	for(int i=0;i<vertexnum;i++)
	cin>>vertex[i];
	if(kind==UDG){
		cout<<"input the adjcent mtrix(format: i j)"<<endl;
		int i,j;
		for(int p=0;p<edgenum;p++){
			cin>>i>>j;
			matrix[i][j].content=1;
			matrix[j][i].content=1;
		}
	}
	else if(kind==DG){
		cout<<"input the adjcent mtrix(format: i j)"<<endl;
		int i,j;
		for(int p=0;p<edgenum;p++){
			cin>>i>>j;
			matrix[i][j].content=1;
		}
		
	}
	else if(kind==UDN){
		cout<<"input the adjcent mtrix(format: i j weight)"<<endl;
		int i,j,weight;
		for(int p=0;p<edgenum;p++){
			cin>>i>>j>>weight;
			matrix[i][j].content=weight;
			matrix[j][i].content=weight;
		}
	}
	else if(kind==DN){
		cout<<"input the adjcent mtrix(format: i j weight)"<<endl;
		int i,j,weight;
		for(int p=0;p<edgenum;p++){
			cin>>i>>j>>weight;
			matrix[i][j].content=weight;
		}
	}
}
void Graph::outputMatrix(){
	for(int i=0;i<vertexnum;i++){
		for(int j=0;j<vertexnum;j++){
			if(matrix[i][j].content==infinite)
			cout<<"* ";
			else
			cout<<matrix[i][j].content<<" ";
		}
		cout<<endl;
	}
}
void Graph::BFS1(){
	queue<int> q;
	int k;
	Status visit[vertexnum];
	for(int i=0;i<vertexnum;i++)
	visit[i]=FALSE;
	for(int i=0;i<vertexnum;i++){
		if(visit[i]==FALSE){
			cout<<vertex[i]<<" ";
			visit[i]=TRUE;
			q.push(i);
			while(q.size()!=0){
				k=q.front();
				q.pop();
				for(int j=0;j<vertexnum;j++){
					if(matrix[k][j].content!=0&&matrix[k][j].content!=infinite&&visit[j]==FALSE){
						cout<<vertex[j]<<" ";
						visit[j]=TRUE;
						q.push(j);
					}
				}
			}
			cout<<endl;
		}
	
	}
	
}
void Graph::BFS2(){
	queue<int> q;
	int k;
	Status visit[vertexnum];
	for(int i=0;i<vertexnum;i++)
	visit[i]=FALSE;
	for(int i=0;i<vertexnum;i++){
		if(visit[i]==FALSE){
			q.push(i);
			while(q.size()!=0){
				k=q.front();
				q.pop();
				if(visit[k]==FALSE)
				cout<<vertex[k]<<" ";
				visit[k]=TRUE;
				for(int j=0;j<vertexnum;j++){
					if(matrix[k][j].content!=0&&matrix[k][j].content!=infinite&&visit[j]==FALSE)
					q.push(j);
				}
			}
			cout<<endl;
		}
	}
} 
void Graph::DFS(){
	stack<int> s;
	int k;
	Status visit[vertexnum];
	for(int i=0;i<vertexnum;i++)
	visit[i]=FALSE;
	for(int i=0;i<vertexnum;i++){
		if(visit[i]==FALSE){
			s.push(i);
			while(s.size()!=0){
				k=s.top();
				s.pop();
				if(visit[k]==FALSE){
					visit[k]=TRUE;
					cout<<vertex[k]<<" ";
					for(int j=0;j<vertexnum;j++){
						if(matrix[k][j].content!=0&&matrix[k][j].content!=infinite&&visit[j]==FALSE){
							s.push(j);
						}
					}
				}
				
				
			}
		}
	}
} 
void Graph::DFS_normal(){
	Status visit[vertexnum];
	for(int i=0;i<vertexnum;i++)
	visit[i]=FALSE;
	for(int i=0;i<vertexnum;i++){
		if(visit[i]==FALSE){
			DFS_recurtion(visit,i);
		}
	}	 
}
void Graph::DFS_recurtion(Status* visit,int index){
	if(visit[index]==FALSE){
		cout<<vertex[index]<<" ";
		visit[index]=TRUE;
		for(int i=0;i<vertexnum;i++){
			if(matrix[index][i].content!=0&&matrix[index][i].content!=infinite&&visit[i]==FALSE){
				DFS_recurtion(visit,i);
			}
		}
	}
}
void Graph::prim(){//从0开始 ,只解决联通网 
	if(kind==DG||kind==UDG){
		cout<<"this is not a graph with weight\n";
	}
	else{
		int lowcost[vertexnum];
		int fromvertex[vertexnum];
		for(int i=0;i<vertexnum;i++){
			lowcost[i]=matrix[0][i].content;
			fromvertex[i]=0;
		}
		int i=vertexnum-1;
		int min,k=0;
		while(i--){
			min=infinite;;
			for(int j=0;j<vertexnum;j++){//找到当前lowcost中最小的 
				if(min>lowcost[j]&&lowcost[j]!=0){
					min=lowcost[j];
					k=j;
				}
			}
			cout<<fromvertex[k]<<" "<<k<<endl;
			for(int j=0;j<vertexnum;j++){
				if(matrix[k][j].content<lowcost[j]){
					lowcost[j]=matrix[k][j].content;
					fromvertex[j]=k;
				}
				
			}
		}
	} 
}
Status Graph::toplogicalsort(){
	int count=0;
	int indegree[vertexnum];
	for(int i=0;i<vertexnum;i++)
	indegree[i]=0;
	stack<int> s;
	for(int i=0;i<vertexnum;i++){
		for(int j=0;j<vertexnum;j++){
			if(matrix[i][j].content!=0&&matrix[i][j].content!=infinite)
			indegree[j]++;
		}
	}
	for(int i=0;i<vertexnum;i++){
		if(indegree[i]==0)
		s.push(i);
	}
	int k;
	while(s.size()!=0){
		k=s.top();
		count++;
		cout<<k<<" ";
		s.pop();
		for(int i=0;i<vertexnum;i++){
			if(matrix[k][i].content!=0&&matrix[k][i].content!=infinite){
				if(--indegree[i]==0){
					s.push(i);
				}
			}
		}
	}
	if(count==vertexnum)
	return TRUE;
	else
	return FALSE;
}
void Graph::Dijkstra(int from,int to){
	int distance[vertexnum];
	Status chosen[vertexnum];
	for(int i=0;i<vertexnum;i++)
	chosen[i]=FALSE;
	int chosennum=1;
	queue<int> path[vertexnum];
	for(int i=0;i<vertexnum;i++){
		distance[i]=matrix[from][i].content;
		path[i].push(from);
		if(i!=from)
		path[i].push(i);
	}
	int min;
	int k;
	
	while(chosennum!=vertexnum){
		min=infinite;
		for(int i=0;i<vertexnum;i++){//找到路径里最短的  以及下标 
		if(min>distance[i]&&chosen[i]==FALSE){
			min=distance[i];
			k=i;
		}
	}
		chosen[k]=TRUE;
		chosennum++;
		for(int i=0;i<vertexnum;i++){
			if(chosen[i]==FALSE&&matrix[k][i].content!=infinite&&((distance[i]!=infinite&&distance[k]+matrix[k][i].content<distance[i])||distance[i]==infinite)){
				distance[i]=distance[k]+matrix[k][i].content;
				path[i]=path[k];
				path[i].push(i);
			}
	}
	}
	for(int i=0;i<vertexnum;i++){
		while(path[i].size()!=0){
			cout<<path[i].front();
			path[i].pop();
		}
		cout<<endl;
	}
}
main(){
	Graph graph(DN);
	graph.outputMatrix();
	graph.Dijkstra(0,4);
}


