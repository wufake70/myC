#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include "c_13Yametekudasai.h"

/*
gcc 编译命令
gcc -o .\test_1.exe .\test_1.c -lwinmm

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
    Sleep(10000); // 播放10秒钟

    // 关闭临时文件和清理资源
    mciSendString("stop mp3", NULL, 0, NULL);
    mciSendString("close mp3", NULL, 0, NULL);
    remove("temp.mp3"); // 删除临时文件
}


int main()
{
    /* 方法一
    // 打开音频文件(需要传入地址)
    mciSendString("open \"D:\\IDM_download\\music\\Yamete kudasai.wav\" type mpegvideo alias mp3", NULL, 0, NULL);

    // 播放音频
    // mciSendString("play mp3", NULL, 0, NULL);
    mciSendString("play mp3 repeat", NULL, 0, NULL);

    // 播放是异步执行的
    // Sleep(10000); // 播放10秒钟
    // mciSendString("stop mp3", NULL, 0, NULL);
    // mciSendString("close mp3", NULL, 0, NULL);
    while(1){};
    
    */

   // 方法二
    /*
    将音频文件转为 .h文件中 一个数组(unsigned char musicData),
    使用工具 bin2h ，语法"bin2h input.mp3 output.h"
    在c源代码中导入该output.h (注意 音频数组变量名)
    运行程序时，将该数组再次写成一个零时mp3文件
    即可 读取播放。
    
    */
   playEmbeddedAudio();

    return 0;
}
