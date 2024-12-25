// Control the FPS for the game 
#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)

// Math constants for trigonometry 
#define PI 3.14159265
#define TWO_PI 6.28318530

// Map constants 
#define TILE_SIZE 64
#define ROWS 13
#define COLS 20 

// Window size 
#define WINDOW_WIDTH (TILE_SIZE * COLS)
#define WINDOW_HEIGHT (TILE_SIZE * ROWS)
#define MINIMAP_SCALE 0.3

// Field of view in radians 
#define FOV_ANGLE (60 * (PI / 180))

// Amount of rays to cast
#define RAY_COUNT WINDOW_WIDTH


// Color constants 
#define LIGHT_GRAY 0xFF777777
#define DARK_GRAY 0xFF333333
#define DARK_BLUE 0xFF0000FF


// Texture 
#define TEXTURE_HEIGHT 64
#define TEXTURE_WIDTH 64