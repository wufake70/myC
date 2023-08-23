/*
1.数组类型形参的长度无法再函数内求得，只能通过函数外参数传入。

2.int 范围[-pow(2,31),pow(2,31)-1]
  unsizeof int int 范围[0,pow(2,32)-1]

3.  unsigned int size=pow(2,32)-1;
    // 注意 i 和size 的范围
    for(unsigned int i=0;i<size;i++){
        ...
    }

4.  连续申请1字节直到1个g的内存空间，
    最后该程序占用内存空间远超预期一个g。
      申请内存也是需要开销的。

5.  函数参数的执行顺序从右到左(未定义行为)
    int i=1;
    printf("%d 的平方是%d\n",i-1,（i++)*(i++));
    返回2 的平方是2

6.  // 使用内联函数,内联函数只是优化操作，
    // 编译时需要"-O"选项，即"gcc c_036.c -O"

7.  #define STR(s) # s
    这样的宏定义 会将 s参数转换为字符串

8.  // 可变参数 ... 支持多个参数，
    // # __VA_ARGS__ 全转为字符串
    #define SHOWLIST(...) printf(# __VA_ARGS__)

9. 二维数组 a[2][1] 表示第2行第1列的元素

10. for(int i=0;i<1000;i++) printf("%d ",rand()%10);    // 获取10以内的随机数

11. // 通过结构体指针访问成员; .(结构体使用),->(指针使用) 都用于成员选择
    printf("%s \n",(*p).name); // 点号(.)优先级高于星号(*)
    printf("%s \n",p->name);    // 

12.malloc申请空间返回的是无类型的指针，需要强制转换
    (int *)malloc(sizeof(Int)*1000);

13. 在C语言中，函数参数传递是按值传递的，
    这意味着在函数中对参数的修改不会影响到函数外部的变量。
    如果我们想要在函数内部修改指针变量的值,
    需要传递指针的指针（双重指针）作为参数。

14. 字符串结束标志 '\0'。

15. stdlib.h的 exit函数返回0为成功，非零失败
    #define EXIT_SUCCESS 0
    #define EXIT_FAILURE 1

16. 字符串常量不可修改,会报段错误
    char* str="hello world";
    strcpy(str,"niheo");

*/
#include <stdio.h>
#include <string.h>

int main()
{
    char* str="hello world";
    strcpy(str,"niheo");

    return 0;
}