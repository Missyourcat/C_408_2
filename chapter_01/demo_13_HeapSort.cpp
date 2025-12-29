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
void AdjustDown(ElemType A[], int k, int len)
{
    int i;
    A[0] = A[k];
    for (i = 2 * k; i <= len; i *= 2)
    {
        if (i < len && A[i] < A[i + 1])
        {
            i++;
        }
        if (A[0] >= A[i])
        {
            break;
        }
        else
        {
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}
void BuildMaxHeap(ElemType A[], int len)
{
    for (int i = len / 2; i > 0; i--)
    {
        AdjustDown(A, i, len);
    }
}
void HeapSort(ElemType A[], int len)
{
    
    BuildMaxHeap(A, len);
    for(int i = len;i > 1; i--)
    {
        SWAP(A[i], A[1]);
        AdjustDown(A,1,i-1);
    }
}
void AdjustDown1(ElemType A[], int k, int len)
{
    int dad = k;
    int son = 2*dad + 1;
    while(son <= len)
    {
        if(son + 1 <= len && A[son] < A[son+1])
        {
            son++;
        }
        if(A[son] > A[dad])
        {
            SWAP(A[son], A[dad]);
            dad = son;
            son = 2 * dad +1;
        }
        else
        {
            break;
        }
    }
}
void HeapSort1(ElemType A[], int len)
{
    int i;
    for(i = len/2;i >= 0; i--)
    {
        AdjustDown1(A,i,len);
    }
    SWAP(A[0], A[len]);
    for(i = len - 1; i>0; i--)
    {
        AdjustDown1(A,0,i);
        SWAP(A[0], A[i]);
    }
}
int main()
{
    SSTable ST;
    ST_INIT(ST, 10);
    ElemType A[10] = {3,87,2,93,78,56,61,38,12,40};
    memcpy(ST.elem, A,sizeof(A));
    ST_PRINT(ST);
    // HeapSort(ST.elem, ST.Length - 1 );
    HeapSort1(ST.elem, ST.Length - 1 );
    ST_PRINT(ST);
    return 0;
}