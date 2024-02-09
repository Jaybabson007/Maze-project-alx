#ifndef SDL_INTEGRATION_H
#define SDL_INTEGRATION_H

// Include necessary headers
#include <SDL2/SDL.h>

// Define screen dimensions
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Function declarations
SDL_Window* initWindow(const char* title, int width, int height);
SDL_Renderer* initRenderer(SDL_Window* window);
void cleanup(SDL_Renderer* renderer, SDL_Window* window);

#endif // SDL_INTEGRATION_H
