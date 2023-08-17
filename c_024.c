#include <stdio.h>
/*
返回函数指针的函数声明

int (*select(char a))(int,int)

实现简单计算器


*/

int add(int,int);
int reduce(int,int);
int multiply(int,int);
int divide(int,int);
int calc(int (*p)(int,int),int,int);
int add(int a,int b)
{
    return a+b;
}
int reduce(int a,int b)
{
    return a-b;
}
int multiply(int a,int b)
{
    return a*b;
}
int divide(int a,int b)
{
    return a/b;
}
// 传入函数指针
int calc(int (*p)(int,int),int a,int b)
{
    return p(a,b);
}
// 返回函数指针
int (*select(char a))(int,int)
{
    switch (a)
    {
    case '+': return add;
    case '-': return reduce;
    case 'x': return multiply;
    case '/': return divide;
    
    default: return add;
    }
}
int main()
{
    int a,b;
    char op;    // +,-
    printf("请输入算式: ");
    scanf("%d%c%d",&a,&op,&b);
    printf("%d%c%d=%d",a,op,b,calc(select(op),a,b));
    
    return 0;
}