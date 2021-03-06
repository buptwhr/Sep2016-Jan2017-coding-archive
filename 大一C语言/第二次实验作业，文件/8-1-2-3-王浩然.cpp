#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void build(void);
void append(void);
void output(void);
void update(void);
void deletegood(void);

struct GOODS{
	int num;
	char name[36];
	int amount;
	float price;
};
main(){
	int num;
	printf("请输入您的选择：\n1--创建一个100条空记录的文件\n2--输入商品记录\n3--更新商品记录\n4--删除商品记录\n5--输出全部商品记录\n6--退出程序\n");
	scanf("%d",&num);
	system("cls");
	while(num!=6){
		switch(num){
		case 1:build();break;
		case 2:append();break;
		case 3:update();break;
		case 4:deletegood();break;
		case 5:output();break;
	}
	printf("请输入您的选择：\n1--创建一个100条空记录的文件\n2--输入商品记录\n3--更新商品记录\n4--删除商品记录\n5--输出全部商品记录\n6--退出程序\n");
	scanf("%d",&num);
	system("cls");
	}
	printf("程序运行结束，再见！"); 
}

void build(void){//建立100条空数据 
	FILE* ptr;
	ptr=fopen("commodity.dat","wb");
	if(ptr==NULL){
		printf("Wrong!");
	}
	else{
		struct GOODS blankgoods={100,"",0,0.0};
		for(int i=0;i<=100;i++){
		fwrite(&blankgoods,sizeof(blankgoods),1,ptr);
	}
	}
	fclose(ptr);
	printf("100条空记录创建完毕\n\n");
}
void append(void){//增加商品信息，并输出所有信息 
	FILE* ptr;
	ptr=fopen("commodity.dat","rb+");
	if(ptr==NULL){
		printf("Wrong!");
	}
	else{
		struct GOODS good;
		printf("请输入商品信息[ID为-1代表输入结束]：\n商品ID:");
		scanf("%d",&good.num);
		while(good.num!=-1){
			printf("商品名：");
			scanf("%s",good.name);
			printf("数量：");
			scanf("%d",&good.amount);
			printf("价格：");
			scanf("%f",&good.price);
			fseek(ptr,sizeof(good)*(good.num),SEEK_SET);
			fwrite(&good,sizeof(good),1,ptr);
			printf("请输入商品信息[ID为-1代表输入结束]：\n商品ID:");
			scanf("%d",&good.num);
		}
		fclose(ptr);
		printf("商品信息输入结束\n\n");
		output();
	}
	
}
void output(void){//输出全部信息 
	FILE* ptr;
	ptr=fopen("commodity.dat","rb");
	if(ptr==NULL){
		printf("Wrong!");
	}
	else{
		struct GOODS good;
		printf("商品信息如下：\n记录号(商品ID)\t商品名\t数量\t价格\n");
		for(int i=0;i<=99;i++){
			fseek(ptr,sizeof(good)*i,SEEK_SET);
			fread(&good,sizeof(good),1,ptr);
			if(good.num!=100){
				printf("%d\t\t%s\t%d\t%.2f\n",good.num,good.name,good.amount,good.price);
			}
		}
	}
	fclose(ptr);
	printf("\n");
} 
void update(void){//更新商品信息 
	FILE* ptr;
	ptr=fopen("commodity.dat","rb+");
	if(ptr==NULL){
		printf("Wrong!");
	}
	else{
		printf("请输入待更新商品ID[ID为-1代表结束更新]:\n");
		struct GOODS good;
		char temp[36];//先以字符串的格式储存更新信息，再用函数转化成int float等 
		int num;//num存需要修改的号码，good存这个商品信息，直接在上面修改 
		scanf("%d",&num);
		while(num!=-1){
			fseek(ptr,sizeof(good)*(num),SEEK_SET);
			fread(&good,sizeof(good),1,ptr);
			if(good.num==num){//判断该商品是否在文件里 
				printf("商品信息如下：\n记录号(商品ID)\t商品名\t数量\t价格\n");
				printf("%d\t\t%s\t%d\t%.2f\n",good.num,good.name,good.amount,good.price);
				//更新工作 
				getchar();
				printf("商品名："); 
				gets(temp);
				if(temp[0]!=0){
					strcpy(good.name,temp);
				}
				printf("数量：");
				gets(temp);
				if(temp[0]!=0){
					good.amount=atoi(temp);
				}
				printf("价格：");
				gets(temp);
				if(temp[0]!=0){
					good.price=atof(temp);
				}
				fseek(ptr,sizeof(good)*(num),SEEK_SET);
				fwrite(&good,sizeof(good),1,ptr);
				fflush(ptr);
				printf("更新后商品信息如下：\n记录号(商品ID)\t商品名\t数量\t价格\n");
				printf("%d\t\t%s\t%d\t%.2f\n",good.num,good.name,good.amount,good.price);
				
				//XXXXXXXXXXXXXXXXXXXXXXXXXXX
			}
			else{
				printf("对不起，记录号为%d的商品不存在，无法更新\n",num); 
			}
			printf("请输入待更新商品ID[记录号为-1代表结束更新]:\n");
			scanf("%d",&num);
			
		}
		printf("更新工作结束\n"); 
	}
	fclose(ptr);
}

void deletegood(void){
	FILE* ptr;
	ptr=fopen("commodity.dat","rb+");
	if(ptr==NULL){
		printf("Wrong!");
	}
	else{
		printf("请输入待删除商品ID[记录号为-1代表结束删除]:\n");
		int num;
		scanf("%d",&num);
		struct GOODS emptyGood={100,"",0,0.0},good;
		while(num!=-1){
			fseek(ptr,sizeof(good)*num,SEEK_SET);
			fread(&good,sizeof(good),1,ptr);
			if(num==good.num){
				printf("商品信息如下：\n记录号(商品ID)\t商品名\t数量\t价格\n");
				printf("%d\t\t%s\t%d\t%.2f\n",good.num,good.name,good.amount,good.price);
				printf("是否确实删除（确认按Y，取消按N)？\n");
				char yesOrNo;
				getchar();
				scanf("%c",&yesOrNo);
				
				if(yesOrNo=='Y'||yesOrNo=='y'){
					fseek(ptr,sizeof(good)*num,SEEK_SET);
					fwrite(&emptyGood,sizeof(good),1,ptr);
					fflush(ptr);//缓冲区搞进文件里 
					printf("记录号为%d的商品成功删除\n",num);
				}
				else
				if(yesOrNo=='N'||yesOrNo=='n'){
					printf("您选择不删除记录号为%d的商品\n",num);
				}
				output();
			}
			else{
				printf("对不起，记录号为%d的商品不存在，无法进行删除操作\n",num);
			}
			
			printf("请输入待删除商品ID[记录号为-1代表结束删除]:\n");
			scanf("%d",&num);
		}
		printf("删除工作结束\n");
	}
	fclose(ptr);
}
