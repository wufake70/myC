#include <stdio.h>
#include <time.h>


int main()
{

    // 获取当前时间戳
    time_t t1=time(NULL);
    // time(&t1);

    /*
    struct tm是一个结构体类型，
    用于表示日期和时间的各个成员，
    如年、月、日、时、分、秒等。
    */
    struct tm *p;

    // 获取当地时间
    p = localtime(&t1);
    printf("%d-%d-%d %d:%d:%d",1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
    /*
    注意:
        tm_year + 1900
        tm_mon + 1
    */

    return 0;
}