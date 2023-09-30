#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string.h>
#include <SDL_syswm.h>
#include <Windows.h>


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define FONT_SIZE 24
#define LINE_SPACING 5

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event event;
SDL_bool quit = SDL_FALSE;

void displayText(int x,int y,const char* str,int fontsize) {
    TTF_Font* font = TTF_OpenFont("simhei.ttf", fontsize); // 使用合适的字体文件路径和字号
    SDL_Color color = {255, 0, 0}; // 文本颜色：红色

    SDL_Surface* surface = TTF_RenderUTF8_Solid(font, str, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect textRect = { x,y, surface->w, surface->h };
    SDL_RenderCopy(renderer, texture, NULL, &textRect); // 绘制文本

    // 释放表面和纹理资源
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font); // 关闭字体
}

int word_counts=1024;
int current_word_counts=0;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    char numstr[10]="";
    char* input=malloc(word_counts*sizeof(char));// 存储用户输入的字符串
    if(input==NULL){
        printf("Fail get memory\n");
        return 1;
    }
    input[0]='\0';

    // 初始化
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    // 获取主显示器的宽度和高度
    SDL_DisplayMode displayMode;
    SDL_GetDesktopDisplayMode(0, &displayMode);  // 0 表示主显示器
    int host_Width = displayMode.w;
    int host_Height = displayMode.h;

    // 创建窗口
    window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    // 创建渲染器
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // 设置窗口背景色为白色
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // 清空渲染器，确保窗口背景为白色
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    // 获取句柄
    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);
    SDL_GetWindowWMInfo(window, &wmInfo);
    HWND hwnd = wmInfo.info.win.window;
    SDL_SetWindowInputFocus(window);  // 获取焦点
    // SDL_SetWindowAlwaysOnTop(window, SDL_TRUE);  // 置顶窗口
    // SDL_Delay(1000); // 延时
    // SDL_SetWindowBordered(window, SDL_FALSE);// 隐藏窗口边框
    // SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "提示", "窗口已最小化！", window);
    // 隐藏任务栏图标
    // LONG_PTR exStyle = GetWindowLongPtr(hwnd, GWL_EXSTYLE);
    // SetWindowLongPtr(hwnd, GWL_EXSTYLE, exStyle | WS_EX_TOOLWINDOW);
    // 限制鼠标范围
    // SDL_SetWindowGrab(window, SDL_TRUE);
    // SDL_SetWindowBordered(window, SDL_FALSE);

    // 设置输入法为英文输入法
    HKL englishLayout = LoadKeyboardLayout("00000409", KLF_ACTIVATE);
    if (englishLayout == NULL) {
        printf("Failed to load English keyboard layout.\n");
        return 1;
    }

    // 加载字体
    TTF_Font* font = TTF_OpenFont("simhei.ttf", FONT_SIZE);
    if (!font) {
        printf("Failed to load font: %s\n", TTF_GetError());
        return 1;
    }
    SDL_Color color = { 0, 0, 0, 255 };  // 黑色字体
    while (!quit) {
        // 事件监听
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                quit = SDL_TRUE;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                case SDLK_RETURN:
                    // 清空输入字符串
                    input[0] = '\0';
                    current_word_counts=0;
                    break;
                case SDLK_BACKSPACE:
                    // 删除输入字符串最后一个字符
                    if (strlen(input) > 0) {
                        input[strlen(input) - 1] = '\0';
                        current_word_counts--;
                    }
                    break;
                }
                break;
            case SDL_TEXTINPUT:
                // 追加用户输入的文本到输入字符串
                if(strlen(input)+1>=word_counts){
                    char* temp=malloc(word_counts*sizeof(char));
                    if(temp==NULL){
                        printf("Fail get memory\n");
                        return 1;
                    }
                    temp[0]='\0';
                    strcpy(temp,input);
                    free(input);
                    word_counts+=1024;
                    input=malloc(word_counts*sizeof(word_counts));
                    if(input==NULL){
                        printf("Fail get memory\n");
                        return 1;
                    }
                    strcpy(input,temp);
                    free(temp);
                }
                strcat(input, event.text.text);
                current_word_counts++;
                break;
            }
        }
        // 置顶并获取焦点
        // SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
        // SetForegroundWindow(hwnd);

        // 渲染窗口内容
        SDL_RenderClear(renderer);
        // 渲染输入文本
        if (strlen(input)) {
            // 根据字体和输入文本创建表面,可自动换行
            SDL_Surface* surface = TTF_RenderText_Blended_Wrapped(font, input, color, WINDOW_WIDTH-10);
            // 创建纹理
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
            // 渲染纹理
            SDL_Rect textRect = { 5, 70, surface->w, surface->h };
            SDL_RenderCopy(renderer, texture, NULL, &textRect);
            // 释放表面和纹理资源
            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
        }
        // 其他文本内容
        displayText(WINDOW_WIDTH/2-80,20,"你好，世界！",30);
        sprintf(numstr,"%d",current_word_counts);
        displayText(11,WINDOW_HEIGHT-21,numstr,20);

        // 更新渲染器
        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    free(input);

    return 0;
}
