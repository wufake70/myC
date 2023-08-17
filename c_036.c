#include <stdio.h>
/*
宏定义运行效率比函数块，函数需要操作stack，效率稍慢。
宏定义也存在问题

内联函数(编译器会自行选择)，不存在以上两种问题
    // 使用内联函数,内联函数只是优化操作，
    // 编译时需要"-O"选项，即"gcc c_036.c -O"

*/

#define SQUAER(x) ((x)*(x))
// inline 内联函数
inline int square(int x);
inline int square(int x)
{
    return x*x;
}


int main()
{
    int i=1;
    while (i<=100)
    {
        // 宏定义的问题，函数参数执行顺序从右到左
        // printf("%d 的平方是%d\n",i-1,SQUAER(i++));

        // 使用函数，频繁操作stack,效率低
        // printf("%d 的平方是%d\n",i-1,square(i++));

        // 使用内联函数,内联函数只是优化操作，
        // 编译时需要"-O"选项，即"gcc c_036.c -O"
        printf("%d 的平方是 %d\n",i-1,square(i++));

    }
    



    return 0;
}