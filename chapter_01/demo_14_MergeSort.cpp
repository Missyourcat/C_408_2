#include<iostream>
#define N 7
typedef int ElemType;

void Merge(ElemType A[], int low, int mid,int high)
{
    static ElemType B[N];
    int i, j, k;
    for(k = low; k <= high; k++)
    {
        B[k] = A[k];
    }
    for(i = low, j = mid + 1, k = i;i <= mid && j <= high; k++)
    {
        if(B[i] <= B[j])
        {
            A[k] = B[i++];
        }
        else
        {
            A[k] = B[j++];
        }
    }
    while (i <= mid)
    {
        A[k++] = B[i++];
    }
    while (j <= high)
    {
        A[k++] = B[j++];
    }
}
void MergeSort(ElemType A[], int low,int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}
void print(int* a)
{
    for(int i = 0; i<N;i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}
int main()
{
    int A[7] = {49, 38, 65, 97, 76, 13, 27};
    MergeSort(A,0,6);
    print(A);
}