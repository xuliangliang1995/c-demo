//
// Created by 许良 on 2021/2/13.
//
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>

/**
 * 调试环境
 * @param message
 */
void DebugPrint(char *message) {
#ifdef DEBUG
    puts(message);
#endif
}

/**
 * 格式化换行打印
 * @param format
 * @param ...
 */
void Printlnf(char *format, ...) {
    va_list args;
    va_start(args, format);

    vprintf(format, args);
    printf("\n");

    va_end(args);
}

