#include<cstdio>
#include<iostream>
#include<queue> 
#define infinite INT_MAX
#define MaxVertex 20
using namespace std;

typedef struct adjMatrix{
	int weight;
}adjMatrix;

class Graph{
	private:
		adjMatrix matrix[MaxVertex][MaxVertex];
		char vertex[MaxVertex];
		int vertexnum,edgenum;
	public:
		Graph();
		void outputMatrix();
		void floyd();
};
Graph::Graph(){
	cout<<"输入图结点和边的数量"<<endl;
	cin>>vertexnum>>edgenum;
	
	for(int i=0;i<vertexnum;i++){
		for(int j=0;j<vertexnum;j++)
		matrix[i][j].weight=(i==j)?0:infinite;
	}

	cout<<"输入各节点的值(a,b,c...)"<<endl;
	for(int i=0;i<vertexnum;i++){
		cin>>vertex[i];
	}
	cout<<"输入结点与边的权值（格式：i j weight，i,j为邻接矩阵下标 从0开始）"<<endl;
	int i,j;
	for(int k=0;k<edgenum;k++){
		cin>>i>>j;
		cin>>matrix[i][j].weight;
	} 
}
void Graph::outputMatrix(){
	cout<<"原邻接矩阵"<<endl; 
	for(int i=0;i<vertexnum;i++){
		for(int j=0;j<vertexnum;j++){
			if(matrix[i][j].weight==infinite)
			cout<<"* ";
			else
			cout<<matrix[i][j].weight<<" ";
		}
		cout<<endl;
	}
}
void Graph::floyd(){
	int min[vertexnum][vertexnum];//记录最短路径长度 
	queue<int> path[vertexnum][vertexnum];//记录最短路径 
	queue<int> temp;
	for(int i=0;i<vertexnum;i++){//M0 赋值为原矩阵 
		for(int j=0;j<vertexnum;j++){
			min[i][j]=matrix[i][j].weight;
			path[i][j].push(i);
			if(i!=j)
			path[i][j].push(j);
		}
		
	}
	for(int k=0;k<vertexnum;k++){//弗洛伊德算法部分 
		for(int i=0;i<vertexnum;i++){
			for(int j=0;j<vertexnum;j++){
				if(min[i][k]!=infinite&&min[k][j]!=infinite&&min[i][k]+min[k][j]<min[i][j]){
					min[i][j]=min[i][k]+min[k][j];
					temp=path[k][j];//路径处理  利用队列数组 
					temp.pop();
					path[i][j]=path[i][k];
					while(temp.size()!=0){
						path[i][j].push(temp.front());
						temp.pop();
					}
				}
			}
		} 
		
	}
	cout<<"最短路径矩阵----------"<<endl;//输出最短路径长度矩阵 
	for(int i=0;i<vertexnum;i++){
		for(int j=0;j<vertexnum;j++){
			if(min[i][j]==infinite)
			cout<<"*"<<" ";
			else
			cout<<min[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"最短路径------------"<<endl;//如果最短路径长度不为正无穷，就输出具体的路径 
	for(int i=0;i<vertexnum;i++){
		for(int j=0;j<vertexnum;j++){
			if(min[i][j]!=infinite){
				cout<<vertex[i]<<"-"<<vertex[j]<<":";
				while(path[i][j].size()!=0){
					cout<<vertex[path[i][j].front()]<<" ";
					path[i][j].pop();
				}
				cout<<endl;
			}
		}
	}
	
}
main(){
	Graph g;
	g.outputMatrix();
	g.floyd();
}
