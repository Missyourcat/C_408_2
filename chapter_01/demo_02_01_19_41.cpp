#include <iostream>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
void list_tail_insert(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    ElemType x;
    LinkList m = L;
    LNode *s;
    while (std::cin >> x)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        m->next = s;
        m = s;
    }
    m->next = NULL;
}
void print_list(LinkList L)
{
    LNode *m = L->next;
    while (m != NULL)
    {
        std::cout << m->data << " ";
        m = m->next;
    }
    std::cout << std::endl;
}
void find_middle(LinkList L, LinkList &L2)
{
    L2 = (LinkList)malloc(sizeof(LNode));
    LNode *s1, *s2;
    s1 = s2 = L->next;
    while (s2 != NULL)
    {
        s2 = s2->next;
        if (s2 == NULL)
        {
            break;
        }
        s2 = s2->next;
        if (s2 == NULL)
        {
            break;
        }
        s1 = s1->next;
    }
    L2->next = s1->next;
    s1->next = NULL;
}
void reverse(LinkList &L)
{
    LNode *a, *b, *c;
    a = L->next;
    if (a == NULL)
    {
        return;
    }
    b = a->next;
    if (b == NULL)
    {
        return;
    }
    c = b->next;
    while (c != NULL)
    {
        b->next = a;
        a = b;
        b = c;
        c = c->next;
    }
    b->next = a;
    L->next->next = NULL;
    L->next = b;
}
void merga(LinkList L, LinkList L2)
{
    LNode* a1, * a2, *set;
    set = a1 = L->next;
    a2 = L2->next;
    a1 = a1->next;
    while (a1 != NULL && a2 != NULL)
    {
        set->next = a2;
        a2 = a2->next;
        set = set->next;
        set->next = a1;
        a1 = a1->next;
        set = set->next;
    }
    if(a1 != NULL)
    {
        set->next = a1;
    }
    if(a2 != NULL)
    {
        set->next = a2;
    }
    
}
int main()
{
    LinkList L;
    list_tail_insert(L);
    print_list(L);
    std::cout << "_____________________" << std::endl;
    LinkList L2 = NULL;
    find_middle(L, L2);
    print_list(L);
    print_list(L2);
    std::cout << "_____________________" << std::endl;
    reverse(L2);
    print_list(L);
    print_list(L2);
    std::cout << "_____________________" << std::endl;
    merga(L,L2);
    free(L2);
    print_list(L);
    return 0;
}