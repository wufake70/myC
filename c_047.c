#include <stdio.h>


/*
位域
    允许在结构中以位为单位指定成员的宽度(比特位)。
    位域用于有效地利用内存空间，
    使得结构结构成员可以占用较小的存储空间。

    位域要大于所存储的数值
    同时小于数据类型的比特位(int 32bit，整型不能超过32)


*/
int main()
{
    struct Test{
        // 冒号后面指定宽度(比特位)
        unsigned int a:1;   // 只能存储0,1
        unsigned int b:1;
        unsigned int c:2;   // 只存储0,1,2,3
    };// 只占4个字节空间
    struct Test t1;
    t1.a=0;
    t1.b=1;
    t1.c=3;
    printf("a=%d,b=%d,c=%d\n",t1.a,t1.b,t1.c);
    printf("t1的大小:%d\n",sizeof(t1));

    return 0;
}