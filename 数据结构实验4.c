#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef int datatype;

typedef struct node
{  
	datatype data;
	struct node *next;
}slnode;
int l;            /*������ҵ��Ľ��λ��*/

slnode *initiate ( );
int append(slnode *h);
int insert(slnode *h, int n);
int deletet(slnode *h, int n);
slnode * search(slnode *h, datatype x);
void print(slnode *h);

void main()
{
	slnode *h,*s;
	int sel,n,x;   /* sel ѡ�����룬n �����ɾ�����ĸ�����x Ҫ���ҵĽ������*/
   
	printf("���������ѡ��: 1---initiate 2---append 3---insert 4---delete  5--- search 6---print 7---exit\nyour choice =");
	scanf("%d",&sel);
	while(sel!=7)
	{
		if(sel==1)
		{
			h=initiate( );
		}
		else if(sel==2)
		{
			append(h);
			print(h);
		}
		else if(sel==3)
		{
			printf("�����������Ľ�����:");
		    scanf("%d",&n); 
		    insert(h,n);
		    print(h);
		}
		else if(sel==4)
		{
			printf("�������ɾ���Ľ�����:");
			scanf("%d",&n);
			deletet(h,n);
			print(h);
		}
		else if(sel==5)
		{   
			printf("������Ҫ���ҵĽ������:");
			scanf("%d",&x);
			s=search(h,x);
			if(s!=NULL)
				printf("���ҳɹ������λ��Ϊ��%d\n",l);
		}
		else if(sel==6)
		{
			print(h);
		}
		else
			printf("���ѡ���Ǵ����!\n ");
		printf("���������ѡ��: 1---initiate 2---append 3---insert 4---delete  5--- search 6---print 7---exit \nyour choice =");
		scanf("%d",&sel);
	}
}

/*��ʼ��*/
slnode *initiate( )
 { slnode *head;
    head = (slnode *)malloc(sizeof(slnode));
    head->next = NULL;
    return (head);
 }   

/*����������*/
int append (slnode *h)
{
	slnode *p,*q;
	int n,i;         /* n ������������Ľ����*/
	datatype a[10];       /* a �����������������*/
	if(h==NULL)
	{
		printf("������δ��ʼ����\n");
		return 0;
	}
	printf("�����뵥��������Ľ����n=");
	scanf("%d",&n);
	printf("�������������������ֵ:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	p=h;
	for(i=0;i<=n-1;i++)
	{
		if ((q=( slnode * )malloc(sizeof(slnode)))==NULL)
		{
			printf("�½��ռ�����ʧ�ܣ�\n");
			return 0;
		}
		q->data=a[i];
		q->next=NULL;
		p->next=q;
		p=q;
	}
	return 1;
}

/*����*/
int  insert (slnode *h, int n)
{
	slnode *p, *q;
	int i, j;              /* i �������λ��*/
	datatype x;          /* x �����������*/
	while(n)
	{
		printf("������������λ�ü�������ݣ�");
		scanf("%d%d",&i,&x);
        p=h;               
        j=0;
		while((p->next!=NULL)&&(j<i-1))
		{
			p=p->next;
			j++;
		}
		if(j!=i-1)
		{
			printf("\n����λ�ò�����\n");
		}
		else
		{
			if ((q=( slnode * )malloc(sizeof(slnode)))==NULL)
			{
				printf("�½��ռ�����ʧ�ܣ�\n");
				return 0;
			}
			q->data=x;
			q->next=p->next;
			p->next=q;
			n--;
		}
	}
	printf("�������!\n");
	return 1;
}

/*ɾ��*/
int deletet (slnode *h, int n)
{
	slnode *p,*s;
	int m;            /*m ���汻ɾ�����ĸ��� */
	datatype x;          /* x ��ɾ������ǰһ����������*/
	p=h;
	m=n;
	while(n)
	{
		printf("�������%d����ɾ������ǰһ���������ݣ�",m-n+1);
		scanf("%d",&x);
		s=search(h,x);
		if(s==NULL)
			continue;
		p=s->next;
		s->next=p->next;
		free(p);
		n--;
	}
	return 1;
}

/*����*/
 slnode * search(slnode *h, datatype x)
{ 
	slnode *p=h->next;
     while(p!=NULL&&p->data!=x)
	 p=p->next;
     return p;
    }
	

/*��ʾ���*/
void print(slnode *h)
{ 
	int i=1;
	h=h->next;
	while(h!=NULL)
 {   
	printf("��%d��������%d\n",i,h->data);
    h=h->next;
	i++;	 
 }
}