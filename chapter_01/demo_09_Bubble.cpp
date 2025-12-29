#include<iostream>
#include<time.h>
typedef int ElemType;
typedef struct
{
    ElemType* elem;
    int Length;
}SSTable;
void ST_INIT(SSTable &ST, int len)
{
    ST.Length = len;
    ST.elem = (ElemType *)malloc(sizeof(ElemType) * ST.Length);
    srand(time(NULL));
    for(int i = 0; i< ST.Length;i++)
    {
        ST.elem[i] = rand()%100;
    }
}
void ST_PRINT(SSTable ST)
{
    for(int i = 0; i < ST.Length ; i++)
    {
        std::cout << ST.elem[i] << " ";
    }
    std::cout << std::endl;
}
void SWAP(ElemType &a, ElemType &b)
{
    ElemType temp;
    temp = a;
    a = b;
    b = temp;
}
void BubbleSort(ElemType A[], int n)
{
    bool flag;
    for(int i =0 ;i < n - 1;i++)
    {
        flag = false;
        for(int j = n-1;j>i;j--)
        {
            if(A[j-1] > A[j])
            {
                SWAP(A[j-1], A[j]);
                flag = true;
            }
        }
        if(false == flag)
        {
            return;
        }
    }
}
int main()
{
    SSTable ST;
    ST_INIT(ST, 10);
    ST_PRINT(ST);
    BubbleSort(ST.elem, ST.Length);
    ST_PRINT(ST);
    return 0;
}