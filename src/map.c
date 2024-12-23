#include "map.h"
#include "constants.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

// Map where
// - 1 represent a wall
// - 0 represents empty space
const int DEFAULT_MAP[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void init_default_map(Map_T** map)
{
    *map = malloc(sizeof(Map_T));
    if (!map){
        fprintf(stderr, "Failed to allocate memory for map\n");
        exit(1);
    }
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            (*map)->grid[i][j] = DEFAULT_MAP[i][j];
        }
    }
}

void free_map(Map_T *map)
{
    if (map){
        free(map);
    }
}

void render_map(Map_T *map, SDL_Renderer* renderer)
{
    // Check if map has been initalized
    if (map == NULL){
        fprintf(stderr, "Map was not initalized for rendering\n");
        exit(1);
    }

    // Render map
    for (int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            // X and y position of the given tile
            int tile_x = j*TILE_SIZE; 
            int tile_y = i*TILE_SIZE; 

            // Tile color is either black or white, depending of if there is a wall there; 
            int tile_color = map->grid[i][j] != 0 ? 255 : 0; 

            // Color in the tile at given position 
            SDL_SetRenderDrawColor(renderer, tile_color, tile_color, tile_color, 255);
            
            // Create the tile and render it
            SDL_FRect rect = {
                MINIMAP_SCALE * tile_x, 
                MINIMAP_SCALE * tile_y,
                MINIMAP_SCALE * TILE_SIZE,
                MINIMAP_SCALE * TILE_SIZE
            };
            SDL_RenderFillRectF(renderer, &rect);
        }
    }
}

int wall_content(Map_T *map, float x, float y)
{
    // Map boundary is walls
    if(x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT){
        return 1;
    }

    // Grid position 
    int grid_x = (int) floor(x / TILE_SIZE);
    int grid_y = (int) floor(y / TILE_SIZE);

    // Return the content of the grid at that given position. 
    return map->grid[grid_y][grid_x];
}

int has_wall_at(Map_T *map, float x, float y)
{
    // Map boundary is walls
    if(x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT){
        return 1;
    }

    // Grid position 
    int grid_x = (int) floor(x / TILE_SIZE);
    int grid_y = (int) floor(y / TILE_SIZE);

    // Return the content of the grid at that given position. 
    return map->grid[grid_y][grid_x] != 0;
}
