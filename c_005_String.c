#include <stdio.h>
#include <string.h>

/*
在 C 语言中，字符串是以字符数组的形式存储的，
可以通过修改字符数组中的元素来修改字符串。但是，需要注意以下几点：

字符串常量 是只读的，不能被修改。
字符串常量是指用双引号括起来的字符串，
例如"hello"，它们存储在只读的数据段中，不能被修改。
如果尝试修改字符串常量，会导致编译器或操作系统抛出错误。

字符串数组中的每个字符都可以被修改，
但是需要确保字符数组有足够的空间来存储修改后的字符串。
如果字符数组的长度不够，可能会导致数据溢出和内存错误。

修改字符串时需要确保字符串以\0结尾，
以便在输出字符串时能够正确地显示。
\0是字符串的结束标志，表示字符串的结束位置。


*/


int main(){
    char a[] = "hello C";
    // 长度 strlen返回的长度不包含\0(编译时加上的，用于标记字符串结尾)
    printf("%d\n",strlen(a));
    a[0] = 'a';

    // 注意如下声明数组，不指定空间，会报错。
    // int aa[];

    // 拼接 strcat(char *dest, const char *src);
    char b1[7] = "你好";
    // printf(strcat(b1,"世界"));
    printf(strcat(b1,b1));
    printf("\n");
    printf(b1);
    
    
printf("\n==================一个问题=================\n");
    // 一个问题
    char c[6] = "你好";
    printf(c); 
    /*
    无法打印出预期的结果，
    因为所给的长度刚够装下字符串，
    编译时，无法补上"\0",机器会一直往下(下一个内存)读取，
    直到"\0"
    */
    char c2[7] = "世界";
    printf("\n");
    printf(c2);  // 不存在以上问题；
    printf("\n");

    printf("\n//复制\n");
    // 复制 strcpy(char *dest, const char *src);
    char d[] = "Hello World!";
    char d2[30];
    // d2 = d; // 数组名是一个常量指针，不能被赋值。
    strcpy(d2,d);
    printf(d2);
    printf("\n");

    printf("\n//比较\n");
    // 字符串比较,strcmp(const char *str1, const char *str2);
    /*
    如果str1小于str2，返回负数；
    如果str1等于str2，返回0；
    如果str1大于str2，返回正数。
    */
    char e[] = "Hello World!";
    // printf("%d",d==e);  // 比较的是地址值，不是字符串内容。
    printf("%d\n",strcmp("A","a"));
    printf("%d\n",strcmp("A","A"));
    printf("%d\n",strcmp("Aa","A"));

    printf("\n//查找\n");
    // 查找 strchr(const char *str, int c);
    // 查找字符第一次出现的位置,返回该 字符到最后的字符串。
    printf("%s\n",strchr(e,'H'));

    printf("\n//截取\n");
    // 截取
    char s[] = "Hello, world!";
    int start = 7;
    int len = 5;
    char substr[len + 1];
    // s+start 是内存地址计算
    strncpy(substr, s + start, len);
    // 未定义行为
    substr[len] = '\0'; // 保证截取后的字符串的有效性和正确性
    printf( substr);

    // 验证字符串就是字符数组(一段连续的内存空间)
    printf("验证字符串就是字符数组(一段连续的内存空间)");
    printf("\n");
    char w[] = "abcdefg";
    printf(w+1);
    

   

    return 0;







}