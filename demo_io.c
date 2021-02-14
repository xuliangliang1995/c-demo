//
// Created by 许良 on 2021/2/14.
//
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
    FILE *file = fopen("CMakeLists.txt.bak", "r");
    if (file) {
        printf("open file success .\n");
        int next_char = getc(file);
        while (next_char != EOF) {
            putchar(next_char);
            next_char = getc(file);
        }
        printf("\n");
        // fflush(stdout);
        fclose(file);
    } else {
        puts(strerror(errno));
        perror("fopen");
    }

    for (int i = 0; i < 10; ++i) {
        printf("%d : %s\n", i, strerror(i));
    }

    return 0;
}

