#include "shared.h"

#define MAX_ROBOT 5
#define MAP_HEIGHT 20
#define MAP_WIDTH 50

char rSymbol[MAX_ROBOT] = {'T', 'S', 'B', 'P', 'M'};
int rState[MAX_ROBOT] = {1, 1, 1, 1, 1};
int rHP[MAX_ROBOT] = {150, 80, 100, 100, 90};
int rX[MAX_ROBOT]; 
int rY[MAX_ROBOT];

char rModel[MAX_ROBOT][3][4] = {
    {"[O]", "|||", "/ \\"},
    {" ^ ", ">|<", "/ \\"},
    {"\\ /", "[X]", "/ \\"},
    {" o ", "~|~", "/ \\"},
    {"_-_", "|M|", "/ \\"}
};

char mappa[MAP_HEIGHT][MAP_WIDTH];
pthread_mutex_t mutex_arena;