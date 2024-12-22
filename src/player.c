#include "player.h"
#include "constants.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void init_player(Player_T *player)
{
    player = malloc(sizeof(Player_T)); // Allocate memory for the player
    if (!player) {
        fprintf(stderr, "Failed to allocate memory for player\n");
        exit(1);
    }

    player->x = WINDOW_WIDTH / 2;
    player->y = WINDOW_HEIGHT / 2;  
    player->width = 5;
    player->height = 5; 
    player->is_facing_left = 0; 
    player->walk_direction = 0; 
    player->rotation_angle = PI / 2; 
    player->walk_speed = 100; 
    player->rotation_speed = 45 * (PI / 180);
}

void move_player(Player_T* player, float dx, float dy, float delta_time)
{   
    if(player == NULL){
        return;
    }
    player->x += dx * delta_time; 
    player->y += dy * delta_time; 
}

void freePlayer(Player_T *player)
{   
    if (player != NULL){
        free(player);
    }
}

void renderPlayer(Player_T *player)
{
    // Render
}
