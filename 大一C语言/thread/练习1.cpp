#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
DWORD WINAPI fun(LPVOID lpParameter);
int num=0; 
main(){
	HANDLE Thread;
	Thread=CreateThread(NULL,0,fun,NULL,0,NULL);
	CloseHandle(Thread);//关闭句柄 线程一直运行 
	while(num++<1000)
	printf("777\n");
	
}


DWORD WINAPI fun(LPVOID lpParameter){
	while(num++<1000)
	printf("111\n");
	return 0;
}
