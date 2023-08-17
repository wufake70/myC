#include <stdio.h>
#include <ctype.h>

// 指针变量作为返回值，即称为 指针函数
char* getWord(char c);
char* getWord(char c)
{
    // 函数不能返回局部"变量"，也不能返回局部变量指针
    // 局部变量
    char str1[]="Apple",
         str2[]="Banana",
         str3[]="Cat",
         str4[]="Dog",
         str5[]="None";
    
    
    switch(toupper(c))
    {
        // case 'A': return "Apple";
        // case 'B': return "Banana";
        // case 'C': return "Cat";
        // case 'D': return "Dog";
        // default: return "None";

    // 函数不能返回局部"变量"
        case 'A': return str1;
        case 'B': return str2;
        case 'C': return str3;
        case 'D': return str4;
        default: return str5;
    }
    
}
int main()
{
    char input;
    printf("请输入一个字符:");
    scanf("%c",&input);
    printf("%s",getWord(input));

    
    
    return 0;
}