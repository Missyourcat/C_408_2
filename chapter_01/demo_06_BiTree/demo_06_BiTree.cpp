#include <iostream>
#include "demo_BiTree.h"
void PreOrder(BiTree p)
{
    if (p != NULL)
    {
        putchar(p->data);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}
void InOrder(BiTree p)
{
    if (p != NULL)
    {
        InOrder(p->lchild);
        putchar(p->data);
        InOrder(p->rchild);
    }
}
void PostOrder(BiTree p)
{
    if (p != NULL)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        putchar(p->data);
    }
}
void LevelOrder(BiTree T)
{
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q, T);
    while (!IsEmpty(Q))
    {
        DeQueue(Q, p);
        putchar(p->data);
        if(p->lchild != NULL)
        {
            EnQueue(Q, p->lchild);
        }
        if(p->rchild != NULL)
        {
            EnQueue(Q, p->rchild);
        }
    }
    
}
int main()
{
    BiTree pnew;             // 新建树结点
    char data;               // 接受数据
    BiTree tree_root = NULL; // 创建树的根节点
    // 创建队列结点
    ptag_t phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;
    while (std::cin.get(data) && data != '\n')
    {
        pnew = (BiTree)calloc(1, sizeof(BiTNode));   // 申请一个初始化为0的树节点的内存空间
        pnew->data = data;                           // 将数据赋值给新节点
        listpnew = (ptag_t)calloc(1, sizeof(tag_t)); // 申请一个指针指向队列的内存空间
        listpnew->p = pnew;                          // 该队列指针的树值为新结点
        if (NULL == tree_root)                       // 如果是树是空的，初始化根节点
        {
            tree_root = pnew; // 根节点指向第一个新节点
            phead = listpnew; // 队头指针指向队列指针
            ptail = listpnew; // 队尾指针指向队列指针
            pcur = listpnew;  // 分链指针指向队列指针
            continue;         // 结束本次循环，开启下一次
        }
        else
        {
            ptail->pnext = listpnew; // 树不为空的情况下，队尾指针将next指向队列指针
            ptail = listpnew;        // 并往后移
        }
        if (NULL == pcur->p->lchild) // 如果分链指针的树结点左孩子为空
        {
            pcur->p->lchild = pnew; // 将左孩子指针指向新的结点
        }
        else if (NULL == pcur->p->rchild) // 如果分链指针的树结点右孩子为空
        {
            pcur->p->rchild = pnew; // 将右孩子指针指向新的结点
            pcur = pcur->pnext;     // 分链指针在队列中往后移动
        }
    }
    std::cout << "\n--------------------先序遍历(根左右)---------------------\n";
    PreOrder(tree_root);
    std::cout << "\n--------------------中序遍历(左根右)---------------------\n";
    InOrder(tree_root);
    std::cout << "\n--------------------后序遍历(左右根)---------------------\n";
    PostOrder(tree_root);
    std::cout << "\n--------------------层次遍历---------------------\n";
    LevelOrder(tree_root);
    return 0;
}