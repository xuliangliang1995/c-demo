//
// Created by 许良 on 2021/2/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <assert.h>
#include <fcntl.h>

void ForkDemo1(void) {
    int rc = fork();
    int x = 5;

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // 子进程
        printf("hello, I am child (pid : %d)\n", (int) getpid());
        x = 6;
        printf("x = %d\n", x);
        // exit(0);
    } else {
        // 父进程（当前进程）
        int wc = wait(NULL);
        assert(rc == wc);
        printf("hello, I am parent of %d (pid : %d)\n", wc, (int) getpid());
        printf("x = %d\n", x);
    }
    // 子进程也能执行到这里
    printf(">>>> %d\n", (int)getpid());
}

void ForkDemo2(void) {
    char *file_path = "file/test.txt";
    int fd = open(file_path, O_RDWR);
    int pid_fork = fork();
    assert(pid_fork >= 0);

    if (pid_fork == 0) {
        char buffer[12] = "child-output";
        write(fd, buffer, 12);
        close(fd);
        exit(0);
    } else {
        char buffer[13] = "parent-output";
        write(fd, buffer, 13);
        close(fd);
    }
}

void ForkDemo3(void) {
    int pid_fork = fork();
    assert(pid_fork >= 0);

    if (pid_fork == 0) {
        char *ls = "/bin/ls";
        char *argv[2] = {"-lh", NULL};
        // close(STDOUT_FILENO); // 关闭标准输出
        //execl(ls, "-a", NULL);
        execvp(ls, argv);
        exit(0);
    } else {
        int res;
//    int pid_wait = wait(&res);
//    printf("[%d]: %d\n", pid_wait, res);

        int pid_wait = waitpid(pid_fork, &res, WUNTRACED);
        printf("[%d][%d]: %d\n", (int) getpid(), pid_wait, res);
    }
}

/*void ForkDemo4(void) {
    int pid_fork_1 = fork();
    assert(pid_fork_1 >= 0);

    int tmp_pipe = open("file/pipe", O_RDWR);


    if (pid_fork_1 == 0) {
        int pipe_pair[2] = {STDOUT_FILENO, tmp_pipe};
        pipe(pipe_pair);
        printf("[%d]content from process 1\n", (int) getpid());
        exit(0);
    }

    waitpid(pid_fork_1, 0, WUNTRACED);
    puts(">>>>>>>>");
    close(tmp_pipe);
    int pid_fork_2 = fork();
    assert(pid_fork_2 >= 0);

    if (pid_fork_2 == 0) {
        int pipe_pair[2] = {tmp_pipe, STDIN_FILENO};
        pipe(pipe_pair);
        char buffer[100] = {0};
        int size = read(STDIN_FILENO, buffer, 100);
        assert(size > 0);

        buffer[size] = '\0';
        printf("[%d]%s\n", (int) getpid(), buffer);
        exit(0);
    }

    waitpid(pid_fork_2, 0, WUNTRACED);
    close(tmp_pipe);

}*/

int main() {
    ForkDemo1();
    //ForkDemo2();
    //ForkDemo3();
    return 0;
}




