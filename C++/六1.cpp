/*
2017Äê9ÔÂ21ÈÕ 11:08:23 
*/
#include<iostream>
#include <iomanip> 
#include<fstream>
using namespace std;

main(){
	int i=-10086;
	unsigned u=10086;
	long int l=10086;
	double f=10086.10086;
	char c[]="CMCC";
	fstream my_file;
	my_file.open("file.txt",ios::out);
	my_file<<i<<endl;
	my_file<<u<<endl;
	my_file<<l<<endl;
	my_file<<f<<endl;
	my_file<<c<<endl;
//-----------------------------
	my_file<<i<<endl;
	my_file<<oct<<i<<endl;
	my_file<<hex<<i<<endl;
//-------------------------
	my_file<<setiosflags(ios::left)<<setw(10)<<f<<endl;
	my_file<<setfill('*')<<setw(10)<<f<<endl;
	my_file<<setprecision(11)<<setw(20)<<f<<endl;
	my_file.close();
}
