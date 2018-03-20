/*
2017年9月21日 13:25:59 
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
	if(i_file&&o_file){//打开成功 
		while(!i_file.eof()){
			getline(i_file,title);//获取一行 
			o_file<<i<<"."<<title<<endl;//重新写入 
			i++;
		}
		cout<<"success"<<endl;
	}
	else{
		cout<<"文件打开失败"<<endl; 
	}
	i_file.close();
	o_file.close();
}
