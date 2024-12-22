#include "constants.h"
#include <SDL2/SDL.h>
#ifndef MAP_H
#define MAP_H

typedef struct Map
{
    int grid[ROWS][COLS];
}Map_T;

/**
 * Init the map with default map
 * 
 * @param map map to be initalized 
 */
void init_default_map(Map_T** map);

/**
 * De allocate map resources
 * 
 * @param map map to be freed. 
 */
void freeMap(Map_T* map);

/**
 * Renders the given map on the SDL canvas.
 * 
 * @param map map to be rendered
 * @param renderer SDL renderer
 */
void renderMap(Map_T* map, SDL_Renderer* renderer);


#endif