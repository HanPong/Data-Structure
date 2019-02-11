#include <stdio.h>
#include <stdlib.h>
#define NULL 0
#define MaxVerNum 100  /* 最大顶点数设为100 */
typedef char VertexType;  /* 顶点类型设为字符型 */
typedef int  EdgeType;  /* 边的权值设为整型 */
typedef struct
   { VertexType vexs[MaxVerNum];       /* 存放顶点信息 */
      EdgeType  edges[MaxVerNum][MaxVerNum]; /* 存放邻接关系 */
      int  n,e; /*顶点数和边数*/
}Mgraph;
int flag[MaxVerNum];
void CreateMGraph(Mgraph *G)
  {int i,j,k;
   printf("请输入顶点数和边数(输入格式为:顶点数,边数):\n") ;
    scanf("%d,%d",&(G->n),&(G->e));
    printf("请输入顶点信息:\n");
    for(i=0;i<G->n;i++) 
	  scanf("\n%c",&(G->vexs[i])); 
    for(i=0;i<G->n;i++)
        for(j=0;j<G->n;j++) 
            G->edges[i][j]=0;
    printf("请输入每条边对应的两个顶点的序号(输入格式为:i,j):\n");
              for(k=0;k<G->e;k++) 
                   { scanf("\n%d,%d",&i,&j);
                         G->edges[i][j]=1; 
						 G->edges[j][i]=1; }
        } 

void DFSM(Mgraph *G,int k)  /*从Vk出发，深度优先遍历图G*/
  { 
	  int j;
	  printf("%c",G->vexs[k]);
	  flag[k]=1;
	  for(j=0;j<G->n;j++)
		  if(G->edges[k][j]==1&&!flag[j])
			  DFSM(G,j);
   }
void DFSTraveseM(Mgraph *G)
    { int i;
       for (i=0; i<G->n;i++)  flag[i]=0;    /* 给每个顶点一个未访问过标记 */
       for (i=0; i<G->n; i++)
          if (!flag[i]) DFSM(G,i);  /*若顶点vi未访问过,从vi开始深度优先遍历图*/
     }  /* 要特别注意非连通图的遍历 */

void BFSM(Mgraph *G,int k)  /*从Vk出发，广度优先遍历图G*/
 { int i,j; 
   int Q[MaxVerNum],front,rear;
   front=-1;rear=-1;  /* 初始化队列Q */
   printf("%c ",G->vexs[k]); 
   flag[k]=1;
   rear++; Q[rear]=k;  /* k入到队列Q中 */
   while(front!=rear) /* 队列Q不空时 */
    { front++;i=Q[front];
      for (j=0;j<G->n;j++)
     if(G->edges[i][j]==1&&!flag[j]) 
        { printf("%c ",G->vexs[j]); 
          flag[j]=1;
          rear++; Q[rear]=j; /* j入队 */
        }
   }
  }
void BFSTraverseM(Mgraph *G)
 { int i;
   for (i=0;i<G->n;i++) 
     flag[i]=0;
   /* 给所有顶点一个未被访问标记 */
   for (i=0;i<G->n;i++)
     if(!flag[i]) BFSM(G,i); 
   /*若vi未被访问过,从vi 开始进行广度优先遍历*/
  } /* 要特别注意非连通图的遍历 */

void main()
{Mgraph G;
 CreateMGraph(&G);
 BFSTraverseM(&G);
 printf("\n");
 DFSTraveseM(&G);
 printf("\n");
}