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
	cout<<"����ͼ���ͱߵ�����"<<endl;
	cin>>vertexnum>>edgenum;
	
	for(int i=0;i<vertexnum;i++){
		for(int j=0;j<vertexnum;j++)
		matrix[i][j].weight=(i==j)?0:infinite;
	}

	cout<<"������ڵ��ֵ(a,b,c...)"<<endl;
	for(int i=0;i<vertexnum;i++){
		cin>>vertex[i];
	}
	cout<<"��������ߵ�Ȩֵ����ʽ��i j weight��i,jΪ�ڽӾ����±� ��0��ʼ��"<<endl;
	int i,j;
	for(int k=0;k<edgenum;k++){
		cin>>i>>j;
		cin>>matrix[i][j].weight;
	} 
}
void Graph::outputMatrix(){
	cout<<"ԭ�ڽӾ���"<<endl; 
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
	int min[vertexnum][vertexnum];//��¼���·������ 
	queue<int> path[vertexnum][vertexnum];//��¼���·�� 
	queue<int> temp;
	for(int i=0;i<vertexnum;i++){//M0 ��ֵΪԭ���� 
		for(int j=0;j<vertexnum;j++){
			min[i][j]=matrix[i][j].weight;
			path[i][j].push(i);
			if(i!=j)
			path[i][j].push(j);
		}
		
	}
	for(int k=0;k<vertexnum;k++){//���������㷨���� 
		for(int i=0;i<vertexnum;i++){
			for(int j=0;j<vertexnum;j++){
				if(min[i][k]!=infinite&&min[k][j]!=infinite&&min[i][k]+min[k][j]<min[i][j]){
					min[i][j]=min[i][k]+min[k][j];
					temp=path[k][j];//·������  ���ö������� 
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
	cout<<"���·������----------"<<endl;//������·�����Ⱦ��� 
	for(int i=0;i<vertexnum;i++){
		for(int j=0;j<vertexnum;j++){
			if(min[i][j]==infinite)
			cout<<"*"<<" ";
			else
			cout<<min[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"���·��------------"<<endl;//������·�����Ȳ�Ϊ���������������·�� 
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
