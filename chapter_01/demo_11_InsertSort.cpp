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
void InsertSort(ElemType* arr, int n)
{
    int i, j, insertVal;
    for(i = 1; i < n; i++)
    {
        insertVal = arr[i];
        for(j = i - 1; j >= 0 && arr[j] > insertVal; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = insertVal;
    }
}
int main()
{
    SSTable ST;
    ST_INIT(ST, 10);
    ST_PRINT(ST);
    InsertSort(ST.elem, ST.Length);
    ST_PRINT(ST);
    return 0;
}