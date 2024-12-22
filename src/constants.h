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

// Field of view in radians 
#define FOV_ANGLE (60 * (PI / 180))