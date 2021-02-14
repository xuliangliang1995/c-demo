//
// Created by 许良 on 2021/2/14.
//
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    time(&current_time);
    printf("%ld", current_time);

    return 0;
}
