#include "color_buffer.h"
#include "constants.h"
#include <SDL2/SDL_stdinc.h>

void malloc_color_buffer(Uint32 *color_buffer)
{
    // Calling malloc for allocating buffer
    color_buffer = (Uint32 *) malloc(sizeof(Uint32)* (Uint32)WINDOW_WIDTH * (Uint32)WINDOW_HEIGHT);

    // Check allocation was ok
    if (!color_buffer){
        fprintf(stderr, "could not allocate memory for the color buffer\n");
        exit(1);
    }
}

void free_color_buffer(Uint32 *color_buffer)
{
    if(color_buffer){
        free(color_buffer);
    }
}

void fill_color_buffer(Uint32 *color_buffer, Uint32 color)
{   
    for(int x = 0; x < WINDOW_WIDTH; x++){
        for(int y = 0; y < WINDOW_HEIGHT; y++){
            color_buffer[(WINDOW_WIDTH * y)] = color;
        }
    }
}
