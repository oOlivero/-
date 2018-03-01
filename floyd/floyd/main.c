//
//  main.c
//  floyd
//
//  Created by Oliver on 2017/11/28.
//  Copyright © 2017年 Oliver. All rights reserved.
//

#include <stdio.h>
#include <string.h>
const int MAX = 0x3f3f3f3f;//0x7777777f
int G[5][5];

int floyd(int a[5][5])
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            for(int k=0;k<5;k++)
                if(a[i][k]+a[k][j]<a[i][j])
                    a[i][j]=a[i][k]+a[k][j];
                //a[i][k]+a[k][j]<a[i][j]?a[i][j]=a[i][k]+a[k][j]:0;
    return 0;
}

void Dijkstra(int a[5][5],int n)
{
    int dis[5];
    int flag[5];
    memset(flag,0,sizeof(flag));//顶点设为没有被标记过
    memset(dis,MAX,sizeof(dis));//初始化最短距离
    dis[n]=0;//让n点到n点距离为0
    while(1)
    {
        int min = MAX;//用于寻找最短的边
        int point = MAX;//用于标记下一个要标记的点
        for(int i=0;i<5;i++)
            if(dis[i]<min&&flag[i]==0)
                min = dis[i],point = i;            //找出距离最近的点
        if(point == MAX)break;//未找到标记的点退出循环
        flag[point] = 1;//标记找到的点
        for(int i=0;i<5;i++)
            if(flag[i]==0&&dis[i]>dis[point]+a[i][point])
                dis[i] = dis[point]+a[i][point];
    }
    int i;
    for(i=0;i<4;i++)
        printf("%d ",dis[i]);
    printf("%d\n",dis[i]);
}

int main()
{
    int a[5][5]=
    {
        0,      2,      MAX,    1,      MAX,
        2,      0,      MAX,    5,      2,
        MAX,    MAX,    0,      4,      7,
        1,      5,      4,      0,      MAX,
        MAX,    2,      7,      MAX,    0
    };
    Dijkstra(a, 0);
    
    floyd(a);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            printf ("%d ",a[i][j]);
        puts("");
    }
    return 0;
}
