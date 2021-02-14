//
// Created by 许良 on 2021/2/13.
//
#include <generic_ext.h>
#include <stdlib.h>

#define PLAYER_COUNT 10

int main() {
    // allocate memory
    int *players = malloc(sizeof(int) * PLAYER_COUNT);
    for (int i = 0; i < PLAYER_COUNT; ++i) {
        players[i] = i;
    }
    PrintIntArray(players, PLAYER_COUNT);
    // free memory
    free(players);
    // 释放内存后，指针即时设置为 NULL
    players = NULL;
    return 0;
}

