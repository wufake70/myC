#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <time.h>
#define FONT_SIZE 20 
#define LINE_SPACING 5

// gcc .\test2.c -o .\test2.exe -user32 -mwindows

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

HFONT font = NULL;
HWND hwndEdit = NULL;
HWND hwndTaskbar=NULL;
HWND hwnd=NULL;
HWND taskmgrWnd=NULL;
int screen_width=0;
int screen_height=0;

char miYao[]="qwe123";
int isLook=1;
int isWrong=0;

BOOL KillProcess(DWORD processId)
{
    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, processId);
    if (hProcess == NULL)
    {
        return FALSE;
    }

    BOOL result = TerminateProcess(hProcess, 0);
    CloseHandle(hProcess);

    return result;
}

// 隐藏任务管理器窗口
BOOL KillTaskmgr()
{
    // 查找任务管理器窗口句柄
    taskmgrWnd = FindWindowA("TaskManagerWindow", NULL);
    if (taskmgrWnd)
    {
        SetForegroundWindow(hwnd);
        // ShowWindow(taskmgrWnd, SW_MINIMIZE);
        DWORD processId;
        GetWindowThreadProcessId(taskmgrWnd, &processId);

        // 通过pid进行删除
        HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, processId);
        if (hProcess == NULL)
        {
            return FALSE;
        }

        BOOL result = TerminateProcess(hProcess, 0); // 立即终止进程
        CloseHandle(hProcess);
        return TRUE;

    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 创建主窗口
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MyWindowClass";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    RegisterClass(&wc);

    // 获取屏幕尺寸
    screen_width = GetSystemMetrics(SM_CXSCREEN);
    screen_height = GetSystemMetrics(SM_CYSCREEN);

    // Alt+F4时，窗口程序被杀掉，但是主程序还在后台
    while(hwnd==NULL&&isLook==1){

        hwnd = CreateWindow(
            "MyWindowClass",
            "Window",
            WS_POPUP | WS_VISIBLE, // 隐藏调整边框
            CW_USEDEFAULT, CW_USEDEFAULT, screen_width, screen_height,
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
            (screen_width-300)/2 , (screen_height-30)/2, 300,25 , // 5,70表示左上角的x,y;后面两位表示宽度，高度
            hwnd,
            (HMENU)1,   // wmId
            hInstance,
            NULL
        );

        // 创建按钮
        HWND hButton = CreateWindowW(
            L"BUTTON",
            L"退出",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            (screen_width+300-80)/2 , (screen_height-90)/2, 40,30 ,
            hwnd,
            (HMENU)2,   // wmid
            NULL,
            NULL
        );

        // 设置输入法为英文输入法
        HKL englishLayout = LoadKeyboardLayout("00000409", KLF_ACTIVATE);

        // 设置字体和颜色
        LOGFONT lf = { 0 };
        lf.lfHeight = FONT_SIZE;
        lf.lfWeight = FW_NORMAL;
        strcpy(lf.lfFaceName, "simhei");
        font = CreateFontIndirect(&lf);
        SendMessage(hwndEdit, WM_SETFONT, (WPARAM)font, TRUE);

        // 隐藏任务栏
        hwndTaskbar = FindWindow("Shell_TrayWnd", NULL);
        ShowWindow(hwndTaskbar, SW_HIDE);

        // 显示窗口
        ShowWindow(hwnd, nCmdShow);

        // 消息循环
        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            KillTaskmgr();
            
        }
    }

    // 清理资源
    DeleteObject(font);
    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CREATE:
        {
            // 使用 SetWindowPos 函数将窗口置前
            SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);        
            break;
        }

        case WM_CLOSE:
        {
            if(isLook==0){
                if(hwndTaskbar!=NULL) ShowWindow(hwndTaskbar, SW_SHOWNORMAL);
                // 将任务管理器窗口移到屏幕左上角并设置为正常大小
                if(taskmgrWnd!=NULL) SetWindowPos(taskmgrWnd, HWND_TOP, 0, 0, 800, 600, SWP_SHOWWINDOW);
                // 关闭窗口和应用程序
                DestroyWindow(hwnd);
            }else hwnd=NULL;
            
            break;
        }

        case WM_DESTROY:
            if(isLook==0) PostQuitMessage(0);
            else hwnd=NULL;
            break;
            
        case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            int wmEvent = HIWORD(wParam);
            // 获取编辑框的文本内容
            char buffer[GetWindowTextLengthA(hwndEdit)+1]; // 根据需要调整缓冲区大小
            GetWindowTextA(hwndEdit, buffer, sizeof(buffer));

            if (wmId == 2 && wmEvent == BN_CLICKED)
            {
                if(strcmp(miYao,buffer)==0){
                    isLook=0;   // 解锁
                    ShowWindow(hwndTaskbar, SW_SHOWNORMAL);
                    exit(0);
                }else{
                    isWrong=1;
                    InvalidateRect(hwnd, NULL, TRUE);   // 强制窗口重绘，否则窗口内容毫无变化

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
            if(isWrong==1) {
                swprintf(countText, sizeof(countText) / sizeof(countText[0]), L"请输入密钥: %ls", L"输入错误");
            }else {
                swprintf(countText, sizeof(countText) / sizeof(countText[0]), L"请输入密钥: ");
            }

            // 计算字符的长度和宽度
            SIZE textSize;
            GetTextExtentPoint32W(hdc, countText, wcslen(countText), &textSize);
            RECT rect = { (screen_width-300)/2, (screen_height-80)/2, (screen_width-300)/2+textSize.cx, (screen_height-80)/2+textSize.cy}; // 左上角x,y;右下角x,y
            
            DrawTextW(hdc, countText, -1, &rect, DT_LEFT | DT_WORDBREAK);
            
            // 恢复字体
            SelectObject(hdc, oldFont);
            EndPaint(hwnd, &ps);
            break;
        }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
