#include <iostream>
#define MaxSize 6
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int front, rear; // 队头队尾
} SqQueue;
void InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
}
bool isEmpty(SqQueue Q)
{
    if (Q.front == Q.rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// 入队
bool EnQueue(SqQueue &Q, ElemType x)
{
    if ((Q.rear + 1) % MaxSize == Q.front)
    {
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}
// 出队
bool DeQueue(SqQueue &Q, ElemType &x)
{
    if (Q.rear == Q.front)
    {
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}
int main()
{
    SqQueue Q;
    InitQueue(Q);
    ElemType x;
    if (isEmpty(Q))
    {
        std::cout << "队列为空\n";
    }
    else
    {
        std::cout << "不为空\n";
    }
    EnQueue(Q, 0);
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 5);// 因为需要判断队空还是队满，需要牺牲一个单位来确定
    while (Q.rear != Q.front)
    {
        if (DeQueue(Q, x))
        {
            std::cout << "出队元素为：" << x << "\n";
        }
        std::cout << "-----------------------\n";
    }
   
    if (!DeQueue(Q, x))
    {
        std::cout << "队列为空,出队失败\n";
    }
    else
    {
        std::cout << "出队元素为：" << x << "\n";
    }
}
