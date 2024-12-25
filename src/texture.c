#include "texture.h"
#include "constants.h"

void malloc_texture_buffer(Uint32 **texture_buffer)
{
    *texture_buffer = (Uint32 *) malloc(sizeof(Uint32) * (Uint32)TEXTURE_WIDTH * (Uint32)TEXTURE_HEIGHT);

    if(!texture_buffer){
        fprintf(stderr, "could not allocate memory for texture\n");
        exit(1);
    }
}

void fill_wall_texture(Uint32 *texture_buffer, Uint32 color)
{
    for (int x = 0; x < TEXTURE_WIDTH; x++){
        for(int y = 0; y < TEXTURE_HEIGHT; y++){
            texture_buffer[(TEXTURE_WIDTH*y) + x] = (x % 8 && y % 8) ? color : 0xFF000000;
        }
    }
}
