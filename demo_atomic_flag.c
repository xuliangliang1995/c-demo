//
// Created by 许良 on 2021/2/16.
//
#include <stdio.h>
#include <stdatomic.h>
#include <tinycthread.h>
#include <time.h>

atomic_flag flag = ATOMIC_FLAG_INIT;

int Sleep(int seconds) {
    thrd_sleep(&(struct timespec){.tv_sec = seconds}, NULL);
    return 0;
}

int PrintFunc(void) {
    static int count = 0;
    while (atomic_flag_test_and_set(&flag)) {
        count++;
        printf("%d\n", count);
        Sleep(1);
    }
    return count;
}

int TestExchange() {
    atomic_int i = 1;
    int res = atomic_exchange(&i, 2);
    printf("res : %d\n", res);
    printf("i : %d\n", i);
    return 0;
}


int main() {
    TestExchange();
    atomic_flag_test_and_set(&flag);

    thrd_t new_thread;
    thrd_create(&new_thread, PrintFunc, NULL);

    Sleep(5);

    atomic_flag_clear(&flag);

    int res;
    thrd_join(new_thread, &res);

    printf("result: %d", res);

    return 0;
}

