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
	printf("����������ѡ��\n1--����һ��100���ռ�¼���ļ�\n2--������Ʒ��¼\n3--������Ʒ��¼\n4--ɾ����Ʒ��¼\n5--���ȫ����Ʒ��¼\n6--�˳�����\n");
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
	printf("����������ѡ��\n1--����һ��100���ռ�¼���ļ�\n2--������Ʒ��¼\n3--������Ʒ��¼\n4--ɾ����Ʒ��¼\n5--���ȫ����Ʒ��¼\n6--�˳�����\n");
	scanf("%d",&num);
	system("cls");
	}
	printf("�������н������ټ���"); 
}

void build(void){//����100�������� 
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
	printf("100���ռ�¼�������\n\n");
}
void append(void){//������Ʒ��Ϣ�������������Ϣ 
	FILE* ptr;
	ptr=fopen("commodity.dat","rb+");
	if(ptr==NULL){
		printf("Wrong!");
	}
	else{
		struct GOODS good;
		printf("��������Ʒ��Ϣ[IDΪ-1�����������]��\n��ƷID:");
		scanf("%d",&good.num);
		while(good.num!=-1){
			printf("��Ʒ����");
			scanf("%s",good.name);
			printf("������");
			scanf("%d",&good.amount);
			printf("�۸�");
			scanf("%f",&good.price);
			fseek(ptr,sizeof(good)*(good.num),SEEK_SET);
			fwrite(&good,sizeof(good),1,ptr);
			printf("��������Ʒ��Ϣ[IDΪ-1�����������]��\n��ƷID:");
			scanf("%d",&good.num);
		}
		fclose(ptr);
		printf("��Ʒ��Ϣ�������\n\n");
		output();
	}
	
}
void output(void){//���ȫ����Ϣ 
	FILE* ptr;
	ptr=fopen("commodity.dat","rb");
	if(ptr==NULL){
		printf("Wrong!");
	}
	else{
		struct GOODS good;
		printf("��Ʒ��Ϣ���£�\n��¼��(��ƷID)\t��Ʒ��\t����\t�۸�\n");
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
void update(void){//������Ʒ��Ϣ 
	FILE* ptr;
	ptr=fopen("commodity.dat","rb+");
	if(ptr==NULL){
		printf("Wrong!");
	}
	else{
		printf("�������������ƷID[IDΪ-1�����������]:\n");
		struct GOODS good;
		char temp[36];//�����ַ����ĸ�ʽ���������Ϣ�����ú���ת����int float�� 
		int num;//num����Ҫ�޸ĵĺ��룬good�������Ʒ��Ϣ��ֱ���������޸� 
		scanf("%d",&num);
		while(num!=-1){
			fseek(ptr,sizeof(good)*(num),SEEK_SET);
			fread(&good,sizeof(good),1,ptr);
			if(good.num==num){//�жϸ���Ʒ�Ƿ����ļ��� 
				printf("��Ʒ��Ϣ���£�\n��¼��(��ƷID)\t��Ʒ��\t����\t�۸�\n");
				printf("%d\t\t%s\t%d\t%.2f\n",good.num,good.name,good.amount,good.price);
				//���¹��� 
				getchar();
				printf("��Ʒ����"); 
				gets(temp);
				if(temp[0]!=0){
					strcpy(good.name,temp);
				}
				printf("������");
				gets(temp);
				if(temp[0]!=0){
					good.amount=atoi(temp);
				}
				printf("�۸�");
				gets(temp);
				if(temp[0]!=0){
					good.price=atof(temp);
				}
				fseek(ptr,sizeof(good)*(num),SEEK_SET);
				fwrite(&good,sizeof(good),1,ptr);
				fflush(ptr);
				printf("���º���Ʒ��Ϣ���£�\n��¼��(��ƷID)\t��Ʒ��\t����\t�۸�\n");
				printf("%d\t\t%s\t%d\t%.2f\n",good.num,good.name,good.amount,good.price);
				
				//XXXXXXXXXXXXXXXXXXXXXXXXXXX
			}
			else{
				printf("�Բ��𣬼�¼��Ϊ%d����Ʒ�����ڣ��޷�����\n",num); 
			}
			printf("�������������ƷID[��¼��Ϊ-1�����������]:\n");
			scanf("%d",&num);
			
		}
		printf("���¹�������\n"); 
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
		printf("�������ɾ����ƷID[��¼��Ϊ-1�������ɾ��]:\n");
		int num;
		scanf("%d",&num);
		struct GOODS emptyGood={100,"",0,0.0},good;
		while(num!=-1){
			fseek(ptr,sizeof(good)*num,SEEK_SET);
			fread(&good,sizeof(good),1,ptr);
			if(num==good.num){
				printf("��Ʒ��Ϣ���£�\n��¼��(��ƷID)\t��Ʒ��\t����\t�۸�\n");
				printf("%d\t\t%s\t%d\t%.2f\n",good.num,good.name,good.amount,good.price);
				printf("�Ƿ�ȷʵɾ����ȷ�ϰ�Y��ȡ����N)��\n");
				char yesOrNo;
				getchar();
				scanf("%c",&yesOrNo);
				
				if(yesOrNo=='Y'||yesOrNo=='y'){
					fseek(ptr,sizeof(good)*num,SEEK_SET);
					fwrite(&emptyGood,sizeof(good),1,ptr);
					fflush(ptr);//����������ļ��� 
					printf("��¼��Ϊ%d����Ʒ�ɹ�ɾ��\n",num);
				}
				else
				if(yesOrNo=='N'||yesOrNo=='n'){
					printf("��ѡ��ɾ����¼��Ϊ%d����Ʒ\n",num);
				}
				output();
			}
			else{
				printf("�Բ��𣬼�¼��Ϊ%d����Ʒ�����ڣ��޷�����ɾ������\n",num);
			}
			
			printf("�������ɾ����ƷID[��¼��Ϊ-1�������ɾ��]:\n");
			scanf("%d",&num);
		}
		printf("ɾ����������\n");
	}
	fclose(ptr);
}
