#include "shared.h"
#include "fire.h"

// TODO: This will be moved to an arena.c file later
void* thread_grafico(void* arg) {
    (void)arg;
    while(1) {
        pthread_mutex_lock(&mutex_arena);
        // We will draw the 20x50 map and 3x3 robots here
        pthread_mutex_unlock(&mutex_arena);
        usleep(50000); // 20 FPS
    }
    return NULL;
}

int main(void) {
    srand(time(NULL));
    pthread_mutex_init(&mutex_arena, NULL);

    pthread_t menu_thread;
    pthread_create(&menu_thread, NULL, menu_over_fire, NULL);
    
    void *menu_result;
    pthread_join(menu_thread, &menu_result);
    
    long choice = (long)menu_result;
    
    if (choice == 0) {
        // --- LAUNCHING THE ARENA ---
        initscr();
        cbreak();
        noecho();
        curs_set(0);
        
        // Start Graphics Thread
        pthread_t gfx_thread;
        pthread_create(&gfx_thread, NULL, thread_grafico, NULL);
        
        // Wait for 'q' to quit the arena
        int ch;
        while ((ch = getch()) != 'q') {
            usleep(100000);
        }
        
        pthread_cancel(gfx_thread);
        pthread_join(gfx_thread, NULL);
        endwin();

    } else {
        printf("Game Exited.\n");
    }

    pthread_mutex_destroy(&mutex_arena);
    return 0;
}