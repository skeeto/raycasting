#include <SDL2/SDL_stdinc.h>
#ifndef COLOR_BUFFER_H
#define COLOR_BUFFER_H

/**
 * Allocates memory for the given color buffer pointer.
 * 
 * Allocates Uint32 for each pixel in the screen. 
 * Each element in the buffer represent a color for the given screen.
 * Will terminate the program, if it was not able to allocate memory for the buffer.
 * 
 * @param color_buffer color buffer pointer that requires the memory
 */
void malloc_color_buffer(Uint32 *color_buffer);

/**
 * Free the dynamic memory for the color buffer.
 * 
 * @param color_buffer buffer to be freed
 */
void free_color_buffer(Uint32 *color_buffer);

/**
 * Fill the color buffer with a given color
 * 
 * @param color_buffer the buffer to be filled
 * @param color color to fill the buffer with
 */
void fill_color_buffer(Uint32 *color_buffer, Uint32 color);

#endif