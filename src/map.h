#ifndef MAP_H
#define MAP_H

#include <SDL2/SDL.h>
#include "constants.h" // Include only necessary files

// Forward declaration
struct Ray; // Forward declaration of Ray_T

typedef struct Map {
    int grid[ROWS][COLS];
} Map_T;

/**
 * Init the map with default map
 */
void init_default_map(Map_T **map);

/**
 * Deallocate map resources
 */
void free_map(Map_T *map);

/**
 * Renders the given map on the SDL canvas.
 */
void render_map(Map_T *map, SDL_Renderer *renderer);

/**
 * Get the content of the wall at the given position
 */
int wall_content(Map_T *map, float x, float y);

/**
 * Check if there is a wall in the grid 
 */
int has_wall_at(Map_T *map, float x, float y);

/**
 * Render the walls in the map using rays
 */
void render_walls(Map_T *map, struct Ray *rays[RAY_COUNT], Uint32 *color_buffer);

#endif
