#include <stdio.h>
#include <String.h>

int main()
{
    char a[10][10]={"hello"};
    printf("%s\n",a[0]);
    strcpy(a[3],"hhhh");
    printf("%s\n",a[3]);

    // char str[100];
    // printf("请输入: ");
    // scanf("%s",str);
    // // printf("%s\n",str);
    // char* str2=strchr(str,'.');
    // printf("pdf? %s\n",strcmp(str2,".pdf")==0?"存在":"无");

    return 0;
}