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
	DataType data[MAXLEN+1];//DataType元素类型  有i个叫DataType的结构体保存在data数组里
	int len;
}SeqList;//顺序表类型

//顺序表的输入
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
//查找
int search(SeqList*L,DataType x)
{
	int i=1;
	while(i<=L->len&&strcmp(L->data[i].no,x.no)!=0)//查找元素x所在的位置，这里的x也是个数组
		//strcmp是string.h的一个函数，比较两个字符串，相同返回0
		i++;
	if(i>L->len)
		return 0;
	    return i;
}	
//插入职工信息(Disabled)

/*void ins(SeqList*L,DataType x)//?
{
	int i,j;
	i=search(L,x);
	if(i==0);
	//????
	
}*/

//菜单
void menu()
{
	printf("1.录入信息:\n");
	printf("2.查找:\n");
	//printf("3.插入:\n");
	printf("4.输出:\n");
	printf("0.退出:\n");
}
void main()
{
	SeqList*L;//固定格式
	DataType x;//设置一个叫x的DataType结构体
	int sel,i;
	L=(SeqList*)malloc(sizeof(SeqList));//固定格式，获取顺序表的储存空间

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