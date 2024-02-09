#include <stdio.h>
#include <stdlib.h>
#include "../inc/sdl_integration.h"
#include <SDL2/SDL.h>

SDL_Window* initWindow(const char* title, int width, int height) {
    SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    return window;
}

SDL_Renderer* initRenderer(SDL_Window* window) {
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    return renderer;
}

void cleanup(SDL_Renderer* renderer, SDL_Window* window) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
