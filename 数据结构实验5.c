#include <stdio.h>
#include <malloc.h>
#define  MAX 50
typedef int datatype;

typedef struct 
{
	datatype stack[MAX];
	int top;
}seqstack; //˳��ջ��������

void initiate (seqstack **s);
int  push(seqstack *s, int n);
int  pop(seqstack *s, int n);
int  stacktop(seqstack *s);
void print(seqstack *s);

int main()
{   
	seqstack *s;
	int sel,n;    /* sel ѡ�����룬 n ��ջ���ջ���ݵĸ���*/
	initiate (&s);//
	printf("��ɳ�ʼ�� !\n");
	printf("���������ѡ��: 1--initiate 2--push 3--pop 4--stacktop 5--print 6--exit\nyour choice =");
	scanf("%d",&sel);
	while(sel!=6)
	{   
		if(sel==1)
		{   
			initiate (&s);
			printf("��ɳ�ʼ�� !\n");  
		}
		else if(sel==2)
		{   
			printf("���������ջ�����ݸ���:");
			scanf("%d",&n); 
			push (s,n);
			print(s);  
		}
		else if(sel==3)
		{   
			printf("���������ջ�����ݸ���:");
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
			printf("���ѡ���Ǵ����!\n ");
		printf("���������ѡ��: 1--initiate 2--push 3--pop 4--stacktop 5--print 6--exit\nyour choice =");
		scanf("%d",&sel);   
	}
	return 1;   
}

/*��ʼ��*/
void initiate (seqstack **s)
  { 
	*s=(seqstack*)malloc(sizeof(seqstack));
    (*s)->top=-1;
}

/*��ջ*/
int push(seqstack *s,int n)
{  
	int i,m;
    printf("����������:\n");
	for(i=0;i<n;i++)//n��Ԫ�صĸ���
	{
		scanf("%d",&m);
		s->top++;
		s->stack[s->top]=m;
	}	
	return 0;
}

/*��ջ*/
int  pop(seqstack *s,int n)
{  
    
  
		 n=s->stack[s->top+1];
	     s->top--;
	     return 1;
	 

}

/*ȡջ��Ԫ��*/
int stacktop(seqstack *s )
{   
	datatype x;
	if (s->top==-1)
	{   printf("ջ�գ�\n");
		return 0;  
	}
	x=(s->stack[(s->top)]);
	printf("ջ������Ϊ��%d\n",x);
	return 1;   
}

/*��ʾ���*/
void print(seqstack *s )
{   
	int i;
	if (s->top==-1)
		printf("ջ�գ�\n");
	else
		for(i=0;i<=s->top;i++)
			printf("stack[%d]Ϊ��%d\n",i,s->stack[i]);  
}