#include "constants.h"
#ifndef MAP_H
#define MAP_H

typedef struct Map
{
    const int grid[ROWS][COLS];
}Map_T;

void init_default_map(Map_T* map);




#endif