#ifndef RAYCASTING_H
#define RAYCASTING_H


//#define FOV 1.0472 // Adjust this value as needed

// Include necessary headers
#include <SDL2/SDL.h>

// Define screen dimensions
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Define map dimensions
#define MAP_WIDTH 10
#define MAP_HEIGHT 10

// Function declarations
void renderWalls(SDL_Renderer* renderer, float playerX, float playerY, float playerAngle);

#endif // RAYCASTING_H
