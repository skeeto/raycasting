#include "player.h"
#include "constants.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

void init_player(Player_T **player)
{
    *player = malloc(sizeof(Player_T)); // Allocate memory for the player
    if (!*player) {
        fprintf(stderr, "Failed to allocate memory for player\n");
        exit(1);
    }

    (*player)->x = WINDOW_WIDTH / 2;
    (*player)->y = WINDOW_HEIGHT / 2;  
    (*player)->width = 5;
    (*player)->height = 5; 
    (*player)->is_facing_left = 0; 
    (*player)->walk_direction = 0; 
    (*player)->rotation_angle = PI / 2; 
    (*player)->walk_speed = 100; 
    (*player)->rotation_speed = 45 * (PI / 180);
}

void move_player(Player_T* player, float dx, float dy, float delta_time)
{   
    if(player == NULL){
        return;
    }
    player->x += dx * delta_time; 
    player->y += dy * delta_time; 
}

void free_player(Player_T *player)
{   
    if (player){
        free(player);
    }
}

void render_player(Player_T *player, SDL_Renderer* renderer)
{
    // Check if player was not a null pointer
    if(!player){
        fprintf(stderr, "Player was not ready for render\n");
        exit(1);
    }

    // Create and render the player rectangle 
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_FRect player_rect = {
        MINIMAP_SCALE * player->x,
        MINIMAP_SCALE * player->y, 
        MINIMAP_SCALE * player->width,
        MINIMAP_SCALE * player->height
    };
    // Draw the rectangle itself
    SDL_RenderFillRectF(renderer, &player_rect);

    // Render the direction where the player is looking at
    SDL_RenderDrawLine(renderer, 
        MINIMAP_SCALE * player->x,
        MINIMAP_SCALE * player->y, 
        MINIMAP_SCALE * player->x + cos(player->rotation_angle) * 40,
        MINIMAP_SCALE * player->y + sin(player->rotation_angle) * 40
    );
}
