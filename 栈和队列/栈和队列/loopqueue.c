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
void init_Q(SqQueue *Q);
void out_Q(SqQueue Q);
void EnQueue(SqQueue *Q,ElemType e);
ElemType DeQueue(SqQueue *Q);
/*  主函数  */
int main()
{
    int k;
    ElemType e,x;
    char ch;
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
            case 1:{ printf("\n 进队 e=?");
            scanf("%d",&e);
            EnQueue(SqQueue &Q1,e);
            out_Q(Q1);
        } break;
            case 2:{ x= DeQueue(&Q1);
                printf("\n出队元素 : %d", x);
                out_Q(Q1 );
            } break;
            case 3: exit(0);
        } /*  switch  */
        printf("\n ----------------");
    }
    while(k>=1 && k<3);
    printf("\n               再见！");
    printf("\n        打回车键，返回。");
    ch=getch();
    return 0;
} /* main */

/*  初始化空队列  * /
 
 /*  输出队列的内容  */

/*  不能修改队列头、尾指针 */

/*  进队函数  */

/*  出队函数 */
