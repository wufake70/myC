#include <stdio.h>

int main()
{
    int a = 100;
    int *p1 = &a;


    // 指向指针的指针
    int **p2 = &p1;
    // 一层接解引用得到p1的值即a的地址值
    printf("*p2%sp1\n",*p2==p1?"==":"!=");
    // 二层解引用
    printf("**p2%sa\n",**p2==a?"==":"!=");

    // 指针数组
    char *cBooks[] = {
        "《C程序设计语言》",
        "《C专家编程》",
        "《C和指针》",
        "《C陷阱和缺陷》",
        "《C Primer Plus》",
    };
    char **byfishC = &cBooks[4];
    char **jiayuLoves[4] = { // 指针指针数组
        &cBooks[0],
        &cBooks[1],
        &cBooks[2],
        &cBooks[3],
    };

    printf("%s\n",*byfishC);
    printf("%d\t%d\t%d\n",sizeof (int *),sizeof byfishC,sizeof jiayuLoves);
    for(int i=0,length=sizeof jiayuLoves/sizeof (void *);i<length;i++){
        printf("%s\n",*jiayuLoves[i]);
    }

    /*
    优点:
        ①避免重复分配内存，
        ②只需要修改一处地方即可，灵活性高。
    
    */


   int b[1][2] = {{1,3}};

    
    

    return 0;

}