#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char *p = (char *)malloc(sizeof(char) * 20);
    p = "zhangsan"; // p指针指向的是常量区的字符串，所以不能修改，也不能使用free去销毁这部分的内存
    // 打印p
    printf("%s:p = %s\n",__FUNCTION__, p);
    // 对指针p所指向的空间进行释放
    free(p);
    p = NULL;
    return 0;
}
