/*
2017��9��21�� 13:25:59 
*/
#include<iostream>
#include<fstream> 
#include<string>
using namespace std;

main(){
	string title;
	int i=1;
	cin>>title;
	ofstream o_file;
	ifstream i_file;
	i_file.open((title+".txt").c_str());
	o_file.open((title+"_copy.txt").c_str());
	if(i_file&&o_file){//�򿪳ɹ� 
		while(!i_file.eof()){
			getline(i_file,title);//��ȡһ�� 
			o_file<<i<<"."<<title<<endl;//����д�� 
			i++;
		}
		cout<<"success"<<endl;
	}
	else{
		cout<<"�ļ���ʧ��"<<endl; 
	}
	i_file.close();
	o_file.close();
}
