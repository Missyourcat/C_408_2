#include<iostream>
typedef int ElemType;
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode* next;
}LinkNode;
typedef struct
{
    LinkNode *front, *rear;
}LinkQueue;
void InitQueue(LinkQueue &Q)
{
    Q.front =  Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}
bool isEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void EnQueue(LinkQueue &Q, ElemType x)
{
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->next = NULL;
    s->data = x;
    Q.rear->next = s;
    Q.rear = s;
}
bool DeQueue(LinkQueue &Q, ElemType &x)
{
    if(Q.front == Q.rear)
    {
        return false;
    }
    LinkNode* p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if(Q.rear == p)
    {
        Q.rear = Q.front;
    }
    free(p);
    return true;
}
int main()
{
    LinkQueue Q;
    ElemType x;
    InitQueue(Q);
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 5);
    while (Q.front != Q.rear)
    {
        if(DeQueue(Q,x))
        {
            std::cout << x << "出队\n";
        }
    }
    if(isEmpty(Q))
    {
        std::cout << "队列为空\n";
    }
}