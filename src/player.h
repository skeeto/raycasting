#ifndef PLAYER_H
#define PLAYER_H

/**
 * Represent a player in the map
 */
typedef struct Player{
    float x; 
    float y; 
    float width; 
    float height; 
    int is_facing_left; 
    int walk_direction; 
    float rotation_angle;
    float walk_speed; 
    float rotation_speed;
} Player_T;

/**
 * Creates a new player.
 * 
 * Allocates the memory required for the player, and create a player with initial fields.
 */
void init_player(Player_T* player);

void move_player(Player_T* player, float dx, float dy, float delta_time);

/**
 * De-allocate player memory
 */
void freePlayer(Player_T* player);

#endif