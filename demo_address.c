
//
// Created by 许良 on 2021/2/26.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("location of code : %p\n", (void *)main);
    printf("location of heap : %p\n", (void *)malloc(1));
    int x = 3;
    printf("location of stack : %p\n", (void *) &x);
    return 0;
}

