/*
2017年9月21日 19:40:57 
练习map结构 <string,string>  key-value(name-num) 
*/

#include<iostream>
#include<fstream>
#include<map>
using namespace std;

class phoneBook{
	private:
		map<string,string>phone_book;
		
	public:
		phoneBook();
		~phoneBook();
		void save_();
		void add_(string,string);
		int delete_(string);
		string find_(string);
};
phoneBook::phoneBook(){
	fstream phoneBookFile;
	phoneBookFile.open("phonebook.txt");
	string name,num;
	if(phoneBookFile){
		while(!phoneBookFile.eof()){
//			getline(phoneBookFile,name);
//			getline(phoneBookFile,num);
			phoneBookFile>>name;
			phoneBookFile>>num;
			phone_book[name]=num;
			phone_book.erase("");
		}
	}
	phoneBookFile.close();
}
phoneBook::~phoneBook(){
		fstream phoneBookFile;
		phoneBookFile.open("phonebook.txt",ios::out);
		map<string,string>::iterator it;
		it=phone_book.begin();
		while(it!=phone_book.end()){
	//	cout<<it->first<<"\n"<<it->second;
		phoneBookFile<<it->first<<"\n"<<it->second;
		it++;
		if(it!=phone_book.end()){
		phoneBookFile<<endl;
	//	cout<<endl;
		}	
	}
	phoneBookFile.close();
} 
void phoneBook::save_(){
	fstream phoneBookFile;
	phoneBookFile.open("phonebook.txt",ios::out);
	map<string,string>::iterator it;
	it=phone_book.begin();
	while(it!=phone_book.end()){
	//	cout<<it->first<<"\n"<<it->second;
		phoneBookFile<<it->first<<"\n"<<it->second;
		it++;
		if(it!=phone_book.end()){
		phoneBookFile<<endl;
	//	cout<<endl;
		}
		
	}
	phoneBookFile.close();
	
}
void phoneBook::add_(string name,string num){
	phone_book[name]=num;
}
int phoneBook::delete_(string name){
	if(phone_book.count(name)){
		return phone_book.erase(name);
	}
	
}


string phoneBook::find_(string s){//如果存在 则返回电话 否则返回“NOTINIT” 
	if(phone_book.count(s)){
		return phone_book[s];
	}
	else
		return "NOTINIT";
}
main(){
	phoneBook p;
	string name;
	string num;
	int i;
	cout<<"1、查找电话 2、添加联系人 3、删除联系人 4、保存并退出\n";
	while((cin>>i)&&i!=4){
		
		switch(i){
			case 1:
				cout<<"输入你要查找的姓名"<<endl;
				cin>>name;
				if(p.find_(name)=="NOTINIT"){
					cout<<"不存在这个联系人"<<endl; 
				} 
				else{
					cout<<name<<"的电话为"<<p.find_(name)<<endl;
				}
				break;
			case 2:
				cout<<"请输入联系人姓名和电话,空格分割（重名将被覆盖）"<<endl;
				cin>>name>>num;
				p.add_(name,num); 
				break;
			case 3:
				cout<<"请输入要删除的联系人"<<endl;
				cin>>name;
				if(p.delete_(name)){
					cout<<"删除成功"<<endl; 
				}else{
					cout<<"要删除的联系人不存在"<<endl; 
				}
				break;
		}
		cout<<"1、查找电话 2、添加联系人 3、删除联系人 4、保存并退出\n";
	} 
//	p.save_();
} 


