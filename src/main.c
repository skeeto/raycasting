#include <stdio.h>
#include <SDL2/SDL.h>
#include "constants.h"

// Window pointer 
SDL_Window* window = NULL;

// Renderer pointer
SDL_Renderer* renderer = NULL; 

// Global bool for the game loop
int game_running; 

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
        WINDOW_HIGHT, 
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


    // Rendering all game objects
    SDL_RenderPresent(renderer);
}

/**
 * Method for setting up the game objects
 */
void setup(){

}

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
        //update();

        // Render the game
        render();
    }

    // Exited the game
    destroy_window();
    return 0;
}