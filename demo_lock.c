//
// Created by 许良 on 2021/2/16.
//
#include <stdio.h>
#include <tinycthread.h>
#include <assert.h>
#include <stdatomic.h>

//_Atomic int count = 0;
mtx_t lock_flag;
int count = 0;

int Counter(void *arg) {
    printf("[%#x]Counter .\n", thrd_current());
    for (int i = 0; i < 1000000; ++i) {
        mtx_lock(&lock_flag);
        count++;
        mtx_unlock(&lock_flag);
    }
    return 0;
}


int main() {
    mtx_init(&lock_flag, mtx_plain); // init plain lock_flag .

    thrd_t thread_1;
    int result_1 = thrd_create(&thread_1, Counter, NULL);
    assert(result_1 == thrd_success);

    thrd_t thread_2;
    int result_2 = thrd_create(&thread_2, Counter, NULL);
    assert(result_2 == thrd_success);

    int res_1, res_2;
    thrd_join(thread_1, &res_1);
    thrd_join(thread_2, &res_2);

    mtx_destroy(&lock_flag); // destroy lock_flag
    printf("%d", count);
    return 0;
}