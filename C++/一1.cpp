#include<iostream>
#include<cstdlib>
#include<time.h>
/*
2017��9��11�� 16:48:35
2017��9��15�� 09:07:25 
*/
using namespace std;

main(){
	srand(time(NULL));
	int iNum=rand()%1000+1;
//	cout<<"random num is "<<iNum<<endl;
	int iFlag=1;
	int iGuess;
	while(iFlag){
		cout<<"please input your assumption from 1 to 1000"<<endl;
		cin>> iGuess;
		if(cin.fail()){
			cout<<"wrong input!"<<endl ;
			cin.clear();//������������ ��ѭ������ ��������� 
//			fflush(stdin);
			cin.sync(); //���cin������ 
		}
		else{
			if(iGuess<1||iGuess>1000){
				cout<<"beyong the restriction"<<endl;//�ж�Խ�� 
			} 
			else{
			if(iGuess>iNum)
			cout<<"try a num smaller"<<endl;
			else if(iGuess<iNum)
			cout<<"try a num bigger"<<endl;
			else
			iFlag=0;
			}
		}
		
		
	} 
	cout<<"you are right"; 
}
