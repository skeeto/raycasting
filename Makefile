CC        = cc
CFLAGS    = -Wall -Wextra -g3 -fsanitize=address,undefined
PKGFLAGS != pkg-config --cflags --libs sdl2

src = raycast.c src/color_buffer.c src/color_buffer.h src/constants.h \
      src/help_functions.c src/help_functions.h src/main.c src/map.c \
      src/map.h src/player.c src/player.h src/ray.c src/ray.h src/texture.c \
      src/texture.h src/wolfenstein_textures.h

raycast: $(src)
	$(CC) $(CFLAGS) -o $@ raycast.c $(PKGFLAGS)

clean:
	rm -f raycast
