#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLEN 100 
typedef struct
{
	char no[8],name[10],xb[3];
}DataType;
typedef struct
{
	DataType data[MAXLEN+1];//DataTypeԪ������  ��i����DataType�Ľṹ�屣����data������
	int len;
}SeqList;//˳�������

//˳��������
void input(SeqList*L)
{
	int i;
	printf("Input the length.\n");
	scanf("%d",&L->len);
	printf("Input no,name,xb:\n");
	for(i=0;i<=L->len;i++)
	{
		scanf("%s%s%s",L->data[i].no,L->data[i].name,L->data[i].xb);
	}
}
//����
int search(SeqList*L,DataType x)
{
	int i=1;
	while(i<=L->len&&strcmp(L->data[i].no,x.no)!=0)//����Ԫ��x���ڵ�λ�ã������xҲ�Ǹ�����
		//strcmp��string.h��һ���������Ƚ������ַ�������ͬ����0
		i++;
	if(i>L->len)
		return 0;
	    return i;
}	
//����ְ����Ϣ(Disabled)

/*void ins(SeqList*L,DataType x)//?
{
	int i,j;
	i=search(L,x);
	if(i==0);
	//????
	
}*/

//�˵�
void menu()
{
	printf("1.¼����Ϣ:\n");
	printf("2.����:\n");
	//printf("3.����:\n");
	printf("4.���:\n");
	printf("0.�˳�:\n");
}
void main()
{
	SeqList*L;//�̶���ʽ
	DataType x;//����һ����x��DataType�ṹ��
	int sel,i;
	L=(SeqList*)malloc(sizeof(SeqList));//�̶���ʽ����ȡ˳���Ĵ���ռ�

	L->len=0;
	do
	{
		menu();
		printf("Input your selcet:\n");
		scanf("%d",&sel);
		switch(sel)
		{
		case 1:input(L);
			break;
		case 2:printf("Input no:\n");
			scanf("%s",x.no);
			i=search(L,x);
			if(i==0)
				printf("Not exist!\n");
			else
				printf("%10s%12s%4s\n",L->data[i].no,L->data[i].name,L->data[i].xb);
			break;
		case 4:for(i=0;i<=L->len;i++)
				   printf("%10s%12s%4s\n",L->data[i].no,L->data[i].name,L->data[i].xb);
		}
	}while(sel!=0);
}