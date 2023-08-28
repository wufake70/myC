#include <stdio.h>
#include <stdlib.h>
#include <openssl/aes.h>
#include <dirent.h>
#include <sys/stat.h>       // 判断是文件夹还是文件

#define AES_BLOCK_SIZE 16


// 解密文件函数
void decryptFile(const char* inputFile, const char* outputFile, const unsigned char* key) {
    // 打开输入文件和输出文件
    FILE* inFile = fopen(inputFile, "rb");
    FILE* outFile = fopen(outputFile, "wb");

    unsigned char inBuffer[AES_BLOCK_SIZE];
    unsigned char outBuffer[AES_BLOCK_SIZE];

    // 创建AES解密上下文并设置密钥
    AES_KEY aesKey;
    AES_set_decrypt_key(key, 128, &aesKey);

    int bytesRead;
    // 逐个解密数据块并写入输出文件
    while ((bytesRead = fread(inBuffer, 1, AES_BLOCK_SIZE, inFile)) > 0) {
        AES_decrypt(inBuffer, outBuffer, &aesKey);
        fwrite(outBuffer, 1, bytesRead, outFile);
    }

    // 关闭文件
    fclose(inFile);
    fclose(outFile);

    // 删除原文件
    remove(inputFile);
    rename(outputFile,inputFile);
    
}

int main() {
    system("chcp 65001");
    const unsigned char key[] = "0123456789abcdef"; // 128-bit (16 bytes) AES密钥
    char inputFile[1024];
    // char encryptedFile[1024];
    char decryptedFile[1024];

    char *extension = NULL; // 查找最后一个点号

    char* path="./";
    DIR* dir=opendir(path);
    if(dir==NULL){
        printf("文件夹打开失败T_T\n");
        exit(EXIT_FAILURE);
    }
    // 文件夹子项
    struct dirent *entry;
    // 文件(夹)状态
    struct stat file_stat;
    char path_1[1024];
    // 读取下一个目录项
    while((entry=readdir(dir))!=NULL){
        if(strcmp(entry->d_name,".")==0||strcmp(entry->d_name,"..")==0||strcmp(entry->d_name,"c_03.exe")==0){
            continue;
        }
        
        strcpy(path_1,path);
        strcat(path_1,entry->d_name);
        // 获取文件(夹)路径信息
        if(stat(path_1,&file_stat)!=0){
            printf("路径信息错误或者没有系统权限T_T\n");
            // exit(EXIT_FAILURE);
            continue;
        }
        
        // 文件夹
        if(S_ISDIR(file_stat.st_mode)){
            continue;
        }
        
        // 只解密 pdf
        extension = strrchr(entry->d_name, '.'); // 查找最后一个点号
        if (extension != NULL) {
            // 比较后缀名
            if (strcmp(extension, ".pdf") != 0) {
                continue;
            }
               
        } else {
            // 没有拓展名
            continue;
        }

        strcpy(inputFile,entry->d_name);
        strcpy(decryptedFile,inputFile);
        strcat(decryptedFile,".tmp");

        // 解密文件
        decryptFile(inputFile, decryptedFile, key);
        printf("文件已解密.\n");

    }

    // 关闭文件夹
    closedir(dir);
    system("pause");

    return 0;
}