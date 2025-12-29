#include<iostream>
#include <ctime>
typedef int ElemType;
typedef struct
{
    ElemType* elem;
    int TableLen;
}SSTable;
void ST_Init(SSTable &ST, int len)
{
    ST.TableLen = len + 1;
    ST.elem = (ElemType *)malloc(sizeof(ElemType) * ST.TableLen);
    
    srand(time(NULL));
    for(int i = 1; i < ST.TableLen; i++)
    {
        ST.elem[i] = rand() % 100;
    }    
}
void ST_print(SSTable ST)
{
    for(int i = 1;i < ST.TableLen; i++)
    {
        std::cout << ST.elem[i] << " ";
    }
    std::cout << std::endl;
}
int Search_Seq(SSTable ST, ElemType key)
{
    ST.elem[0] = key;
    int i;
    for(i = ST.TableLen - 1;ST.elem[i] != key; i--);
    return i;
}
int BinarySearch(SSTable ST, ElemType key)
{
    int low = 1, high = ST.TableLen , mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(ST.elem[mid] == key)
        {
            return mid ;
        }
        else if (ST.elem[mid] > key)
        {
            high = mid - 1;
        }
        else 
        {
            low = mid + 1;
        }
    }
    return -1;
}
int compare(const void* left,const void* right)
{
    return *(ElemType*)left - *(ElemType*)right;
}
int main()
{
    SSTable ST;
    ElemType Key;
    int pos;
    ST_Init(ST, 5);
    ST_print(ST);
    std::cout << "顺序查找，输入要搜索的数值:" ;
    std::cin >> Key;
    pos = Search_Seq(ST, Key);
    if(pos)
    {
        std::cout << "查找成功,位置位于：" << pos << std::endl;
    }
    else
    {
        std::cout << "失败" << std::endl;
    }
    qsort(ST.elem, ST.TableLen, sizeof(ElemType), compare);
    ST_print(ST);
    std::cout << "二分查找，输入要搜索的数值:" ;
    std::cin >> Key;
    pos = BinarySearch(ST, Key);
    if(pos)
    {
        std::cout << "查找成功,位置位于：" << pos << std::endl;
    }
    else
    {
        std::cout << "失败" << std::endl;
    }
    return 0;

}