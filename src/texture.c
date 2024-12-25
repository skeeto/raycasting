#include "texture.h"
#include "constants.h"
#include "wolfenstein_textures.h"

void malloc_texture_buffer(Uint32 **texture_buffer)
{
    *texture_buffer = (Uint32 *) malloc(sizeof(Uint32) * (Uint32)TEXTURE_WIDTH * (Uint32)TEXTURE_HEIGHT);

    if(!*texture_buffer){
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

void load_wolfenstein_textures(Uint32 *wolfenstein_textures[8])
{
    // Assign textures in the texture buffer
    wolfenstein_textures[0] = (Uint32 *) REDBRICK_TEXTURE; 
    wolfenstein_textures[1] = (Uint32 *) PURPLESTONE_TEXTURE;
    wolfenstein_textures[2] = (Uint32 *) MOSSYSTONE_TEXTURE;
    wolfenstein_textures[3] = (Uint32 *) GRAYSTONE_TEXTURE;
    wolfenstein_textures[4] = (Uint32 *) COLORSTONE_TEXTURE;
    wolfenstein_textures[5] = (Uint32 *) BLUESTONE_TEXTURE;
    wolfenstein_textures[6] = (Uint32 *) WOOD_TEXTURE;
    wolfenstein_textures[7] = (Uint32 *) EAGLE_TEXTURE;
}
