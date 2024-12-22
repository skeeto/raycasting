#include "constants.h"
#ifndef MAP_H
#define MAP_H

typedef struct Map
{
    const int grid[ROWS][COLS];
}Map_T;

/**
 * Init the map with default map
 * 
 * @param map map to be initalized 
 */
void init_default_map(Map_T* map);

/**
 * De allocate map resources
 * 
 * @param map map to be freed. 
 */
void freeMap(Map_T* map);


#endif