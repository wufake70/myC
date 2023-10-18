#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*
gcc 编译命令
gcc -o .\test.exe .\test.c -mwindows -user32

user32库是Windows操作系统中重要的用户界面库，
提供了与窗口、消息处理和用户输入相关的函数和功能。
*/

// 用于存储自定义字体
HFONT g_hFont = NULL;  
// 自定义文本颜色，这里设置为红色
COLORREF g_textColor = RGB(255, 0, 0);  


// WindowProc 是一个回调函数，用于处理窗口消息的函数。
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE:
        {
            // 使用 SetWindowPos 函数将窗口置前
            SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

            // 创建字体
            g_hFont = CreateFont(
                20,                     // 字体高度
                0,                      // 字体宽度
                0,                      // 字体倾斜度
                0,                      // 字体倾斜度
                FW_BOLD,                // 字体粗细，使用 FW_BOLD 表示加粗字体
                FALSE,                  // 是否斜体
                FALSE,                  // 是否下划线
                FALSE,                  // 是否删除线
                DEFAULT_CHARSET,        // 字符集
                OUT_DEFAULT_PRECIS,     // 输出精度
                CLIP_DEFAULT_PRECIS,    // 剪辑精度
                1,        // 字体质量
                DEFAULT_PITCH | FF_SWISS,   // 字体间距和字体系列
                "Arial"                 // 字体名称
            );

            
            return 0;
        }

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // 设置字体和文本颜色
            HFONT hOldFont = (HFONT)SelectObject(hdc, g_hFont);
            SetTextColor(hdc, g_textColor);

            // 获取窗口客户区的大小
            RECT clientRect;
            GetClientRect(hwnd, &clientRect);

            // 计算文本的矩形区域
            RECT textRect;
            textRect.left = clientRect.left + 50;    // 设置文本的左边界
            textRect.top = clientRect.top + 50;      // 设置文本的上边界
            textRect.right = clientRect.right - 50;  // 设置文本的右边界
            textRect.bottom = clientRect.bottom - 50;// 设置文本的下边界

            // 绘制文本
            SetBkMode(hdc, TRANSPARENT);  // 设置背景模式为透明，确保文本背景不会被绘制
            // 不用系统会乱码
            // DrawText(hdc, "你关不了我,(¬◡¬)✧(¬◡¬ )✧", -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            DrawTextW(hdc, L"你关不了我,(¬◡¬)✧(¬◡¬)✧", -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

            // 恢复原有的字体
            SelectObject(hdc, hOldFont);

            EndPaint(hwnd, &ps);
            break;
        }

        // 关闭窗口(状态栏叉掉)
        case WM_CLOSE:
            // 释放字体资源
            if (g_hFont != NULL)
            {
                DeleteObject(g_hFont);
                g_hFont = NULL;
            }

            hwnd = NULL; // 将 hwnd 设置为 NULL
            DestroyWindow(hwnd);
            return 0;

        case WM_DESTROY:
            // 释放字体资源
            if (g_hFont != NULL)
            {
                DeleteObject(g_hFont);
                g_hFont = NULL;
            }

            hwnd = NULL;  // 将 hwnd 设置为 NULL
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


int main() {
    // 注册窗口类
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;    // WindowProc 是一个回调函数，用于处理窗口消息的函数。
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "MyWindowClass";
    RegisterClass(&wc);

    // 获取屏幕尺寸
    int screen_width = GetSystemMetrics(SM_CXSCREEN);
    int screen_height = GetSystemMetrics(SM_CYSCREEN);

    HWND hwnd=NULL;
    while(hwnd==NULL){
        // 创建窗口
        hwnd = CreateWindow(
            "MyWindowClass",       // 窗口类型
            "hello wrold",          // 窗口名字
            WS_POPUP | WS_VISIBLE | WS_BORDER,
            0,0, screen_width,screen_height,
            NULL,
            NULL,
            NULL,
            NULL
        );

        // 设置窗口样式
        SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED | WS_EX_TRANSPARENT);
        SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 0, LWA_COLORKEY);

        // 显示弹窗
        ShowWindow(hwnd, SW_SHOW);

        // 获取鼠标焦点
        SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) & ~WS_EX_TRANSPARENT);

        // 消息循环
        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            // 设置窗口位置
            // SetWindowPos(hwnd, NULL, rand()%(screen_width-200), rand()%(screen_height-100), 200, 100, SWP_NOZORDER | SWP_NOSIZE);
            SetForegroundWindow(hwnd);
            SetFocus(hwnd);
        }
    }

    return 0;
}