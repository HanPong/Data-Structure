#include <stdio.h>
#include <stdlib.h>
#define MAXVALUE 10000 /*最大权值为10000 */
#define MAXLEAF 30 /* 最多有30个叶子结点 */
#define MAXNODE MAXLEAF*2-1 
/* 因哈夫曼树无度为1的结点,总结点数n=n0+n2 。当n0 =30时,根据二叉树性质
n0=n2+1, n2 = n0–1=29，所以哈夫曼树最多有30+29 =59个结点 */
#define MAXBIT 10  
typedef struct 
  {int weight;
   int parent;
   int lchild;
   int rchild;
  }HNodeType;  
typedef struct 
        { int bit[MAXBIT];  /*保存各字符哈夫曼编码的空间*/
           int start;      /* 保存各字符哈夫曼编码的开始位置 */
         }HCodeType;
void Create_HuffMTree(HNodeType HFMTree[ ],int n)
    {
	int m1,m2,x1,x2;
     int i,j;
      for(i=0;i<2*n-1;i++)
         {
		  HFMTree[i].weight=0;
           HFMTree[i].parent=-1;
           HFMTree[i].lchild=-1;
           HFMTree[i].rchild=-1;}
          
      for (i=0;i<n;i++) 
	  {printf("请输入叶子节点的权值:");
        scanf("%d",&HFMTree[i].weight); 
	  }
	  for(i=0;i<n-1;i++) //gouzao haximanshu de n-1 ge jiedian     
    { 
		  x1=x2=MAXVALUE;
          m1=m2=0;
       for (j=0;j<n+i;j++)
          {

		   if(HFMTree[j].parent==-1&&HFMTree[j].weight<x1)
                 {
			       x2=x1;m2=m1;
                   x1=HFMTree[j].weight;  
                   m1=j;
		   }
            else if(HFMTree[j].parent==-1&& HFMTree[j].weight<x2)    
                   {
				x2=HFMTree[j].weight;
                     m2=j;} 
           }
 HFMTree[m1].parent=n+i;
 HFMTree[m2].parent=n+i;      
 HFMTree[n+i].weight=HFMTree[m1].weight+HFMTree[m2].weight;                                            ;
 HFMTree[n+i].lchild=m1;
 HFMTree[n+i].rchild=m2;}
}         

void HuffmanCode(HNodeType HFMTree[ ], HCodeType HuffCode[  ],int n)
 { 
	HCodeType cd;
    int i,j,c,p;
    for(i=0;i<n;i++)
     {cd.start=n-1;
       c=i;
       p=HFMTree[c].parent;
       while(p!=-1)
           { if(HFMTree[p].lchild==c)
	              cd.bit[cd.start]=0;
	         else
	              cd.bit[cd.start]=1;
              cd.start--;
	         c=p;
	         p=HFMTree[p].parent;
           }    
for(j=cd.start+1;j<MAXBIT;j++) 
{
     HuffCode[i].bit[j]=cd.bit[j];
}
     HuffCode[i].start=cd.start; 
 }
} 
void main()
{
	HNodeType HFM[MAXNODE];
 int num;
 int i,j;
 HCodeType HFMCode[MAXLEAF];
 printf("请输入叶子节点数:");
 scanf("%d",&num);
 Create_HuffMTree(HFM,num);
 HuffmanCode(HFM,HFMCode,num);
 for(i=0;i<num;i++)
    {
	 printf("%5d%8d      ",i,HFM[i].weight);
	 for (j=HFMCode[i].start+1;j<MAXBIT;j++)
	 {
      printf ("%d",HFMCode[i].bit[j]);
	 }
      printf("\n");
    }
}