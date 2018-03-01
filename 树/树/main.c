# include <stdio.h>
# include <stdlib.h>
typedef int Etype;
typedef struct BiTNode  /* 树结点结构 */
{
    Etype data;
    struct BiTNode *lch,*rch;
}BiTNode;
/* 函数原形声明 */
BiTNode *creat_bt1();
BiTNode *creat_bt2();
void inorder(BiTNode *p);
void numb(BiTNode *p);
BiTNode *t;
int n,n0,n1,n2;
/*  主函数 */
int main()
{
    char ch;
    int k;
    do
    {
        printf("\n\n\n");
        printf("\n\n     1. 建立二叉树方法1 ");
        printf("\n\n     2. 建立二叉树方法2");
        printf("\n\n     3. 中序递归遍历二叉树");
        printf("\n\n     4. 计算树中结点个数");
        printf("\n\n     5. 结束程序运行");
        printf("\n======================================");
        printf("\n     请输入您的选择 (1,2,3,4,5,6)");
        scanf("%d",&k);
        switch(k)
        {
            case 1:t=creat_bt1( );break; /*  调用性质5建立二叉树算法 */
            case 2:t=creat_bt2( );break; /*  调用递归建立二叉树算法   */
            case 3: { inorder(t);                /*  调用中序遍历     */
            printf("\n\n    打回车键，继续。");
            ch=getchar();}
            break;
            case 4:
            {
                n=0;n0=0 ; n1=0; n2=0;  /* 全局变量置0 */
                           numb(t);
                           printf("\n     二叉树结点总数 n=%d",n);
                           printf("\n     二叉树叶子结点数 n0=%d",n0);
                           printf("\n     度为1的结点数 n1=%d",n1);
                           printf("\n     度为2的结点数 n2=%d",n2);
                           printf("\n\n   打回车键，继续。");
                            ch=getchar();
            } break;
            case 5: exit(0);
        } /*  switch  */
        printf("\n ----------------");
    }
    while(k>=1 && k<5);
    printf("\n               再见！");
    printf("\n      打回车键，返回。");
    ch=getchar();
}
/* main */


/* 利用二叉树性质5 ，借助一维数组V 建立二叉树 */
BiTNode *creat_bt1()
{
    BiTNode *t = NULL,*p,*v[20];
    int i,j;
    Etype e;
    /* 输入结点的序号i 、结点的数据e  */
    printf("\n i,data=?");
    scanf("%d%d",&i,&e);
    while(i!=0 && e!=0)              /* 当 i ,e都为0时，结束循环  */
    {
        p=(BiTNode *)malloc(sizeof(BiTNode));
        p->data=e;
        p->lch=NULL;
        p->rch=NULL;
        v[i]=p;
        if (i==1) t=p;                      /* 序号为1的结点是根 */
        else
        {
            j=i/2;
            if(i%2==0) v[j]->lch=p; /* 序号为偶数，做左孩子*/
            else   v[j]->rch=p;  /* 序号为奇数，做右孩子*/
        }
        printf("\n i,data=?");
        scanf("%d,%d",&i,&e);
    }
    return t;
}
/* creat_bt1 */


/* 模仿先序递归遍历方法，建立二叉树 */
BiTNode * creat_bt2()
{
    Etype e;
    BiTNode *t;
    printf("\n data=");
    scanf("%d",&e);
    if(e==0)
        t=NULL;                  /* 对于0值，不分配新结点 */
    else
    {
        t=(BiTNode *)malloc(sizeof(BiTNode));
        t->data=e;
        t->lch=creat_bt2();  /* 左孩子获得新指针值  */
        t->rch=creat_bt2();  /* 右孩子获得新指针值  */
    }
    return(t);
} /* creat_bt2 */


/* 中序递归遍历二叉树  */
void inorder(BiTNode *p)
{
    if (p)
    {
        inorder(p->lch);
        printf("%3d",p->data);
        inorder(p->rch);
    }
} /* inorder  */
/* 利用中序递归遍历二叉树的方法，计算树中结点个数 */
/* 读者可以试着运用先序或后序递归遍历二叉树方法重新编写这一段函数 */  
void numb(BiTNode *p)
{
    if (p)
    {
        numb (p->lch);
        {
            printf("%3d",p->data);
            n++;
            if(p->lch==NULL && p->rch==NULL)
                n0++;
            if((p->lch==NULL && p->rch!=NULL)||(p->lch!=NULL && p->rch==NULL))
                n1++;
            if(p->lch!=NULL && p->rch!=NULL)
                n2++;
        } /*  把访问的功能扩大了 使用n0：统计没有子树，n1：仅有左子树or仅有右子树，n2：有左右子数的情况。*/
        numb (p->rch);
    }
} /* numb  */
