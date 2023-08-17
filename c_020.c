#include <stdio.h>
#include <stdarg.h>     // 可变参数的头文件

/*
类型名 函数名(参数列表)
{
    函数体
}
参数列表：
    传值和传址(传指针)、传数组(传地址)、可变参数

    注意: 传地址也是传值，在函数内部修改指针的指向(地址值)，
        需要传入指针的指针，在进行一层解引用来修改

返回值:
    基本数据类型，结构体，指针(数组不可以)


*/

// 传值和传址(传指针)


// 传数组(传地址)
void getArray(int a[10]);
void getArray(int a[10])
{
    for(int i=0;i<10;i++) printf("%d\n",a[i]);
}

// 可变参数
int sum(int n,...);
int sum(int n,...)
{
    int result=0;
    // 定义参数列表
    va_list list;

    // va_start() 宏用于初始化可变参数列表，并将指针指向可变参数的第一个参数。
    va_start(list,n);
    for(int i=0;i<n;i++){
        // va_arg() 宏用于获取下一个可变参数的值，并将指针指向下一个可变参数。
        result += va_arg(list,int);
    }
    // va_end() 宏用于清理可变参数列表，并释放相关资源。
    va_end(list);

    return result;

}
int main()
{
    int a[10] = {1,2,3,4};
    getArray(a);

    // 可变参数
    printf("结果为 %d\n",sum(4,1,2,3,4));

    return 0;
}