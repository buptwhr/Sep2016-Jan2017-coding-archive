#include<stdio.h>
int cifang(int x)//��10��x�η� 
{
	int y=1,i;
	for(i=1;i<=x;i++)
	y=y*10;
	return y;	
}

int changdu(int x)//��x��λ�� 
{
	int i;
	for(i=1;x>=10;i++)
	x=x/10;
	return i;
}

main()

{
	int a,b,num,length;
	int flag=1;
	scanf("%d",&num);
	length=changdu(num);
	while(flag==1&&length>1)
	{
		a=num%10;
		b=num/cifang(length-1); 
		if(a==b)
		{
			flag=1;
			num=(num/10)%cifang(length-2);
			length=length-2;
		}
		else
		flag=0;
		
	}
	if(flag==1)
	printf("�ǻ�����");
	else
	printf("���ǻ�����") ;
	
	}
