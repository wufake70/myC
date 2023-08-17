#include <stdio.h>

int add(int,int);
int reduce(int,int);
// 函数指针作为参数
int calc(int (*p)(int,int),int,int);

int add(int a,int b)
{
    return a+b;
}
int reduce(int a,int b)
{
    return a-b;
}
int calc(int (*p)(int,int),int a,int b)
{
    return p(a,b);

}


int main()
{
    
    printf("99+1=%d\n",calc(add,99,1));
    printf("99-1=%d",(*calc)(reduce,99,1));
    
    return 0;
}