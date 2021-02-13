//
// Created by 许良 on 2021/2/13.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    for (int i = 0; i < 5; ++i) {
        printf("Random Value : %d\n", rand());
    }
}

