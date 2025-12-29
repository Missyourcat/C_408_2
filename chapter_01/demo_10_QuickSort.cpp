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
void A_PRINT(ElemType A[], int length)
{
    for (int i = 0; i < length; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}
int Partition(ElemType A[], int low, int high)
{
    int x = high + 1;
    ElemType pivot = A[low];
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
        {
            high--;
        }
        A[low] = A[high];
        // A_PRINT(A, x);
        while (low < high && A[low] <= pivot)
        {
            low++;
        }
        A[high] = A[low];
        // A_PRINT(A, x);
        // std::cout << "-----------------------\n";
    }
    A[low] = pivot;
    // A_PRINT(A, x);
    // std::cout << "==========================\n";
    return low;
}
void QuickSort(ElemType A[], int low, int high)
{
    if (low < high)
    {
        int pivotpos = Partition(A, low, high);
        QuickSort(A, low, pivotpos - 1);
        QuickSort(A, pivotpos + 1, high);
    }
}
int main()
{
    SSTable ST;
    ST_INIT(ST, 10);
    ST_PRINT(ST);
    std::cout << "==========================\n";
    QuickSort(ST.elem, 0, 9);
    ST_PRINT(ST);
    std::cout << "==========================\n";
    return 0;
}