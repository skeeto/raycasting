#include <stdio.h>
#include <SDL2/SDL.h>
#include "constants.h"
#include "player.h"

// Window pointer 
SDL_Window* window = NULL;

// Renderer pointer
SDL_Renderer* renderer = NULL; 

// Global bool for the game loop
int game_running; 

// Variable for keeping track of how many ticks since last frame
float ticks_since_last_frame = 0.0f; 

// Player that walks in the ray cast simulation
Player_T player;  

// Map where
// - 1 represent a wall
// - 0 represents empty space
const int map[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

/**
 * Method for initializing the window to render graphics.
 * 
 * Returns 0, or 1 on error
 */
int init_window(){
    // Initialize the SDL library
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        fprintf(stderr, "Error when initializing the SDL library\n");
        return 1; 
    }

    // Creating a window
    window = SDL_CreateWindow("RayCast", 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 
        WINDOW_WIDTH, 
        WINDOW_HEIGHT, 
        SDL_WINDOW_BORDERLESS
    );
    if(!window){
        fprintf(stderr, "Could not create SDL window\n");
        return 1; 
    }

    // Create SDL renderer
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer){
        fprintf(stderr, "Could not crete SDL renderer\n");
        return 1; 
    }

    // Setting mode for renderer
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    return 0; 
}

/**
 * Deallocates memory for the SDL, and clean up after window creation.
 * Should be called before exiting the binary. 
 */
void destroy_window(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/**
 * Render method for the raycast application. 
 */
void render(){
    // Drawing a background color
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderClear(renderer);

    // Render player 
    const SDL_Rect rect = {player.x, player.y, 20, 20};
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rect);

    // Rendering all game objects
    SDL_RenderPresent(renderer);
}

/**
 * Method for setting up the game objects
 */
void setup(){
    // Set the initial player postion
    init_player(&player);
}


/**
 * Process input such as key pressed or other IO input.
 */
void process_input(){
    // Polling the newest events
    SDL_Event event; 
    SDL_PollEvent(&event);

    // Handle each type of event 
    switch (event.type){
        case SDL_QUIT:
            game_running = 0; 
            break;
        case SDL_KEYDOWN:
            // ESC leads to quitting the game
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                game_running = 0; 
            }
            break; 
        default:
            break;
    }
}

/**
 * Update the state of the game
 */
void update(){
    // Wait until FPS is met
    // We use SDL Delay: https://wiki.libsdl.org/SDL2/SDL_Delay 
    // Makes the CPU more available
    int delay = FRAME_TIME_LENGTH - (SDL_GetTicks() - ticks_since_last_frame);
    if (delay > 0 && delay <= FRAME_TIME_LENGTH){
        SDL_Delay(delay);
    }

    // Delta time for making game objects move in pixels per second
    // All game objects should use this for movement speed
    float dt = (SDL_GetTicks() - ticks_since_last_frame) / 1000.0f;
    
    // Set ticks since last frame after storing 
    ticks_since_last_frame = SDL_GetTicks();

    // Update player state
    move_player(&player, 20, 20, dt);
}

void freeGameObjects(){
    freePlayer(&player);
}


int main(){
    // Initialize the window
    game_running = !init_window();

    // Setup of the window 
    setup();

    // Game loop
    while(game_running){
        // Handle input 
        process_input();

        // Update the state
        update();

        // Render the game
        render();
    }


    // Exited the game
    destroy_window();

    // Free all game objects
    freeGameObjects();
    return 0;
}