#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "../inc/maze.h"
#include "../inc/raycasting.h"
#include "../inc/sdl_integration.h"

int main(void)
{
    //This Initializes SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    //This Creates SDL window and renderer
    SDL_Window *window = initWindow("SDL Maze Game", SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!window)
    {
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Renderer *renderer = initRenderer(window);
    if (!renderer)
    {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    //The Main game loop
    int quit = 0;
    while (!quit)
    {
        //This Handle events (if needed)

        //This Update game state (if needed)

        //This Renders the walls using raycasting
        renderWalls(renderer, 0.0f, 0.0f, 0.0f); //Renders player position and angle

        //This Present the renderer
        SDL_RenderPresent(renderer);
    }

    // Cleanup and exit
    cleanup(renderer, window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
