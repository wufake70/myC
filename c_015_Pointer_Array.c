#include <stdio.h>


int main()
{
    // 使用指针统计字符串长度
    // 指针与数组区别
    /*
    尽管指针，数组都是保存地址指数据，他们不能等同
    指针变量可以进行++,--,
    但是数组名不可以。
    
    
    */

    char *str = "hello world";
    // char str[] = "hello world";
    // printf("%c\t%c",str[10],str[11]);
    // if (str[11]=='\0') printf("true");

    int count=0;
    while(*str++!='\0')
    // while(str[count]!='\0')
    {
        count++;
        printf("%c",str[0]);
    }
    printf("一共有%d个字符。",count);


    // 
    char* name= "_φ(❐_❐✧ 人丑就要多读书";
    // char name[] = "_φ(❐_❐✧ 人丑就要多读书";
    // *name = '9';
    printf("\n%s\n",name);
    // *name 没有任何意义


printf("\n=================\n");
    // (字符)指针数组是数组
    char *p1[5] = {     // 字符串数组
        "Hello world!",
        "Hello C ",
        "Hello Java",
        "Hello Python",
        "Hello Php"
    };
    for(int i=0;i<5;i++) printf("%s\n",p1[i]); 
    // [] 优先级高于 *
    // 每个数组元素存放一个指针变量。


    // 数组指针是指针
    int a[5];
    // 如下初始化是错误的，
    // a是第一个元素的地址，并不是该数组的地址
    // int (*p2)[5]=a;
    // 需要使用& 取地址符
    int (*p2)[5]=&a;
    // (),[]统一优先级，顺序从左到右。
    printf("%p\t%p",a,&a);


    return 0;
}