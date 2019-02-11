#include <stdio.h>
#include <malloc.h>
#define  MAX 50
typedef int datatype;

typedef struct 
{
	datatype stack[MAX];
	int top;
}seqstack; //顺序栈定义类型

void initiate (seqstack **s);
int  push(seqstack *s, int n);
int  pop(seqstack *s, int n);
int  stacktop(seqstack *s);
void print(seqstack *s);

int main()
{   
	seqstack *s;
	int sel,n;    /* sel 选择输入， n 进栈或出栈数据的个数*/
	initiate (&s);//
	printf("完成初始化 !\n");
	printf("请输入你的选择: 1--initiate 2--push 3--pop 4--stacktop 5--print 6--exit\nyour choice =");
	scanf("%d",&sel);
	while(sel!=6)
	{   
		if(sel==1)
		{   
			initiate (&s);
			printf("完成初始化 !\n");  
		}
		else if(sel==2)
		{   
			printf("请输入待进栈的数据个数:");
			scanf("%d",&n); 
			push (s,n);
			print(s);  
		}
		else if(sel==3)
		{   
			printf("请输入待出栈的数据个数:");
			scanf("%d",&n);
			pop (s,n);
			print(s);  
		} 
		else if(sel==4)
		{   
			stacktop (s);
            print(s);   
		}
		else if(sel==5)
			print(s);   
		else
			printf("你的选择是错误的!\n ");
		printf("请输入你的选择: 1--initiate 2--push 3--pop 4--stacktop 5--print 6--exit\nyour choice =");
		scanf("%d",&sel);   
	}
	return 1;   
}

/*初始化*/
void initiate (seqstack **s)
  { 
	*s=(seqstack*)malloc(sizeof(seqstack));
    (*s)->top=-1;
}

/*进栈*/
int push(seqstack *s,int n)
{  
	int i,m;
    printf("请输入数字:\n");
	for(i=0;i<n;i++)//n是元素的个数
	{
		scanf("%d",&m);
		s->top++;
		s->stack[s->top]=m;
	}	
	return 0;
}

/*出栈*/
int  pop(seqstack *s,int n)
{  
    
  
		 n=s->stack[s->top+1];
	     s->top--;
	     return 1;
	 

}

/*取栈顶元素*/
int stacktop(seqstack *s )
{   
	datatype x;
	if (s->top==-1)
	{   printf("栈空！\n");
		return 0;  
	}
	x=(s->stack[(s->top)]);
	printf("栈顶数据为：%d\n",x);
	return 1;   
}

/*显示输出*/
void print(seqstack *s )
{   
	int i;
	if (s->top==-1)
		printf("栈空！\n");
	else
		for(i=0;i<=s->top;i++)
			printf("stack[%d]为：%d\n",i,s->stack[i]);  
}