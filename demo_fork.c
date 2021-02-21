//
// Created by 许良 on 2021/2/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <assert.h>

int main() {
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // 子进程
        printf("hello, I am child (pid : %d)\n", (int) getpid());
    } else {
        // 父进程（当前进程）
        int wc = wait(NULL);
        assert(rc == wc);
        printf("hello, I am parent of %d (pid : %d)\n", wc, (int) getpid());
    }
    return 0;
}


