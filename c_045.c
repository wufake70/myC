#include <stdio.h>
#include <string.h>


/*
共用体(联合体)
    所有成员共用一个内存地址
    但是一次只能存储一个成员的值，会覆盖

共用体大小足以容纳其最大成员的大小

优点
    节省内存，数据类型转换

*/

union Test
{
    int i;
    char str[10];
};


int main()
{
    union Test t1;
    t1.i=10;
    strcpy(t1.str,"hello world");
    printf("%d\n",t1.i);
    printf("%s\n",t1.str);
    printf("t1.i: %p\n",(void*)&t1.i);
    printf("t1.str: %p\n",(void*)t1.str);

    
    if((void*)&t1.i==(void*)t1.str){
        printf("True\n");
    }
    printf("%d\n",sizeof(t1));


    return 0;
}