//
// Created by 许良 on 2021/2/12.
//
#include <stdio.h>
// 定义宏函数
#define MAX(a, b) (a) > (b) ? (a) : (b)

int main() {
    printf("%d", MAX(1, MAX(3, 4)));
    return 0;
}

