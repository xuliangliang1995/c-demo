//
// Created by 许良 on 2021/2/15.
//
#include <stdio.h>
#include <tinycthread.h>
#include <assert.h>
#include <stdatomic.h>

//_Atomic int count = 0;
atomic_int count = 0;

int Counter(void *arg) {
    printf("[%#x]Counter .\n", thrd_current());
    for (int i = 0; i < 1000000; ++i) {
        count++;
    }
    return 0;
}


int main() {
    thrd_t thread_1;
    int result_1 = thrd_create(&thread_1, Counter, NULL);
    assert(result_1 == thrd_success);

    thrd_t thread_2;
    int result_2 = thrd_create(&thread_2, Counter, NULL);
    assert(result_2 == thrd_success);

    int res_1, res_2;
    thrd_join(thread_1, &res_1);
    thrd_join(thread_2, &res_2);
    printf("%d", count);
    return 0;
}