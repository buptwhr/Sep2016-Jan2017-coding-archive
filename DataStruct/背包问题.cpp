#include<iostream>
#include<cstdlib>
using namespace std;
int bag(int a[],int m,int good[],int n1,int n2,int weight);
int num=0; 
main(){
	int n;
	cout<<"输入物体数量\n";
	cin>>n;
	int good[n];
	int a[n];
	cout<<"分别输入物体重量\n";
	for(int i=0;i<n;i++){
		cin>>good[i];
	} 
	int weight;
	cout<<"输入背包容量\n"; 
	cin>>weight;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(good[j]>good[j+1]){
				int temp;
				temp=good[j];
				good[j]=good[j+1];
				good[j+1]=temp;
			}
		}
	}
	bag(a,0,good,0,n,weight);
	if(num==0)
	cout<<"没有合适组合";
} 

int bag(int a[],int m,int good[],int n1,int n2,int weight){
	if(weight==0){
		for(int i=0;i<m;i++){
			cout<<a[i]<<" ";
			num++;
		}
		cout<<endl;
	}
	else if(weight<0){
		return 0;
	}
	else{
		for(int i=n1;i<n2;i++){
			a[m]=good[i];
			bag(a,m+1,good,i+1,n2,weight-a[m]);
		}	
	}
} 
