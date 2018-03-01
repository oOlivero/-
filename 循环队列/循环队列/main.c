#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20                       /* 数组最大界限 */
typedef int ElemType;                    /* 数据元素类型 */
typedef  struct
{
    ElemType  a[MAXSIZE];               /* 一维数组子域 */
    int  front,rear;                 /* 头、尾指针子域  */
}SqQueue;                     /* 循环队列的结构体类型 */
SqQueue  Q1;
/*  函数声明  */
void init_Q(SqQueue *Q)
{
    int i;
    Q->front=Q->rear=0;
    for(int i = 0;i<MAXSIZE;i++)
        Q->a[i]=0;
}
void out_Q(SqQueue Q)
{
    int i;
    if(Q.front<=Q.rear)
        for(i=Q.front;i<Q.rear;i++)
            printf("%d ",Q.a[i]);
    else
    {
        for(i=Q.front;i<MAXSIZE;i++)
            printf("%d ",Q.a[i]);
        for(i=0;i<Q.rear;i++)
            printf("%d ",Q.a[i]);
    }
    printf("\n");
}
void EnQueue(SqQueue *Q,ElemType e)
{
    if((Q->rear+1)%MAXSIZE==Q->front)
        exit(-1);
    Q->a[Q->rear]=e;
    Q->rear++;
    Q->rear=Q->rear%MAXSIZE;
}
ElemType DeQueue(SqQueue *Q)
{
    if(Q->front==Q->rear)
        exit(-1);
    int t=Q->front;
    Q->front=(++Q->front)%MAXSIZE;
    return Q->a[t];
}
/*  主函数  */
int main()
{
    int k; ElemType e,x; char ch;
    init_Q( &Q1);          /* 初始化一个空循环队列 */
    do
    {
        printf("\n\n\n");
        printf("\n\n     1. 数据元素e进队列 ");
        printf("\n\n     2. 出队一个元素，返回其值");
        printf("\n\n     3. 结束程序运行");
        printf("\n======================================");
        printf("\n     请输入您的选择 (1,2,3)");
        scanf("%d",&k);
        switch(k)
        {
            case 1:
            {
                printf("\n 进队 e=?");
                scanf("%d",&e);
                EnQueue(&Q1,e);
                out_Q(Q1);
            }
            break;
            case 2:
            {
                x= DeQueue(&Q1);
                printf("\n出队元素 : %d\n", x);
                out_Q(Q1 );
            }
            break;
            case 3: exit(0);
        } /*  switch  */
        printf("\n ----------------");
    }
    while(k>=1 && k<3);
    printf("\n               再见！");
    printf("\n        打回车键，返回。");
    ch=getchar();
    return 0;
}
