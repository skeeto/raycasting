#include "map.h"
#include "constants.h"
#include "ray.h"
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

void render_walls(Map_T *map, Ray_T *rays[RAY_COUNT], Uint32 *color_buffer)
{
    for (int i = 0; i < RAY_COUNT; i++){
        float distance_projection_plane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE /2);
        float projection_wall_height = (TILE_SIZE / rays[i]->distance) * distance_projection_plane;

        // Calculate the strip height of the wall 
        int wall_strip_height = (int) projection_wall_height;
        
        // Find the top pixel of the strip
        int wall_top_pixel = (WINDOW_HEIGHT / 2) - (wall_strip_height / 2);
        wall_top_pixel = wall_top_pixel < 0 ? 0 : wall_top_pixel;

        // Find the bottom pixel
        int wall_bottom_pixel = (WINDOW_HEIGHT / 2) + (wall_strip_height / 2);
        wall_bottom_pixel = wall_bottom_pixel > WINDOW_WIDTH ? 0 : WINDOW_HEIGHT;


        // Render the strip from the top to the bottom
        for (int y = wall_top_pixel; y < wall_bottom_pixel; y++){
            color_buffer[(WINDOW_WIDTH * y) + 1] = 0xFFFFFFFF;
        }
    }
}
