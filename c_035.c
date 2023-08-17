#include <stdio.h>
/*
宏定义就是简单滴进行替换(编译之前的预处理过程中)
宏定义的作用域是开始位置到程序结束
可以使用 #undef 来终止宏定义的作用域

#define STR(s) # s
这样的宏定义 会将 s参数转换为字符串

// 可变参数 ... 支持多个参数，
// # __VA_ARGS__ 全转为字符串
#define SHOWLIST(...) printf(# __VA_ARGS__)

*/
#define R 10
#define PI 3.14
#define V PI*R*R*R*4/3
#define MIN(x,y) (((x)<(y))?(x):(y)) // 机械的替换而已
// #define MIN(x,y) (x<y)?x:y  // 需要使用括号来保证优先级

// #define HI "hello world"
#define STR(s) # s

// 可变参数 ... 支持多个参数，
// # __VA_ARGS__ 全转为字符串
#define SHOWLIST(...) printf(# __VA_ARGS__)


int main()
{
    printf("V=%.9f",V);
    printf("\n===========带参的宏定义===========\n");
    int a,b;
    printf("请输入两个整数(空格分开)：");
    scanf("%d %d",&a,&b);
    printf("最小值是：%d",MIN(a,b));

    printf("\n=======================\n");
    printf(STR(hello world));

    printf("\n============可变参数============\n");
    SHOWLIST(Hello world\nhello java);
    



    return 0; 
}