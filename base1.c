/*
1. 编译需要openssl的库源码，需要安装openssl，如下操作(非常规):
    ① https://slproweb.com/products/Win32OpenSSL.html 下载 openssl win的exe文件，建议 1.1.1v 且不要light版。
    ② 运行exe，默认选项即可，可自选安装路径。
    ③ 进入openssl的安装目录中 D:\SoftWareSpace\OpenSSL-Win64\include，
      将openssl目录复制到 gcc安装目录中 D:\SoftWareSpace\mingw64\x86_64-w64-mingw32\include。(保证 #include <openssl/aes.h>有效)。
    ④ 将openssl安装目录中的libsslxxx.dll,libcryptoxxx.dll文件复制到 gcc安装目录中lib目录下，
      并改名为libssl.dll,libcrypto.dll。(保证 "gcc -lssl -lcrypto ..." 编译文件时，能找到以上两个库 )

2. gcc 的"-L"表示 指定了在哪一个目录搜索动态链接库文件
        "-l"表示 链接哪一个动态链接库文件

3. 全局变量(静态存储区空间有限)申请大内存的数组，容易出现段错误
    char path_arr[1000][1000000];


4.  code1:  
      char* suffix=NULL;
      strcpy(suffix, strrchr(entry->d_name,'.'));
      // 会出现段错误

    code2:
      char *extension = NULL;
      extension = strrchr(entry->d_name, '.');
      // 可以正常运行
    strrchar返回的指针，strcpy是操作字符串的，所以第一个会报错


5. 编译器在编译和链接过程中使用 pthread 库。需要"-pthread"参数 告诉gcc。
      
6.  释放 malloc 分配的内存块后，并不需要将指针重新指向 NULL。
    将指针赋值为 NULL 是一种良好的编程实践，可以避免悬空指针（dangling pointer）的问题。
    悬空指针是指在释放了内存后，仍然保留着指向已释放内存的指针。
    如果后续代码误用了悬空指针，将导致未定义的行为，可能出现程序崩溃或产生奇怪的结果。

7. gcc "-mwindows" 表示不显示cmd窗口运行程序。

8. 给exe设置图片
    准备图标文件：首先，你需要一个图标文件（通常是ICO文件格式）。确保图标文件的尺寸和位深度符合你的需求。
    创建资源文件：创建一个文本文件，使用扩展名为.rc（例如icon.rc），并将以下内容添加到文件中：
      1 ICON "path/to/your/icon.ico"
    将"path/to/your/icon.ico"替换为图标文件的实际路径。

    生成.res文件：使用windres工具将资源文件编译为.res文件。在命令行中运行以下命令：
      windres icon.rc -O coff -o icon.res
    
    gcc 将icon和c源码一起编译
      gcc -o test.exe test.c icon.res -....

*/