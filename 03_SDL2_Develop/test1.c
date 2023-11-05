#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <time.h>
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define FONT_SIZE 24
#define LINE_SPACING 5

// 编译命令: gcc .\test1.c -o .\test1.exe -user32 -mwindows


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

HFONT font = NULL;
HWND hwndEdit = NULL;
HWND hwndCount = NULL;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 创建主窗口
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MyWindowClass";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    RegisterClass(&wc);

    HWND hwnd = CreateWindow(
        "MyWindowClass",
        "Window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    // 创建编辑框
    hwndEdit = CreateWindow(
        "EDIT",
        NULL,
        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,
        5, 70, WINDOW_WIDTH - 20, WINDOW_HEIGHT - 160, // 5,70表示左上角的x,y;后面两位表示宽度，高度
        hwnd,
        (HMENU)1,   // wmId
        hInstance,
        NULL
    );

    // 设置字体和颜色
    LOGFONT lf = { 0 };
    lf.lfHeight = FONT_SIZE;
    lf.lfWeight = FW_NORMAL;
    strcpy(lf.lfFaceName, "simhei");
    font = CreateFontIndirect(&lf);
    SendMessage(hwndEdit, WM_SETFONT, (WPARAM)font, TRUE);

    // 创建字符计数标签
    hwndCount = CreateWindow(
        "STATIC",
        "0",
        WS_VISIBLE | WS_CHILD,
        5, WINDOW_HEIGHT - 80, 200, 24,
        hwnd,
        NULL,
        hInstance,
        NULL
    );
    SendMessage(hwndCount, WM_SETFONT, (WPARAM)font, TRUE);

    // 显示窗口
    ShowWindow(hwnd, nCmdShow);

    // 消息循环
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // 清理资源
    DeleteObject(font);

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
        {
            // 关闭窗口和应用程序
            DestroyWindow(hwnd);
            break;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
            
        case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            int wmEvent = HIWORD(wParam);

            // 检查是哪个编辑框发送了消息
            if (wmEvent == EN_CHANGE)
            {
                // 检查编辑框的ID
                if (wmId == 1)
                {
                    // 获取编辑框的文本内容
                    char buffer[GetWindowTextLengthA(hwndEdit)+1]; // 根据需要调整缓冲区大小
                    GetWindowTextA(hwndEdit, buffer, sizeof(buffer));
                    char numstr[10];
                    MessageBox(NULL, buffer, "警告", MB_ICONWARNING | MB_OK);
                    // 处理编辑框的文本内容变化
                    sprintf(numstr, "%d", strlen(buffer)); // 将整数转换为字符串
                    SetWindowText(hwndCount, numstr); // 更新静态文本控件的文本内容
                }
            }
            break;
        }

        case WM_PAINT:
        {
            // 绘制其他文本内容
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            // 设置字体和颜色
            HFONT oldFont = (HFONT)SelectObject(hdc, font);
            SetTextColor(hdc, RGB(0, 0, 0));

            wchar_t countText[50];
            swprintf(countText, sizeof(countText) / sizeof(countText[0]), L"当前时间戳: %ds", time(NULL));
            // 计算字符的长度和宽度
            SIZE textSize;
            GetTextExtentPoint32W(hdc, countText, wcslen(countText), &textSize);
            RECT rect = { 10, 30, 10+textSize.cx, 30+textSize.cy}; // 左上角x,y;右下角x,y
            
            DrawTextW(hdc, countText, -1, &rect, DT_LEFT | DT_WORDBREAK);
            // 恢复字体
            SelectObject(hdc, oldFont);
            EndPaint(hwnd, &ps);
            break;
        }
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
