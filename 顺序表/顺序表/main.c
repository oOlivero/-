//
//  main.c
//  顺序表
//
//  Created by Oliver on 2017/10/30.
//  Copyright © 2017年 Olive. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ListIntiSize 100        //初始量
#define ListIncrementSize 10    //增量
#define succeed 1
#define error -1
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
#define ElemType int
#define Status int

typedef struct //线性表的定义
{
    ElemType *elem;     //储存空间地址
    int length;     //当前长度
    int listsize;   //当前容量
    int existence;  //当前线性表是否存在
}List;

void InitList(List *L)  //新建一个线性表
{
    L->elem = (ElemType *)malloc(ListIntiSize * sizeof(ElemType));
    if (!L->elem)
        exit(OVERFLOW);
    L->length = 0;
    L->listsize = ListIntiSize;
    L->existence = 1;
} //IntiList

Status DestroyList(List *L) //摧毁一个线性表
{
    if (L->existence == 1)
    {
        free(L->elem);
        L->existence = 0;
        return succeed;
    }
    else
    {
        return error;
    }
} //DestroyList

Status ClearList(List *L)   //将线性表重置为空表
{
    if (L->existence == 1)
    {
        L->length = 0;
        return succeed;
    }
    else
    {
        return error;
    }
} //ClearList

Status ListEmpty(List L)    //判断线性表是否为空
{
    if (L.length == 0)
        return TRUE;
    else
        return FALSE;
} //ListEmpty

Status ListLength(List L)   //返回线性表数据个数
{
    if (L.existence == 1)
        return L.length;
    else
        return error;
} //ListLength

Status GetElem(List L, int i)  //返回线性表中第i个值
{
    ElemType e;
    if (L.existence == TRUE)
    {
        e = L.elem[i - 1];
        return e;
    }
    else
        return error;
} //GetElem

Status LocateElem(List L, ElemType e)    //返回第一个与e满足compare的元素的位序
{
    int i = 0;
    if (L.existence == TRUE)
    {
        for (; i < L.length; i++)
        {
            if (L.elem[i] == e)
                return i + 1;
        }
        return error;
    }
    else
        return error;
} //LocateElem

Status PriorElem(List L, ElemType cur_e, ElemType *pre_e) //
{
    if (L.existence == TRUE)
    {
        for (int i = 0; i < L.length; i++)
        {
            if (cur_e == L.elem[i] && i != 0)
            {
                *pre_e = L.elem[i - 1];
                return succeed;
            }
        }
        return FALSE;
    }
    else
        return error;
} //PriorElem

Status NextElem(List L, ElemType cur_e, ElemType *next_e)//下一个元素
{
    if (L.existence == TRUE)
    {
        for (int i = 0; i < L.length; i++)
        {
            if (cur_e == L.elem[i] && i != L.length - 1)
            {
                *next_e = L.elem[i];
                return succeed;
            }
        }
        return FALSE;
    }
    else
        return error;
} //NextElem

Status ListInsert(List *L, int i, ElemType e)//插入元素
{
    if (L->existence == TRUE && i >= 1 && i <= ListLength(*L) + 1 )
    {
        if (L->length >= L->listsize)
        {
            ElemType* newbase = (ElemType *)realloc(L->elem, (L->listsize + ListIncrementSize) * sizeof(ElemType));
            if (!newbase)
                exit(OVERFLOW);
            L->elem = newbase;
            L->listsize += ListIncrementSize;
        }
        for (int j = L->length; j >= i; j--)
        {
            L->elem[j] = L->elem[j - 1];
        }
        L->elem[i - 1] = e;
        L->length++;
        return succeed;
    }
    else
        return error;
} //ListInsert

Status ListDelete(List *L, int i, ElemType *e)
{
    if (L->existence == TRUE && i >= 1 && i <= L->length)
    {
        *e = L->elem[i - 1];
        for (int j = i-1; j < L->length; j++)
        {
            L->elem[j] = L->elem[j + 1];
        }
        L->length--;
        return succeed;
    }
    else return error;
} //ListDelete

Status ListCreate(List *L)
{
    char cin[100];
    int e,size=1;
    while(gets(cin),strcmp(cin,"?"))
    {
        if(sscanf(cin, "%d",&e))
            ListInsert(L, size++, e);
        else return error;
    }
    return 0;
}

Status ListPrint(List *L)
{
    if (L->existence == TRUE && L->length != 0)
    {
        for (int i = 1; i <= L->length; i++)
            printf("%d ",GetElem(*L, i));
        puts("");
        return TRUE;
    }
    else
        return error;
}


int main()
{
    int e,loc;
    List demo;
    InitList(&demo);
    ListCreate(&demo);
    printf("List = ");
    ListPrint(&demo);
    printf("List.lenth = %d\n",demo.length);
    scanf("%d",&e);
    printf("%d\n",LocateElem(demo, e));
    scanf("%d",&e);
    printf("%d\n",GetElem(demo,e));
    scanf("%d,%d",&e,&loc);
    ListInsert(&demo, loc, e);
    ListPrint(&demo);
    scanf("%d",&e);
    ListDelete(&demo, e, &loc);
    ListPrint(&demo);
    return 0;
}
/*
2
1
5
4
6
3
7
9
8
?
4
9
10,2
6
*/
