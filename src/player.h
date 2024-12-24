#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "constants.h" // Only include this for ROWS/COLS

// Forward declaration
struct Map; // Forward declaration of Map_T

/**
 * Player struct
 */
typedef struct Player {
    float x; 
    float y; 
    float width; 
    float height; 
    int turn_direction; 
    int walk_direction; 
    float rotation_angle;
    float walk_speed; 
    float rotation_speed;
} Player_T;

/**
 * Initialize the player
 */
void init_player(Player_T **player);

/**
 * Method for moving a player
 */
void move_player(Player_T *player, struct Map *map, float delta_time);

/**
 * Deallocate the player
 */
void free_player(Player_T *player);

/**
 * Render the player on the SDL screen
 */
void render_player(Player_T *player, SDL_Renderer *renderer);

#endif
