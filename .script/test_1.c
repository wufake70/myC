#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "Yametekudasai.h"
/*
需要 -lwinmm参数

*/


// 写入临时文件并播放
void playEmbeddedAudio()
{
    FILE* fp = fopen("temp.mp3", "wb"); // 以二进制写入模式打开文件
    if (fp == NULL) {
        printf("无法打开临时文件。\n");
        return;
    }
    fwrite(musicData, 1, _size, fp); // 将音频数据写入文件
    fclose(fp);

    // 打开临时文件并播放
    mciSendString("open temp.mp3 alias mp3", NULL, 0, NULL);
    mciSendString("play mp3 repeat", NULL, 0, NULL);

    // 等待播放结束
    // Sleep(10000); // 播放10秒钟
    // while(1){};

    // 关闭临时文件和清理资源
    // mciSendString("stop mp3", NULL, 0, NULL);
    // mciSendString("close mp3", NULL, 0, NULL);
    // remove("temp.mp3"); // 删除临时文件
}

// int main()
// {
//     playEmbeddedAudio();

//     return 0;
// }