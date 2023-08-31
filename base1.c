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
      



*/