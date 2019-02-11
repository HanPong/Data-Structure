#include <stdio.h>
#include <stdlib.h>
#define MAXNODE 10
typedef char datatype;
typedef struct BiTNode
    { datatype  data;
      struct BiTNode  *lchild,  *rchild;
    } BiTNode,*BiTree;
void CreateBinTree(BiTree *T)  // 以递归方式建立二叉树
{char ch;
  scanf("\n%c",&ch);
  if(ch=='0') 
	  *T=NULL;   // 以0作为空结点的值以结束递归
  else  
  { 
	  *T=(BiTNode*)malloc(sizeof(BiTNode));
             (*T)->data=ch;
              CreateBinTree(&(*T)->lchild);
              CreateBinTree(&(*T)->rchild); 
  }
}
/*BiTree CreateBinTree(BiTree T)  // 以递归方式建立二叉树
{char ch;
  scanf("\n%c",&ch);
  if(ch=='0')  T=NULL;   // 以0作为空结点的值以结束递归
  else  { T=(BiTNode*)malloc(sizeof(BiTNode));
          T->data=ch;
          T->lchild=CreateBinTree(T->lchild);
          T->rchild=CreateBinTree(T->rchild); }
  return(T);
}*/
void PreOrder(BiTree bt)
      { if(bt==NULL) return;
         printf("%3c",bt->data);
         PreOrder(bt->lchild);
         PreOrder(bt->rchild);  }
void InOrderOut(BiTree T)
 {
     BiTree queue[MAXNODE];
	int i=0;
	queue[0]=NULL;
	while(i>=0)
	{
		if(T!=NULL)
		{
			queue[++i]=T;
			T=T->lchild;
		}
		else
		{
			T=queue[i--];
			printf("%3c",T->data);
			T=T->rchild;
		}
		if(T==NULL&&i==0)
			break;

	}





 }
 /*void InOrderOut(BiTree bt)
 {
	BiTree queue[MAXNODE];
	int i=0;
	queue[0]=NULL;
	while(i>=0)
	{
		if(bt!=NULL)
		{
			queue[++i]=bt;
			bt=bt->lchild;
		}
		else
		{
			bt=queue[i--];
			printf("%3c",bt->data);
			bt=bt->rchild;
		}
		if(bt==NULL&&i==0)
			break;

	}
  }
  */
void PostOrder(BiTree bt)
{
	BiTree queue[MAXNODE];
	int b[MAXNODE],i=0;
	queue[0]=NULL;
	do
	{
		if(bt!=NULL)
		{
			queue[++i]=bt;
			b[i]=0;
			bt=bt->lchild;
		}
		else
		{
			bt=queue[i--];
			if(!b[i+1])
			{
				queue[++i]=bt;
				b[i]=1;
				bt=bt->rchild;
			}
			else
			{
				printf("%3c",bt->data);
				bt=NULL;
			}
		}
	}
	while(bt!=NULL||i>0);
}

void LevelOrder(BiTree bt)
  { BiTree queue[MAXNODE];
    int front,rear;
    if(bt==NULL) return;
    front=-1;
    rear=0;
    queue[rear]=bt;
    while(front!=rear)
      {front++;
        printf("%3c",queue[front]->data);
		//Visit(queue[front]->data);
       if(queue[front]->lchild!=NULL)
         { rear++;  queue[rear]=queue[front]->lchild; }
       if(queue[front]->rchild!=NULL)
         { rear++;  queue[rear]=queue[front]->rchild; }
      }
   }
int Allnode(BiTree root)
 {   if(!root)   return 0;
     else  return (1+Allnode(root->lchild)+Allnode(root->rchild));
  }
BiTree Search(BiTree bt, datatype x)
{BiTree p;
  if ( bt )
    { if ( bt->data == x) return bt;
      if ( bt->lchild != NULL)
        { p=Search(bt->lchild,x);
          if(p) return p; }
      if ( bt->rchild != NULL)
        { p=Search(bt->rchild,x);
          if(p) return p; }
     }
  return NULL;
}

/*int n=0;//设计一算法，统计二叉树中度为2的结点总数
void n2(BiTree bt )
     { if(bt!=NULL)
	   {if(bt->lchild!=NULL&&bt->rchild!=NULL)
                n=n+1;
            n2(bt->lchild);
            n2(bt->rchild);  }
      }*/

int n2(BiTree bt)
{
	if (bt==NULL) return 0;
	if ((bt->lchild==NULL)&&(bt->rchild==NULL)) return 0;
	if ((bt->lchild!=NULL)&&(bt->rchild==NULL))	return n2(bt->lchild);
	if ((bt->lchild==NULL)&&(bt->rchild!=NULL))	return n2(bt->rchild);
	if ((bt->lchild!=NULL)&&(bt->rchild!=NULL))	return n2(bt->lchild)+n2(bt->rchild)+1;
}

int CountLeaf(BiTree bt)
  {if(bt==NULL) return(0);
    if(bt->lchild==NULL&&bt->rchild==NULL)  return(1) ;
else return(CountLeaf(bt->lchild)+CountLeaf(bt->rchild));
   }

void main( )
{   BiTree bt,p;
	int sel,n;
	datatype x;
	printf("\n请输入你的选择：1--- Creat，2--- Preorder，3--- Inorder，4--- Postorder，5--- Levelorder，");
	printf("\n6---Allnodenumber，7---Search，8---Degree2nodenumber， 9--- Degree0nodenumber，10---Quit\n");
    scanf("%d",&sel);
	while(sel!=10)
	{
		if(sel==1)
		{
		    CreateBinTree(&bt); // bt=CreateBinTree(bt);
			printf("完成建立！\n");
		}
	    if(sel==2)
		{
			printf("先序为：");
			PreOrder(bt);
             printf("\n");
		}
		if(sel==3)
		{
			printf("中序为：");
			InOrderOut(bt);
             printf("\n");
		}
		if(sel==4)
		{
			printf("后序为：");
			PostOrder(bt);
             printf("\n");
		}
		if(sel==5)
		{
			printf("层次遍历为：");
			LevelOrder(bt);
             printf("\n");
		}

		if(sel==6)
		{
			  printf("总结点数为：");
               printf("%d",Allnode(bt));
               printf("\n");
		}
		if(sel==7)
		{
			printf("请输入要查找的元素：");
			scanf("\n%c",&x);
			p=Search(bt,'c');
             printf("%c",p->data); // printf("%c",Search(bt,'c')->data);
             printf("\n");		}
		if(sel==8)
		{
			printf("度为2的结点数为：");
             printf("%d",n2(bt));// n2(bt);
             printf("%d",n);
            printf("\n");
		}
		if(sel==9)
		{
			printf("叶子结点数为：");
             printf("%d",CountLeaf(bt));
             printf("\n");
		}
		printf("\n请输入你的选择：1--- Creat，2--- Preorder，3--- Inorder，4--- Postorder，5--- Levelorder，");
	printf("\n6---Allnodenumber，7---Search，8---Degree2nodenumber， 9--- Degree0nodenumber，10---Quit\n");
    scanf("%d",&sel);
	}
}
