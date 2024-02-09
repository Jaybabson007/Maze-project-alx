#include <stdio.h>
#include <stdlib.h>
#include "../inc/raycasting.h"
#include <SDL2/SDL.h>

// Define wall colors
#define WALL_COLOR 0x00FF00FF
#define GROUND_COLOR 0x000000FF

// Assuming CEIL_COLOR is in the format 0xRRGGBBAA
#define CEIL_RED   0x40
#define CEIL_GREEN 0x40
#define CEIL_BLUE  0x40
#define CEIL_ALPHA 0xFF

// Assuming GROUND_COLOR is in the format 0xRRGGBBAA
#define GROUND_RED   0x00
#define GROUND_GREEN 0x00
#define GROUND_BLUE  0x00
#define GROUND_ALPHA 0xFF

// Extract individual color components
/*#define CEIL_RED  (Uint8)((CEIL_COLOR >> 24) & 0xFF)*/
/*#define CEIL_GREEN (Uint8)((CEIL_COLOR >> 16) & 0xFF)*/
/*#define CEIL_BLUE  (Uint8)((CEIL_COLOR >> 8)  & 0xFF)*/
/*#define CEIL_ALPHA (Uint8)(CEIL_COLOR & 0xFF)*/

// Define the map layout (1 represents a wall, 0 represents an empty space)
int map[MAP_WIDTH][MAP_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void renderWalls(SDL_Renderer* renderer, float playerX, float playerY, float playerAngle) {
    // Clear the screen
    SDL_RenderClear(renderer);

     // Set ceiling color
    SDL_SetRenderDrawColor(renderer, GROUND_RED, GROUND_GREEN, GROUND_BLUE, GROUND_ALPHA);

    // Draw the floor and ceiling
    for (int y = 0; y < SCREEN_HEIGHT / 2; y++) {
        SDL_SetRenderDrawColor(renderer, GROUND_RED, GROUND_GREEN, GROUND_BLUE, GROUND_ALPHA);
        SDL_RenderDrawLine(renderer, 0, y, SCREEN_WIDTH, y);

        SDL_SetRenderDrawColor(renderer, GROUND_COLOR);
        SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT - y, SCREEN_WIDTH, SCREEN_HEIGHT - y);
    }

    // Raycasting logic here...

    // Present the renderer
    SDL_RenderPresent(renderer);
}
