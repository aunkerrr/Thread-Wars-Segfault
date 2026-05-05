#include <stdio.h>
#include <stdlib.h>
#include "fire.h"
#include "shared.h"

int main(void) {
    pthread_t menu;
    int start_game = show_fire_menu();

    if (start_game == 1) {
        // TODO: Initialize Arena
        // TODO: Spawn Robot Threads
        // TODO: Start Game Loop
        printf("Entering the Cyber-Arena...\n");
    } else {
        printf("Game exited from menu.\n");
    }

    return 0;
}