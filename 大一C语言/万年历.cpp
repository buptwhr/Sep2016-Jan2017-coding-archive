#include <stdio.h>
int bissextile(int);
int days(int,int);
int thismonth,a;


main(){
	int i,year,month;
	printf("写完之后感觉血亏，输入年 月");
	scanf("%d%d",&year,&month);
	printf("Sun\tMon\tTues\tWeds\tThur\tFri\tSat\n");
	for(i=0;i<days(year,month)%7;i++){
		printf("\t");
	}
	for(i=1;i<=thismonth;i++){
		printf("%d",i);
		if(((days(year,month)%7)+i)%7==0)
		printf("\n");
		else
		printf("\t");
	}
	printf("\nMDZZ  写于2016/11/24 23:37\nMDZZ  修改于2016/11/25 19：26"); 
//	printf("%d  %d",a,days(2016,2));

}


int bissextile(int year){
	if ((year%4==0&&year%100!=0)||year%400==0)
	return 1;
	else
	return 0;//is bissextile return 1;else 0; 
}

int days(int year,int months){//该年该月第一天  是第多少天 
	int i,day=1;
	for (i=1;i<months;i++){
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
		day+=31;
		else
		if(i==4||i==6||i==9||i==11)
		day+=30;
		else
		if(bissextile(year))
		day+=29;
		else
		day+=28;
	}
	
	a=day;
	switch(months){
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:
			thismonth=31;break; 
			case 4:case 6:case 9: case 11:
			thismonth=30;break;
			case 2:
				if(bissextile(year))
				thismonth=29;
				else
				thismonth=28;break;    
	}
	for(i=1;i<year;i++){
		if(bissextile(i))
		day+=366;
		else
		day+=365;
	}
	return day;
}













