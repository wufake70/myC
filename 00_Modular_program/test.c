#include <stdio.h>
#include "calculator.h"

int main()
{
    int a,b,d;
    char c;
    printf("Calculator of two int\n");
    printf("'add:+' 'subtract:-' 'multiply:*' 'divide:/'\n");
    printf(": ");
    scanf("%d %c %d",&a,&c,&b);
    // printf("%d %c %d\n",a,c,b);
    
    switch(c){
        case '+':
            d=add(a,b);
            break;
        case '-':
            d=subtract(a,b);
            break;
        case '*':
            d=multiply(a,b);
            break;
        case '/':
            d=divide(a,b);
            break;
        default:
            printf("Error!!\n");
            return 1;
    }

    printf("result: %d\n",d);

    return 0;
}