#include <iostream>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
void EnQueue(LinkList front, LinkList &rear, ElemType val)
{
    LinkList p;
    if (rear->next == front)
    {
        p = (LinkList)malloc(sizeof(LNode));
        rear->data = val;
        rear->next = p;
        p->next = front;
        rear = p;
    }
    else
    {
        rear->data = val;
        rear = rear->next;
    }
}
void DeQueue(LinkList rear, LinkList &front)
{
    if (rear == front)
    {
        std::cout << "队空\n";
    }
    else
    {
        std::cout << front->data << "出队\n";
        front = front->next;
    }
}

int main()
{
    LinkList front, rear;
    front = (LinkList)malloc(sizeof(LNode));
    rear = front;
    rear->next = front;
    EnQueue(front, rear, 1);
    EnQueue(front, rear, 2);
    EnQueue(front, rear, 3);

    DeQueue(rear, front);
    DeQueue(rear, front);
    DeQueue(rear, front);
    DeQueue(rear, front);
    DeQueue(rear, front);
}