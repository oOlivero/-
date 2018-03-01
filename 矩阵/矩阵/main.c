#include <stdio.h>

const int max = 20;
int a[max][max];
int b[max][max];
int final[max][max];
int n;

void Trans(int a[max][max])
{
    int t;                                                  //用于交换
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)                                //0到i交换，不能是0到n-1，否则交换两次
            t=a[i][j],a[i][j]=a[j][i],a[j][i]=t;            //交换
}

void Mul(int a[max][max],int b[max][max],int final[max][max])
{
    for(int i=0;i<n;i++)                                    //i为行数
        for(int j=0;j<n;j++)                                //j为列数
            for(int k =0;k<n;k++)
                final[i][j]+=a[i][k]*b[k][j];
}

void Print(int a[max][max])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
            printf("%d ",a[i][j]);
        printf("%d\n",a[i][j]);
    }
}
int main()
{
    while(scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                    scanf("%d",&a[i][j]);
        Print(a);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&b[i][j]);
        Print(b);
        Trans(a);
        Print(a);
        Mul(a, b, final);
        Print(final);

    }
    return 0;
}
