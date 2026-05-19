#ifndef SHARED_H
#define SHARED_H 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <ncurses.h>
#include <string.h>

#define MAX_ROBOT 5
#define MAP_HEIGHT 20
#define MAP_WIDTH 50

// EXTERN declarations (Promises to the compiler that these exist)
extern char rSymbol[MAX_ROBOT];
extern int rState[MAX_ROBOT];
extern int rHP[MAX_ROBOT];
extern int rX[MAX_ROBOT]; 
extern int rY[MAX_ROBOT];
extern char rModel[MAX_ROBOT][3][4];

extern char mappa[MAP_HEIGHT][MAP_WIDTH];
extern pthread_mutex_t mutex_arena;

#endif // SHARED_H