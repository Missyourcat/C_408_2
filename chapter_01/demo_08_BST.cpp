#include<iostream>
typedef int KeyType;
typedef struct BSTNode
{
    KeyType key;
    struct BSTNode* lchild, * rchild;
}BSTNode, *BSTree;
int BST_insert(BSTree &T, KeyType K)
{
    if(T == NULL)
    {
        T = (BSTNode*)calloc(1, sizeof(BSTNode));
        T->key = K;
        return 1;
    }
    BSTree p = T,parent;
    while (p)
    {
        parent = p;
        if(p->key == K)
        {
            return 0;
        }
        else if(K < p->key)
        {
            p = p->lchild;
        }
        else
        {
            p = p->rchild;
        }
    }
    BSTree pnew = (BSTree)calloc(1, sizeof(BSTNode));
    pnew->key = K;
    if(K > parent->key)
    {
        parent->rchild = pnew;
    }
    else
    {
        parent->lchild = pnew;
    }
    return 1;
}
void Creat_BST(BSTree &T, KeyType str[], int n)
{
    T = NULL;
    int i =0;
    while(i < n)
    {
        BST_insert(T,str[i]);
        i++;
    }
}
BSTNode* BST_Search(BSTree T, KeyType key, BSTree &p)
{
    p = NULL;
    while(T!=NULL&&key!=T->key)
    {
        p = T;
        if(key < T->key)
        {
            T = T->lchild;
        }
        else
        {
            T = T->rchild;
        }
    }
    return T;
}
void InOrder(BSTree T)
{
    if(T!=NULL)
    {
        InOrder(T->lchild);
        std::cout << T->key << " ";
        InOrder(T->rchild);
    }
}
void DeleteNode(BSTree &ST,KeyType x)
{
    if(ST == NULL)
    return ;
    if(ST->key > x)
    {
        DeleteNode(ST->lchild,x);
    }
    else if (ST->key < x)
    {
        DeleteNode(ST->rchild,x);
    }
    else
    {
        if(ST->lchild == NULL)
        {
            BSTree tempNode = ST;
            ST = ST->rchild;
            free(tempNode);
        }
        else if (ST->rchild == NULL)
        {
            BSTree tempNode = ST;
            ST = ST->lchild;
            free(tempNode);
        }
        else
        {
            BSTree tempNode = ST->lchild;
            while(tempNode->rchild != NULL)
            {
                tempNode = tempNode->rchild;
            }
            ST->key = tempNode->key;
            DeleteNode(ST->lchild, tempNode->key);
        }
    }
    
}
int main()
{
    BSTree T = NULL;
    BSTree parent, search;
    KeyType str[7] = {50, 21, 66, 28, 40, 79, 58};
    Creat_BST(T,str,7);
    InOrder(T);
    std::cout<<std::endl;
    search = BST_Search(T, 40, parent);
    if(search)
    {
        std::cout << "找到结点，值为" << search->key << std::endl;
    }
    else
    {
        std::cout << "未找到" << "\n";
    }
    DeleteNode(T, 40);
    InOrder(T);
    return 0;
}