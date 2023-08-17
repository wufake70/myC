#include <stdio.h>
/*
局部变量
    定义在函数内部的变量。
    不能作为返回值。  


全局变量
    定义在全部函数外部的变量，
    作用域为整个程序，程序退出才会释放。
    会自动初始化为0
*/

int main()
{
    // i为局部变量
    int i=520;
    printf("before, i=%d\n",i);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n",i);
    }
    printf("after,i=%d\n",i);
    

    return 0;
}