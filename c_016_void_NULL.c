#include <stdio.h>

int main()
{
    // void指针
    void *p1;
    int a = 100;
    char *str = "hello";
    printf("void指针大小: %d\n",sizeof p1);
    // void可以保存任意类型的指针
    p1 = &a;
    printf("此时为%p\n",p1);
    printf("%d\n",*(int *)p1);  // void * 转换成 int *；
    p1 = str;
    printf("此时为%p\n",p1);
    printf("%s\n",(char *)p1);

    // 其他指针类型也可以转换成void

    // NULL指针(空指针，宏定义)
    // 表示一个不被使用的地址。
    void *p23;       // 未初始化的野指针,指向随机的地址
    // 通常初始化为NULL,避免野指针
    void *p3 = NULL;
    printf("%p\n",p23);
    printf("%p\n",p23);
    // 判断空指针
    printf(p3==NULL?"NULL":"不是NULL");




    return 0;
}