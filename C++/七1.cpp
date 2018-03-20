/*
2017��9��21�� 19:40:57 
��ϰmap�ṹ <string,string>  key-value(name-num) 
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


string phoneBook::find_(string s){//������� �򷵻ص绰 ���򷵻ء�NOTINIT�� 
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
	cout<<"1�����ҵ绰 2�������ϵ�� 3��ɾ����ϵ�� 4�����沢�˳�\n";
	while((cin>>i)&&i!=4){
		
		switch(i){
			case 1:
				cout<<"������Ҫ���ҵ�����"<<endl;
				cin>>name;
				if(p.find_(name)=="NOTINIT"){
					cout<<"�����������ϵ��"<<endl; 
				} 
				else{
					cout<<name<<"�ĵ绰Ϊ"<<p.find_(name)<<endl;
				}
				break;
			case 2:
				cout<<"��������ϵ�������͵绰,�ո�ָ�����������ǣ�"<<endl;
				cin>>name>>num;
				p.add_(name,num); 
				break;
			case 3:
				cout<<"������Ҫɾ������ϵ��"<<endl;
				cin>>name;
				if(p.delete_(name)){
					cout<<"ɾ���ɹ�"<<endl; 
				}else{
					cout<<"Ҫɾ������ϵ�˲�����"<<endl; 
				}
				break;
		}
		cout<<"1�����ҵ绰 2�������ϵ�� 3��ɾ����ϵ�� 4�����沢�˳�\n";
	} 
//	p.save_();
} 


