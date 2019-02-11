#include <stdio.h>
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 10
#define ERROR 0
typedef struct{
 int *elem;
 int length;
 int listsize;
} SqList;
void InitList_Sq(SqList *l)
{
 l->elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
 if(!l->elem) exit(0);
 l->length=0;
 l->listsize=LIST_INIT_SIZE;
}
int InList(SqList *l)
{
 int *p,*newbase;
 p=l->elem;
 while(1)
 {
  for(;p<l->elem+l->listsize;p++)
  {
   scanf("%d",p);if(*p==-1) break;l->length++;
  }
  if((p==l->elem+l->listsize))
  {
   newbase=(int *)realloc(l->elem,(l->listsize+LISTINCREMENT)*sizeof(int));
   p=l->elem+l->length;
   l->listsize=l->listsize+LISTINCREMENT; 
   if(!l->elem) return ERROR;
  }
  if(*p==-1) break;
 }
 return 1; 
}
void PrList(SqList *l)
{
 int *p,i;
 p=l->elem;
 for(;p<l->elem+l->length;p++)
 printf("%d ",*p);
}
int ListInsert_sq(SqList *l,int i,int e)
{
 int *newbase,*p,*q;
 if(i<1||i>l->length) return ERROR;
 if(l->length==l->listsize)
 {
  newbase=(int *)realloc(l->elem,(l->listsize+LISTINCREMENT)*sizeof(int));
  if(!newbase) return ERROR;
  l->elem=newbase;
  l->listsize+=LISTINCREMENT;
 }
 q=l->elem+i-1;
 for(p=l->elem+l->length-1;p>=q;p--)
 *(p+1)=*(p);
 *q=e;
 l->length+=1;
 return 1;
}
int ListDelet_sq(SqList *l,int i)
{
 int *p,e;
 if((i<1)||(i>l->length)) return ERROR;
 p=l->elem+i-1;
 e=*p;
 for(;p<l->elem+l->length-1;p++)
 *p=*(p+1);
 l->length--;
 printf("Ҫɾ����Ԫ���ǣ�%d\n",e);
 return 1;
}
void main()
{
 int i,j,n;
 char a;
 SqList la;
 InitList_Sq(&la);
 printf("������˳����е�Ԫ�أ�\n");
 if(!InList(&la)) return ERROR;
 do
 {
  printf("��������Ҫ����Ԫ�ص�λ�ü�Ԫ�أ�(a,b)\n");
  scanf("%d,%d",&i,&j);
  if(!ListInsert_sq(&la,i,j)) return ERROR;
  printf("�Ƿ���Ҫ����Ԫ�أ���N/Y��");
  getchar();
  scanf("%c",&a);
  if(a=='N'||a=='n') break;
 }while(1);
 do
 { 
  printf("��������Ҫɾ��Ԫ�ص�λ�ã�\n");
  scanf("%d",&i);
  if(!ListDelet_sq(&la,i)) return ERROR;
  printf("�Ƿ���Ҫɾ��Ԫ�أ���N/Y��");
  getchar();
  scanf("%c",&a);
  if(a=='N'||a=='n') break;
 }while(1);
 printf("����˳���Ϊ��\n");
 PrList(&la); 
}