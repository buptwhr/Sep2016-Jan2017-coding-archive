#include<iostream>
#define MAXNUM 20
using namespace std;

class sql{
	private:
		int length;
		int array[1+MAXNUM];
		void heapadjust(int,int); 
		int partition(int,int);
		void quicksort_(int,int);
	public:
		sql();
		void print();
		void insertsort();
		void shellsort();
		void heapsort();
		void quicksort();
};
sql::sql(){
	cout<<"input the num of numbers(at most 20)\n";
	cin>>length;	
	if(length>20){
		cout<<"oh!!!!no\n";
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
void sql::insertsort(){
	int temp;
	for(int i=2;i<=length;i++){
		if(array[i]<array[i-1]){
			array[0]=array[i];
			array[i]=array[i-1];
			int j;
			for(j=i-2;array[j]>array[0];j--){
				array[j+1]=array[j];
			}
			array[j+1]=array[0];
		}
	}
}
void sql::shellsort(){
	cout<<"input the length of array d[]"<<endl;
	int dl;
	cin>>dl;
	int d[dl];
	cout<<"input the elements of d[], the last one must be 1"<<endl;
	for(int i=0;i<dl;i++)
	cin>>d[i];
	int k;
	for(int i=0;i<dl;i++){
		for(int j=d[i]+1;j<=length;j++){
			if(array[j]<array[j-d[i]]){
				array[0]=array[j];
				array[j]=array[j-d[i]];
				for(k=j-2*d[i];k>0&&array[k]>array[0];k-=d[i]){
					array[k]=array[k-d[i]];
				}
				array[k+d[i]]=array[0];
			}
		}
	}
}
void sql::heapadjust(int start,int tail){
	int smaller;
	int temp;
	for(int i=start;2*i<=tail;){
		if((2*i+1)<=tail&&array[2*i]>array[2*i+1])
		smaller=2*i+1;
		else
		smaller=2*i;
		if(array[i]>array[smaller]){
			temp=array[i];
			array[i]=array[smaller];
			array[smaller]=temp;
			i=smaller;
		}
		else
		break;		
	}
}
void sql::heapsort(){
	int temp;
	for(int i=length/2;i>=1;i--){
		heapadjust(i,length);
	}
	for(int i=length;i>=2;i--){
		temp=array[1];
		array[1]=array[i];
		array[i]=temp;
		heapadjust(1,i-1);
	}
}
void sql::quicksort_(int start,int tail){
	if(start<tail){
		int pivotkey=partition(start,tail);
		quicksort_(start,pivotkey-1);
		quicksort_(pivotkey+1,tail);
	}
}
int sql::partition(int start,int tail){
	array[0]=array[start];
	while(start!=tail){
		while(start<tail&&array[tail]>=array[0]) tail--;
		array[start]=array[tail];

		while(start<tail&&array[start]<=array[0]) start++;
		array[tail]=array[start];
	}
	array[start]=array[0];
	return start;
}
void sql::quicksort(){
	quicksort_(1,length);
}
main(){
	sql s;
	s.print();
	s.quicksort();
	s.print();
} 
