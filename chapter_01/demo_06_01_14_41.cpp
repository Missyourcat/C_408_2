#include<iostream>
typedef int BiElemType;
typedef struct BiTNode
{
    BiElemType weight;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode, * BiTree;
typedef struct tag
{
    BiTree data;
    struct tag* next;
}tag_t, *ptag_t;
int wpl_PreOrder(BiTree root, int deep)
{
    // wpl为静态局部变量,类似于全局变量，只会初始化一次
    static int wpl = 0;
    if(root->lchild == NULL && root->rchild ==NULL)
    {
        wpl += deep * root->weight;
    }
    if(root->lchild != NULL)
    {
        wpl_PreOrder(root->lchild, deep + 1);
    }
    if(root->rchild != NULL)
    {
        wpl_PreOrder(root->rchild, deep + 1);
    }
    return wpl;
}
int WPL(BiTree root)
{
    return wpl_PreOrder(root, 0);
}
int main()
{
    BiTree pnew;
    char x;
    BiTree tree_root = NULL;
    ptag_t pcur = NULL, phead = NULL, ptail = NULL, listpnew = NULL;
    while (std::cin.get(x) && x != '\n')
    {
        pnew = (BiTree)calloc(1, sizeof(BiTNode));
        pnew->weight = x - '0';
        listpnew = (ptag_t)calloc(1, sizeof(tag_t));
        listpnew->data = pnew;
        if(tree_root == NULL)
        {
            tree_root = pnew;
            phead = listpnew;
            ptail = listpnew;
            pcur = listpnew;
            continue;
        }
        else
        {
            ptail->next = listpnew;
            ptail = listpnew;
            if(pcur->data->lchild == NULL)
            {
                pcur->data->lchild = pnew;
            }
            else if(pcur->data->rchild == NULL)
            {
                pcur->data->rchild = pnew;
                pcur = pcur->next;
            }
        }
    }
    std::cout << WPL(tree_root) << std::endl;
    return 0;

}