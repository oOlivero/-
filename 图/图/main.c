# include <stdio.h>
# include <stdlib.h>
# define MAX 20
typedef int VexType;
typedef  VexType Mgraph[MAX][MAX]; /* Mgraph是二维数组类型标识符 */
/* 函数原形声明 */
void creat_mg(Mgraph G);
void out_mg(Mgraph G);
Mgraph G1;                         /*  G1是邻接矩阵的二维数组名  */
int n,e,v0;

/*  主函数 */
int main()
{
    creat_mg(G1);
    out_mg(G1);
    return 0;
}/* main */


/*  建立邻接矩阵  */
void creat_mg(Mgraph G)
{
    int i,j,k;
    printf("\n  n,e=?");
    scanf("%d%d", &n,&e);  /* 输入顶点数n，边数e */
    for(i=1; i<=n;i++)
        for(j=1;j<=n;j++) G[i][j]=0;
    /* 如果是网，G[i][j]=0该为G[i][j]=32767（无穷）*/
    for(k=1;k<=e;k++)                                /* 组织边数的循环  */
    {
        printf("\n  vi,vj=?");
        scanf("%d%d", &i,&j);          /* 输入一条边的两个顶点编号i,j */
        G[i][j]=1; G[j][i]=1;            /* 无向图的邻接矩阵是对称矩阵 */
        /* 如果是网，还要输入边的权值w，再让G[i][j]=w */
    }
} /* creat_mg */


/* 邻接矩阵简单输出，为了检查输入是否正确 */
void out_mg(Mgraph G)
{
    int i,j;
    char ch;
    for(i=1; i<=n;i++)        /*  矩阵原样输出 */
    {
        printf("\n ");
        for(j=1;j<=n;j++)
            printf("%5d",G[i][j]);
    }
    /*  输出所存在的边 */
    for(i=1; i<=n;i++)
        for(j=1;j<=n;j++)
            if(G[i][j]==1)printf("\n 存在边< %d,%d >",i,j);
    printf("\n\n   打回车键，继续。");
    ch=getchar();
} /*  out_mg */
           
           
