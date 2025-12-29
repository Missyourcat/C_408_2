#include <stdio.h>
int main()
{
    int a, b, max;
    while (scanf("%d%d", &a, &b))
    {
        max = a > b ? a : b; // 三目运算符
        printf("max = %d\n", max);
    }
    int c, d;
    c = 10, d = 1;
    if (c, d - 1) // 不会进入if，逗号表达式整体的值是最后一个表达式的值
    {
        printf("if excute\n");
    }
    /// 逗号表达式的常见使用场景,for的表达式1初始化多个变量用的较多
    for (c = 0, d = 1; c < 10; c++)
    {
    }
    int e = -1, f;
    f = e++ > -1; // 等价f = e>-1;e = e + 1 ;
    printf("e = %d,f = %d\n", e, f);
    int g[3] = {2, 7, 8};
    int *h;
    int i;
    h = g;
    i = *h++; // 先把*h赋值给i，在对h加1
    printf("g[0] = %d,i = %d, *p = %d\n", g[0], i, *h);
    i = h[0]++; // 先把g[0]赋值给i,然后对g[0]加1
    printf("g[0] = %d,i = %d, *p = %d\n", g[0], i, *h);
    short j = 5, k;
    k = j << 1;            // 一个变量移动以后自身不会改变
    printf("k = %d\n", k); // 左移=乘2，结果为10
    k = j >> 1;
    printf("k = %d\n", k); // 右移=除2，结果为2
    j = 0x8011;
    unsigned short l = 0x8011;
    unsigned short m = 0;
    k = j >> 1;
    m = l >> 1;
    printf("k = %d, m = %u \n",k,m);//结果不一样
    j = 5, k = 7; //0101 0111 
    printf("j & k = %d\n", j & k);//按位与 0101
    printf("j | k = %d\n", j | k);//按位或  0111
    printf("j ^ k = %d\n", j ^ k);//按位异或 0010
    printf("~j = %d\n", ~j);//按位取反 1010 1001 1110
    int arr[5] = {8,5,3,5,8}; //1000 0101 0011 0101 1000
    int result = 0; //0000 
    for(int i = 0; i < 5; i++)// 异或运算符有两个特性，一是任何数和零异或得到的是自身，两个相等的数异或得到的是零
    {
        result ^= arr[i]; //1000 1101 1110 1011 0011 
    }
    printf("%d\n",result);
    int o = 10;
    int* p = &o;
    int** p2 = &p;
    printf("sizeof(p2) = %d \n", sizeof(p2));
    printf("**p2 = %d\n", **p2);
    return 0;
}