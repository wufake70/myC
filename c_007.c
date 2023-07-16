#include <stdio.h>

int main(){
/*
关系运算符(高)
    <,<=,>,>=,
    ==,!=

逻辑运算符(低)
    !
    &&
    ||
*/

// 短路求值
int a=1,b=2;
(a=0)&&(b=3);   // a=0 逻辑与运算直接错，不会进行b的赋值。
printf("a=%d,b=%d\n",a,b);
(a=2)||(b=3);
printf("a=%d,b=%d\n",a,b);



    return 0;
}