
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

memset初始化

calloc在申请内存后会自动初始化为0。
    参数calloc(10,sizeof(int));

memcopy拷贝，拓展空间
    参数: memcpy(pint2,pint,10*sizeof(int));

realloc拓展空间,不会进行初始化，即拓展的空间的值未定义。
    参数: (int *)realloc(pint2,40*sizeof(int));
        会自动释放pint2的内存空间

*/


int main()
{
    printf("===========pint--memset===========\n");
    int *pint=NULL;
    int i;
    pint=(int *)malloc(10*sizeof(int));
    if(pint==NULL){
        exit(1);
    }
    // 初始化，参数: 地址块，初始化的值，空间大小
    memset(pint,0,10*sizeof(int));
    // 遍历
    for(i=0;i<10;i++) printf("%d,",pint[i]);
    free(pint);
    printf("\n==========pstr--calloc============\n");
    pint=(int *)calloc(10,sizeof(int));
    for(i=0;i<10;i++) printf("%d,",pint[i]);
    // free(pint);
    printf("\n==========拓展空间--memcopy============\n");
    pint[8]=8,pint[9]=9;
    for(i=0;i<10;i++) printf("%d,",pint[i]);
    printf("\n");
    int *pint2=NULL;
    pint2=(int *)calloc(20,sizeof(int));
    if(pint2==NULL){
        exit(1);
    }
    //将pint1拷贝到pint2
    memcpy(pint2,pint,10*sizeof(int));
    free(pint);
    for(i=0;i<20;i++) printf("%d,",pint2[i]);
    // free(pint2);
    printf("\n==========拓展空间--realloc============\n");
    pint2[19]=19;
    for(i=0;i<20;i++) printf("%d,",pint2[i]);
    printf("\n");
    int *pint3=NULL;
    pint3=(int *)realloc(pint2,40*sizeof(int));
    if(NULL==pint3){
        exit(1);
    }
    for(i=0;i<40;i++) printf("%d,",pint3[i]);
    free(pint3);

    
    
    return 0;
}