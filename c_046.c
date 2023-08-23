#include <stdio.h>
#include <time.h>
/*
枚举类型
    如果一个变量只有几种可能的值，可将其声明为枚举类型
    枚举类型的值和宏定义相似，不同的是该值是整型且从0开始

声明格式
    enum 枚举类型名 {枚举值名，枚举值名，，，}

*/

int main()
{
    // 一周七天，保存为枚举值
    enum Week {sun,mon,tue,wed,thu,fri,sat } today;
    // 分别对应{0,1,2,3,4,5,6}

    // 也可以指定序号 
    // enum Week {sun=1,mon,tue,wed,thu,fri,sat } today;

    struct tm *p;
    // 获取当前时间戳
    time_t t;       
    time(&t);
    
    // 当地时间
    p=localtime(&t);
    today=p->tm_wday;
    printf("%d\n",today);

    switch(today)
    {
        case mon:
        case tue:
        case wed:
        case thu:
        case fri:
            printf("上班日 T_T\n");
            break;
        case sun:
        case sat:
            printf("休息日 \n");
            break;
        default:
            printf("出错了\n");

    }
    

    return 0;
}