#include <iostream>
#include <time.h>
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int Length;
} SSTable;
void ST_INIT(SSTable &ST, int len)
{
    ST.Length = len;
    ST.elem = (ElemType *)malloc(sizeof(ElemType) * ST.Length);
    srand(time(NULL));
    for (int i = 0; i < ST.Length; i++)
    {
        ST.elem[i] = rand() % 100;
    }
}
void ST_PRINT(SSTable ST)
{
    for (int i = 0; i < ST.Length; i++)
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
void SelectSort(ElemType A[], int n)
{
    int i, j, min;
    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i+1; j < n;j++)
        {
            if(A[j] < A[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            SWAP(A[i], A[min]);
        }
    }
}
int main()
{
    SSTable ST;
    ST_INIT(ST, 10);
    ST_PRINT(ST);
    SelectSort(ST.elem, ST.Length);
    ST_PRINT(ST);
    return 0;
}