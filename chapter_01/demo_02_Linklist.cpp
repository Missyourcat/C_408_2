//
// Created by Missyourcat on 2025/5/21.
//
#include<stdio.h>
#include<stdlib.h>
#include<string>

typedef int ElemType;
typedef struct LNode{
    ElemType data;//数据域
    struct LNode *next;
}LNode, *LinkList;
// typedef struct LNode LNode;        // LNode == struct LNode
// typedef struct LNode *LinkList;    // LinkList == struct LNode *
//LNode*是结构体指针，和LinkList完全等价
void list_head_insert(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));//申请头结点空间，头指针指向头结点
    ElemType x;
    scanf("%d", &x);
    LNode *s;//用来指向申请的新结点
//    s = (LinkList)malloc(sizeof(LNode));
//    s->data = x;
//    s->next = NULL;
//    L->next = s;//头结点的next，指向第一个结点
//    while(x!=9999)
//    {
//        s = (LinkList)malloc(sizeof(LNode));
//        s->data = x;
//        s->next = L->next;//s的next指向原本链表的第一个结点
//        L->next = s;//头结点的next，指向新结点
//        scanf("%d", &x);
//    }
//代码优化版本
    L->next = NULL;
    while(x!=9999)
    {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
}
void print_list(LinkList L)
{
    L = L->next;
    while(L != NULL)
    {
        printf("%3d", L->data);
        L = L->next;
    }
}
void list_tail_insert(LNode *&L)
{
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    ElemType x;
    scanf("%d", &x);
    LNode *s, *r = L;//s是用来指向申请的新结点，r始终指向链表尾部
    while(x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;//新节点给尾结点的next指针
        r = s;//r要指向新的尾部
        scanf("%d", &x);
    }
    r->next = NULL;//让尾结点指向NULL
}
// 按序号查找结点值，NULL代表查找结点不存在
LNode *GetElem(LinkList L, int i)
{
    if(i == 0)
    {
        return L;
    }
    if(i < 1)
    {
        return NULL;
    }
    LNode *p = L->next;
    int j = 1;
    while(p && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}
// 按值查找，返回NULL代表未找到
LNode *LocateELem(LinkList L, ElemType e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}
// 新结点插入第i个位置
bool ListFrontInsert(LinkList L,int i, ElemType e)
// 删除第i个结点
{
    LinkList p = GetElem(L, i - 1);
    if(p == NULL)
    {
        return false;
    }
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
int main()
{
    LinkList L;//L是链表头指针，是结构体指针类型
    // list_head_insert(L);
    list_tail_insert(L);
    print_list(L);
    printf("%d\n", GetElem(L, 1)->data);
    printf("%d\n", LocateELem(L, 1)->data);
    ListFrontInsert(L, 1, 2);
    print_list(L);
    return 0;
}
 