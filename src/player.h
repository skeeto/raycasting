#include <SDL2/SDL.h>

#ifndef PLAYER_H
#define PLAYER_H

/**
 * Player struct
 */
typedef struct Player{
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
 * Initialize the player.
 * 
 * Allocates the resources for the given player pointer, and sets default params.
 * 
 * @param player 
 */
void init_player(Player_T **player);

/**
 * Method for moving a player
 * 
 * Will also rotate the player and move the player.
 * Uses ows state to termin if we are going to move or not.  
 * 
 * @param player the player to be moved
 * @param delta_time delta time to make the move be dependent on the rendering rate
 */
void move_player(Player_T *player, float delta_time);

/**
 * De allocate the player
 * 
 * @param player player to free
 */
void free_player(Player_T *player);

/**
 * Render the player on the SDL screen
 * 
 * @param player 
 */
void render_player(Player_T *player, SDL_Renderer *renderer);

#endif