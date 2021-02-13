//
// Created by 许良 on 2021/2/13.
//
#include <stdio.h>
#include <stddef.h>


int main() {
    char string[12] = "hello world";
    short short_val = 3;
    int int_val = 6;

    // 字符串必须以 NULL 结束， \0。 即：烫烫。。。
    for (int i = 0; i < 11; ++i) {
        printf("%c\n", string[i]);
    }
    printf("%s\n", string);

    char string_zh[] = "你好，中国。";
    wchar_t ws[] = L"你好，中国。";
    return 0;
}

