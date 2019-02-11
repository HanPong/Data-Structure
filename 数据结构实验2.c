#include <stdio.h>
#include <malloc.h>

#define MaxSize 50

typedef char ElemType;

typedef struct
{
    ElemType elem[MaxSize];
    int length;
}SqList;

void InitList(SqList *L)   /* 初始化顺序表 */
{
    L=(SqList *)malloc(sizeof(SqList));
    L->length=0;
}

void CreateListR(SqList *L,ElemType a[],int n)  /*创建顺序表      */
{

    int i;
    for(i=0;i<n;i++)
    L=(SqList *)malloc(sizeof(SqList));
    L->elem[i]=a[i];
    L->length++;
}

void DispList(SqList *L)   /* 输出顺序表 */
{
    int i;
    if(ListEmpty(L)) return;
    for(i=0;i<L->length;i++)
        printf("%c",L->elem[i]);
    printf("\n");
}

int ListLength(SqList *L)   /* 求顺序表的长度 */
{
    return(L->length);
}

int ListEmpty(SqList *L)  /* 求顺序表是否为空 */
{
    return(L->length==0);
}

int GetElem(SqList *L,int i,ElemType e)  /*求顺序表中某个数据的元素值 */
{
    if(i<1||i>L->length)
        return 0;
    else
        e=L->elem[i-1];
    return 1;
}

int LocateElem(SqList *L,ElemType e)    /*按值查找元素*/
{
    int i=0;
    while(i<L->length&&L->elem[i]!=e) i++;
    if(i>=L->length)
        return 0;
    else
        return i+1;
}

int ListInsert(SqList *L,int i,ElemType e)  /*按i位置插入元素*/
{
    int j;
    if(i<1||i>L->length+1)
        return 0;
    i--;
    for (j=L->length;j>i;j--)
        L->elem[j]=L->elem[j-1];
    L->elem[i]=e;
    L->length++;
    return 1;
}

int ListDelete(SqList *L,int i,ElemType e)  /*删除某个位置的元素*/
{
    int j;
    if (i<1||i>L->length)
        return 0;
    i--;
    e=L->elem[i];    /*e中的放elem[i]有何用..以后没用到*/
    for(j=i;j<L->length-1;j++)
        L->elem[j]=L->elem[j+1];
    L->length--;
    return 1;
}

void DestroyList(SqList *L)   /*销毁链表*/
{
    free(L);
}

void main()
{
    SqList L;
    ElemType a[]={'a','b','c','d'};
    int c;
    int e;
    while(1)
    {
    printf("Please Choose the step you want ?\n\n");
    scanf("%d",&c);
    if(c==0) break;
    switch(c)
    {
    case 1: InitList(&L);break;
    case 2: CreateListR(&L,a,4);break;
    case 3: DispList(&L);break;
    case 4: printf("long %d", ListLength(&L));break;
    case 5: printf("%d",ListEmpty(&L));break;
    case 6: GetElem(&L,3,e);break;
    case 7: LocateElem(&L,'a');break;
    case 8: ListInsert(&L,4,'f');break;
    case 9: DispList(&L);break;
    case 10: ListDelete(&L,3,e);break;
    case 11: DispList(&L);break;
    case 12: DestroyList(&L);break;
    default: printf("error data");break;
    }

    }

}