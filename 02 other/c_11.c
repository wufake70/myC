#include <stdio.h>
#include <Windows.h>

int main() {
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    
    int numCores = sysinfo.dwNumberOfProcessors;
    
    printf("CPU逻辑核数：%d\n", numCores);
    
    return 0;
}