// demo_BiTree.h - 二叉树和链式队列的定义和声明
#include<iostream>

// 定义二叉树元素类型为字符
typedef char BiElemType;

// 二叉树节点结构体
typedef struct BiTNode
{
    BiElemType data;        // 节点数据
    struct BiTNode* lchild; // 左子节点指针
    struct BiTNode* rchild; // 右子节点指针
}BiTNode, * BiTree;

// 辅助队列使用的结构体，用于存储树节点地址
typedef struct tag
{
    BiTree p;              // 树节点的地址
    struct tag* pnext;     // 下一个辅助节点指针
}tag_t, * ptag_t;

// 定义队列元素类型为二叉树指针
typedef BiTree ElemType;

// 链式队列节点结构体
typedef struct LinkNode
{
    ElemType data;         // 队列元素数据
    struct LinkNode* next; // 下一个节点指针
}LinkNode;

// 链式队列结构体
typedef struct
{
    LinkNode* front;       // 队头指针
    LinkNode* rear;        // 队尾指针
}LinkQueue;

// 初始化队列
void InitQueue(LinkQueue &Q);

// 检查队列是否为空
bool IsEmpty(LinkQueue Q);

// 入队操作
void EnQueue(LinkQueue &Q, ElemType x);

// 出队操作
bool DeQueue(LinkQueue &Q, ElemType &x);
