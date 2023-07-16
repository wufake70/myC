#include <stdio.h>
/*
*/
void main(){
    // 布尔类型 _Bool
    // 非0为true，0为false；
    _Bool a = 22;
    printf("%d",a);

    // sizeof运算符
    short a1;
    int a2;
    long a3;
    long int a4;
    long long int a5;
    float a6;
    double a7;
    _Bool a8;
    char a9;
    char b[] = "kdfjkdjakdlkjf";
    printf("short %d\n",sizeof a1);
    printf("int %d\n",sizeof a2);
    printf("long %d\n",sizeof( a3));
    printf("long int %d\n",sizeof a4);
    printf("long long int %d\n",sizeof a5);
    printf("float %d\n",sizeof a6);
    printf("double %d\n",sizeof a7);
    printf("_Bool %d\n",sizeof a8);
    printf("char %d\n",sizeof a9);
    printf("char[] %d\n",sizeof b);
    // printf("char[] %d\n",strlen(b));
printf("========================\n");
    // 符号型数据
    // int == signed int
    int b1 = -10;
    signed int b2 = -11;
    // 无符号型，字符串格式要用 %u
    unsigned int b3 = -99;
    printf("b1:%d\n",b1);
    printf("b2:%d\n",b2);
    printf("b3:%u\n",b3);
    // printf("b1:%d\n");
 



}