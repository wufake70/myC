#include <stdio.h>
#include <windows.h>
#include <dirent.h>

int main() {
    const char* path = "D:/.important/myC/02 other/"; // 带有空格的路径
    DIR* dir=opendir(path);
    if(path==NULL){
        printf("T_T\n");
    }
    printf("ok\n");

    return 0;
}