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
void init_default_map(Map_T **map);

/**
 * De allocate map resources
 * 
 * @param map map to be freed. 
 */
void free_map(Map_T *map);

/**
 * Renders the given map on the SDL canvas.
 * 
 * @param map map to be rendered
 * @param renderer SDL renderer
 */
void render_map(Map_T *map, SDL_Renderer *renderer);


/**
 * Check if given position in given map contains a wall
 * 
 * Uses x and y positions that are translated into grid coordinates
 * 
 * @param map given map to check
 * @param x the given x position 
 * @param y the given y position
 * @return int return 0 if no wall hit or 1 if there is a wall hit
 */
int wall_content(Map_T *map, float x, float y);

int has_wall_at(Map_T *map, float x, float y);


#endif