#include<iostream>
#include<stack> 
#define MAXSIZE 20
using namespace std;
typedef struct tuple{//二元组 放栈里 
	int low;
	int high;
}tuple;
class sql{
	private:
		int array[MAXSIZE+1];
		int length;
	public:
		sql();
		void print();
		void quicksort();
};
sql::sql(){
	cout<<"input the num of numbers(at most 20)\n";
	cin>>length;	
	if(length>20){
		cout<<"too many\n";
		exit(0);
	}

	for(int i=1;i<=length;i++){
		cin>>array[i];
	}
}
void sql::print(){
	for(int i=1;i<=length;i++)
	cout<<array[i]<<" ";
	cout<<endl;
}
void sql::quicksort(){
	stack<tuple> s;
	tuple t;
	int low,high,temp;
	low=1;
	high=length;
	int i,j;//移动 
	
	t.low=0;
	t.high=0;
	s.push(t);//栈区压入一个无意义信息，方便进入while循环
	while(s.size()!=0){
		if(high-low<=2){
			if(high-low>=1){
				for(int k=0;k<=high-low;k++){
					for(int q=low;q<high;q++){
						if(array[q]>array[q+1]){
							temp=array[q];
							array[q]=array[q+1];
							array[q+1]=temp;
						}
					}
				}
			}
			t=s.top();
			low=t.low;
			high=t.high;
			s.pop();
		}
		else{
			array[0]=array[low];
			i=low,j=high;
			while(i!=j){
			while(i<j&&array[j]>=array[0]) j--;
			array[i]=array[j];
			while(i<j&&array[i]<=array[0]) i++;
			array[j]=array[i];
			}
			array[i]=array[0];
			if(high-i>i-low){
				t.low=i+1;
				t.high=high;
				s.push(t);
				high=i-1;
			}
			else{
				t.low=low;
				t.high=i-1;
				s.push(t);
				low=i+1;
			}
		}	
}
}
main(){
	sql s;
	s.quicksort();
	s.print();
}
