//
// Created by Missyourcat on 2025/4/23.
//
#include<stdio.h>
//顺序表的初始化以及插入操作
#define MaxSize 50
typedef int ElemType;//让顺序表存储其他类型元素时，可以快速完成代码修改
typedef struct{
    ElemType data[MaxSize];
    int length;//顺序表长度
}SqList;
//顺序表插入，L改变，引用地址
bool list_insert(SqList &L, int Position, ElemType element)
{
    //判断Position是否合法,存储空间是否满了
    if(1 < Position && Position <= L.length + 1 && L.length <= MaxSize)
    {
        //后方元素依此后移
        for(int j = L.length; j >= Position; j--)
        {
            L.data[j] = L.data[j - 1];
        }
        L.data[Position - 1] = element;
        L.length++;
        return true;
    }else{
        return false;
    }
}
//顺序表删除
bool list_delete(SqList &L, int Position, ElemType &del)
{
    //判断删除的元素的位置是否合法
    if(Position < 1 || Position > L.length)
    {
        return false;
    }else{
        del = L.data[Position - 1];
        int j;
        for(j = Position; j < L.length ; j++)
        {
            L.data[j - 1] = L.data[j];
        }
        L.length--;
        return true;
    }
}
// 查找位置，没找到返回0
int locate_elem(SqList L, ElemType element)
{
    int i;
    for(i = 0; i < L.length; i++)
    {
        if(L.data[i] == element)
        {
            return i+1;//i是数组下标，加1是顺序表下标
        }
    }
    return 0;//没有循环或者循环结束
}
//打印顺序表
void print_SqList(SqList L)
{
    for(int i = 0; i < L.length; i++)
    {
        printf("\t%d", L.data[i]);
    }
    printf("\n");
}
int main()
{
    SqList L;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;
    bool res = list_insert(L, 2, 4);
    if(res)
    {
        printf("insert SqList success!\n");

    }else{
        printf("insert SqList failed \n");
    }
    print_SqList(L);
    printf("===============================\n");
    ElemType del;
    res = list_delete(L, 3, del);
    if(res)
    {
        printf("delete SqList success!\n");
        printf("del %d\n", del);
    }else{
        printf("delete SqList failed \n");
    }
    print_SqList(L);
    printf("===============================\n");
    int locate = 0;
    locate = locate_elem(L,60);
    if(locate)
    {
        printf("elem locate is %d\n", locate);
    }else{
        printf("don't find!\n");
    }

    return 0;
}