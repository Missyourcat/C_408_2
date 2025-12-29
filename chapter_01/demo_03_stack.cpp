#include <iostream>
#define Maxsize 5

typedef int ElemType;
typedef struct
{
    ElemType data[Maxsize];
    int top;
} SqStack;
void InitStack(SqStack &L)
{
    L.top = -1; // 表示栈空
}
bool StackEmpty(SqStack S)
{
    if (S.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// 入栈
bool Push(SqStack &S, ElemType x)
{
    if (S.top == Maxsize - 1)
    {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}
// 出栈
bool Pop(SqStack &S, ElemType &x)
{
    if (S.top == -1)
    {
        return false;
    }
    x = S.data[S.top--];
    return true;
}
// 获取栈顶元素
bool GetTop(SqStack S, ElemType &x)
{
    if (S.top == -1)
    {
        return false;
    }
    x = S.data[S.top];
    return true;
}
void print_stack(SqStack S)
{
    
    for(int x = 0; x <= S.top; x++)
    {
        std::cout << S.data[x] << " ";
    }
    std::cout << "\n";
    
}
int main()
{
    SqStack S; // 先进后出 FILO LIFO
    bool flag;
    ElemType m;   // 存放拿出的元素
    InitStack(S); // 初始化
    if (flag = StackEmpty(S))
    {
        std::cout << "栈空" << std::endl;
    }
    
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    Push(S, 4);
    Push(S, 4);
    print_stack(S);
    while (S.top != -1)
    {
        if (flag = GetTop(S, m))
        {
            std::cout << "栈顶元素为: " << m << "\n";
        }
        if (flag = Pop(S, m))
        {
            std::cout << "弹出元素为: " << m << "\n";
        }
        std::cout << "----------------------\n";
    }
    if (flag = StackEmpty(S))
    {
         std::cout << "栈空:" << S.top << "\n";
    }
   
}