#include <stdio.h>

int square(int num);
int square(int num)
{
    return num*num;
}
int main()
{
    int num;
    // 声明一个函数类型的指针
    int (*p)(int num);
    // 指向square地址
    p = square;
    printf("请输入一个整数: ");
    scanf("%d",&num);
    printf("%d的平方是 %d",num,p(num));

    return 0;
}