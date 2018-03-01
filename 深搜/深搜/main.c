# include <stdio.h>
# include <stdlib.h>
# define MAX 20

typedef int VexType;

typedef  struct Vnode
{
    VexType data;
    struct Vnode *next;
}Vnode;
/* Vnode是顶点的结点结构 */
typedef Vnode Lgraph[MAX];      /* Lgraph是一维数组类型标识符 */
/* 函数原形声明 */
void creat_L(Lgraph G);
void out_L(Lgraph G);
void dfsL(Lgraph G,int v);
Lgraph Ga;                      /*  Ga是邻接链表的表头数组名  */
int n,e, vis[MAX];
/*  主函数 */
int main()
{
    int v1,i;
    char ch;
    for(i=0;i<MAX;i++) vis[i]=0;     /*  顶点访问的标志数组   */
    creat_L(Ga);                     /*   建立图邻接链表Ga    */
    out_L(Ga);                             /*  输出邻接链表Ga */
    printf("\n ");
    scanf("%d",&v1);
    dfsL(Ga,v1);     /* 从顶点v1开始，对图Ga进行深度优先遍历 */
    printf("\n\n   打回车键，继续。");
    ch=getchar();
}/* main */

/* 建立邻接链表  */
void creat_L(Lgraph G)
{
    Vnode *p,*q;
    int i,j,k;
    printf("输入 n,e=?");
    scanf("%d%d",&n,&e);
    for(i=1; i<=n; i++)
    {
        G[i].data=i;
        G[i].next=NULL;
    }
    for(k=1;k<=e; k++)
    {
        printf("输入 vi,vj=?");
        scanf("%d,%d",&i,&j);
        p=(Vnode *)malloc(sizeof(Vnode));
        p->data=i;
        p->next=G[j].next;
        G[j].next=p;   /* p结点链接到第j条链 */
        q=(Vnode *)malloc(sizeof(Vnode));
        q->data=j;
        q->next=G[i].next;
        G[i].next=q;  /* q结点链接到第i条链  */
    }
}/*  creat_L */


/*  邻接链表的简单输出，为了检查输入是否正确  */
void out_L(Lgraph G)
{
    int i; Vnode *p;
    char ch;
    for (i=1; i<=n; i++)
    {
        printf("\n i=%d",i);
        p=G[i].next;
        while(p!=NULL)
        {
            printf("%5d",p->data);
            p=p->next;
        }
    }
   printf("\n\n   打回车键，继续。");
   ch=getchar();
} /* out_L */


/* 深度优先遍历图 */
void dfsL(Lgraph G,int v)
{
    Vnode *p;
    printf("%3d",G[v].data);
    vis[v]=1; /*  顶点v被访问，标志置1 */
    p=G[v].next;
    while(p)
    {
        v=p->data;
        if(vis[v]==0)
            dfsL(G,v);  /* 顶点v未被访问时继续遍历 */
        p=p->next;
    }
}/* dfs  */

