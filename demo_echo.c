//
// Created by 许良 on 2021/2/14.
//
#include <stdio.h>

int main() {
    char buffer[4];
    // gets 等文本类型的命令，不要去操作二进制文件
    while (fgets(buffer, 4, stdin)) {
        printf("%s", buffer);
    }
    return 0;
}