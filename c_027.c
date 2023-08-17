#include <stdio.h>

/*
 c语言的变量有两种生存期
    静态存储期，全局变量，函数，static声明的变量(局部作用域，生存期为程序)
        程序运行期间一直占据空间，直到程序关闭才释放。
    自动存储期，局部变量

存储类型(内存类型)
    auto (自动变量，默认的 )
    register(寄存器)
    static
    extern
    typedef


*/
void f1(void);
void f1(void)
{
    // 静态变量只会初始化一次,并且只在该函数内有效(可读，可写)
    static int count = 0;
    printf("count=%d\n",count);
    count++;
}

int main()
{
    for(int i=0;i<10;i++){
        f1();
    }
    
    return 0;
}