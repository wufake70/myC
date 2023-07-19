#include <stdio.h>

int main()
{
    // 常量: 520,'a',3.14
    // 或是下面情形
    // # define A 'a'
    
    // 还可以使用 const 将一个变量变为常量，此时只能读取，不能写入
    const int price = 666;
    // price = 9;   // read-only variable

    // 指向常量的指针，则指向的值就不能修改了
    const int *p1 = &price;
    // *p1 = 9;  // 报错
    // 但是任然可修改该指针的指向

    // 常量指针
    int num = 520;
    const int num2 = 888;
    // 指向非常量的常量指针，与指向常量的指针相反
    int * const p2 = &num;
    *p2 = 666;
    // 常量指针指向的值可以修改
    printf("*p2=num=%d",*p2);
    // 但是指针的指向不能修改
    // p2 = &num2; // 只读
    
    // 指向常量的常量指针，指向的值、指向都不可修改。
    const int * const p3 = &num2;
    // *p3 = 99;    // 报错
    // p3 = &price; // 报错

    return 0;
}