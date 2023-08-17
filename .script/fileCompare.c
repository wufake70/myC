#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

#define BUFFER_SIZE 1024

int compare_md5(const char* file1, const char* file2) {
    FILE *fp1, *fp2;
    unsigned char md5_file1[MD5_DIGEST_LENGTH];
    unsigned char md5_file2[MD5_DIGEST_LENGTH];
    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    MD5_CTX md5_ctx;
    int i;

    fp1 = fopen(file1, "rb");
    fp2 = fopen(file2, "rb");

    if (!fp1 || !fp2) {
        printf("无法打开文件\n");
        return -1;
    }

    MD5_Init(&md5_ctx);

    while (fread(buffer1, 1, BUFFER_SIZE, fp1) != 0) {
        MD5_Update(&md5_ctx, buffer1, BUFFER_SIZE);
    }

    MD5_Final(md5_file1, &md5_ctx);

    MD5_Init(&md5_ctx);

    while (fread(buffer2, 1, BUFFER_SIZE, fp2) != 0) {
        MD5_Update(&md5_ctx, buffer2, BUFFER_SIZE);
    }

    MD5_Final(md5_file2, &md5_ctx);

    fclose(fp1);
    fclose(fp2);

    for (i = 0; i < MD5_DIGEST_LENGTH; i++) {
        if (md5_file1[i] != md5_file2[i]) {
            return 0; // 文件不同
        }
    }

    return 1; // 文件相同
}

int main() {
    const char* file1 = "path/to/file1";
    const char* file2 = "path/to/file2";

    int result = compare_md5(file1, file2);

    if (result == 1) {
        printf("文件相同\n");
    } else if (result == 0) {
        printf("文件不同\n");
    } else {
        printf("无法比较文件\n");
    }

    return 0;
}