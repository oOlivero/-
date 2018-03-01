#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20                       /* 数组最大界限 */
typedef int ElemType;                    /* 数据元素类型 */
typedef  struct
{
    ElemType  a[MAXSIZE];               /* 一维数组子域 */
    int  top;                       /* 栈顶指针子域    */
}SqStack;                     /* 栈的顺序结构体类型 */
SqStack  s1;
/*  函数声明  */
void init_s(SqStack *s)             /*  初始化空栈  */
{
    for(int i=0;i<MAXSIZE;i++)
        s->a[i]=0;
    s->top=0;
}
int out_s(SqStack s)				/*  输出栈的内容  */
{
    return s.a[s.top];
}
void push(SqStack *s,ElemType e)	/*  进栈函数  */
{
    s->a[s->top++] = e;
}
ElemType pop(SqStack *s) 			/*  出栈函数 */
{
    if(s->top==0)
        exit(-1);
    return s->a[--s->top];
}

/*  主函数  */
int main()
{
    int k;
    ElemType e,x;
    char ch;
    init_s( &s1);          /* 初始化一个空栈 */
    do {
        printf("\n\n\n");
        printf("\n\n     1. 数据元素e进栈 ");
        printf("\n\n     2. 出栈一个元素，返回其值");
        printf("\n\n     3. 结束程序运行");
        printf("\n======================================");
        printf("\n     请输入您的选择 (1,2,3)");
        scanf("%d",&k);
        switch(k)
        {
            case 1:
            {
                printf("\n 进栈 e=?");
                scanf("%d",&e);
                push( &s1,e);
                out_s( s1 );
            }break;
            case 2:
            {
                x= pop( &s1);
                printf("\n出栈元素 : %d", x);
                out_s( s1 );

            } break;
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
