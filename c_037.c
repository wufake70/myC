#include <stdio.h>
#include <string.h>
#include <float.h>
struct Book
{
    char title[100];
    char author[100];
    double price;
};

int main()
{
    struct Book book1;
    printf("书籍推荐\n");
    strcpy(book1.title,"《C和指针》");
    strcpy(book1.author,"wufake");
    book1.price=99999.999;
    printf("书名: %s\n作者: %s\n价格: %f\n",book1.title,book1.author,book1.price);
    printf("%f\n",sizeof(FLT_MAX));
    return 0;
}



