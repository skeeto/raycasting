#include "constants.h"
#include "player.h"

#ifndef RAY_H
#define RAY_H

typedef struct Ray
{
    // Ray information 
    float ray_angle; 
    float wall_hit_x;
    float wall_hit_y; 
    float distance; 
    int was_hit_vertical; 

    // Keep track of direction
    int is_ray_pointing_up; 
    int is_ray_pointing_down; 
    int is_ray_pointing_left;
    int is_ray_pointing_right; 

    // Content and color of the ray hit
    int wall_hit_content; 
} Ray_T;

/**
 * Allocates memory for the rays list 
 * 
 * @param rays rays to be renders
 */
void init_rays(Ray_T *rays[RAY_COUNT]);

/**
 * De allocates memory for the rays list 
 * 
 * @param rays rays array to be freed
 */
void free_rays(Ray_T *rays[RAY_COUNT]);

/**
 * Cast a ray on the given map from the given player, and set the ray struct in the array list of rays.
 * 
 * @param rays the list of rays
 * @param map the map to cast array in
 * @param player the player to cast from
 * @param ray_angle the angle the ray currently have
 * @param strip_numb the column strip id, used as a index to place the ray in the ray list
 */
void cast_ray(Ray_T **rays[RAY_COUNT], Map_T *map, Player_T *player, float ray_angle, int strip_numb);

/**
 * Method that casts all the rays from the given player position
 * 
 * @param rays list of all have been cast
 * @param map map to cast the rays in
 * @param player the player from which we cast all rays
 */
void cast_rays(Ray_T **rays[RAY_COUNT], Map_T *map, Player_T *player);


void render_rays(Ray_T *rays[RAY_COUNT], SDL_Renderer *renderer, Player_T* player);

#endif 