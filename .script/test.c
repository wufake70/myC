#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void printPDFFiles(const char *dirPath) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;

    // Open directory
    dir = opendir(dirPath);
    if (dir == NULL) {
        printf("无法打开目录: %s\n", dirPath);
        return;
    }

    // Read directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Exclude current directory and parent directory
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Build file path
        char filePath[1024];
        sprintf(filePath, "%s/%s", dirPath, entry->d_name);

        // Get file/directory attributes
        if (stat(filePath, &statbuf) == -1) {
            continue;
        }

        // Check if it's a regular file
        if (S_ISREG(statbuf.st_mode)) {
            // Get file name
            char *fileName = entry->d_name;

            // Check file extension for ".pdf"
            int len = strlen(fileName);
            if (len >= 4 && strcmp(fileName + len - 4, ".pdf") == 0) {
                printf("%s\n", filePath);
            }
        }

        // Check if it's a directory
        if (S_ISDIR(statbuf.st_mode)) {
            // Recursively print PDF files in subdirectory
            printPDFFiles(filePath);
        }
    }

    // Close directory
    closedir(dir);
}

int main() {
    const char *dirPath = "C:/"; // C盘根目录路径
    printf("C盘中的PDF文件列表:\n");
    printPDFFiles(dirPath);

    return 0;
}