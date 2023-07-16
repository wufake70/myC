#include <stdio.h>
#include <ctype.h>

int main()
{
    char rank;
    printf("请输入成绩等级(A.优秀,B.良好,C.中等,D.及格,E.不及格)\
    \n键入对应字母: \
    ");
    scanf("%c",&rank);
    rank = toupper(rank);
    // printf("%c\n",rank);
    // printf("%p\n",rank);
    // printf("%p",&rank);
    
    printf("您的成绩范围在:\t");
    switch (rank)
    {
    case 'A': printf("100~90分\n");
        break;
    case 'B': printf("90~80分\n");
        break;
    case 'C': printf("80~70分\n");
        break;
    case 'D': printf("70~60分\n");
        break;
    case 'E': printf("60~0分\n");
        break;
    
    default: printf("其他\n");
        break;
    }

}