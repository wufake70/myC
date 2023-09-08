#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    FILE* fp=NULL;
    char* fname="c_10.txt";
    
    // 新建隐藏文件
    if((fp=fopen(fname,"w"))){
        // 设置隐藏属性（仅适用于Windows系统）
        int result = SetFileAttributesA(fname, FILE_ATTRIBUTE_HIDDEN);
        if (result == 0) {
            printf("Error setting file attributes.\n");
            exit(1);
        }
        printf("new hidden file 'c_10.txt' successful.\n");
        system("pause");
        fclose(fp);
    }

    if(fp=fopen("./Encrypted.flag","w")){
        // 设置隐藏属性（仅适用于Windows系统）
        int result = SetFileAttributesA("./Encrypted.flag", FILE_ATTRIBUTE_HIDDEN);
        if (result == 0) {
            printf("Error setting file attributes.\n");
            exit(1);
        }
        fclose(fp);
    }

    printf("fail new file.\n");
    system("pause > nul");

    return 0;
}