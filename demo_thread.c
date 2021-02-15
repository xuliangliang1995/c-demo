//
// Created by 许良 on 2021/2/15.
//
#include <stdio.h>
#include <tinycthread.h>

int PrintHello(void) {
    printf("Run in new thread [%#x]: Hello world !\n", thrd_current());
    return 2;
}

int main() {
    thrd_t new_thread;
    int result = thrd_create(&new_thread, PrintHello, "C lang");
    if (result == thrd_success) {
        printf("Run in Main thread[%#x], created new thread[%#x]\n", thrd_current(), new_thread);
    } else {
        printf("Run in Main thread[%#x], failed to create new thread.\n", thrd_current());
    }

    int res;
    thrd_join(new_thread, &res);
    printf("%d\n", res);
    return 0;
}

