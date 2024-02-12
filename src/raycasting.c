#include <stdio.h>
#include <stdlib.h>
#include "../inc/raycasting.h"
#include <SDL2/SDL.h>
#include <math.h>

#define FOV 60.0

// Define wall colors
#define WALL_RED   255
#define WALL_GREEN 0
#define WALL_BLUE  0
#define WALL_ALPHA 255

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

float currentCameraAngle = 0.0; //Initialize with a default angle

void updateCameraAngle(float angle) {
    currentCameraAngle += angle;
}

void modifyMap(int x, int y, int value) {
    map[x][y] = value;
}



void renderWalls(SDL_Renderer* renderer, float playerX, float playerY, float playerAngle) {
    // Clear the screen
    SDL_RenderClear(renderer);

     // Set ceiling color
     SDL_SetRenderDrawColor(renderer, CEIL_RED, CEIL_GREEN, CEIL_BLUE, CEIL_ALPHA);

    // Draw the floor and ceiling
    for (int y = 0; y < SCREEN_HEIGHT / 2; y++) {
        SDL_SetRenderDrawColor(renderer, GROUND_RED, GROUND_GREEN, GROUND_BLUE, GROUND_ALPHA);
        SDL_RenderDrawLine(renderer, 0, y, SCREEN_WIDTH, y);

        SDL_SetRenderDrawColor(renderer, GROUND_RED, GROUND_GREEN, GROUND_BLUE, GROUND_ALPHA);
        SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT - y, SCREEN_WIDTH, SCREEN_HEIGHT - y);
    }

    // Raycasting logic here...
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        // Calculate ray angle
        float rayAngle = (playerAngle - FOV / 2.0) + ((float)x / SCREEN_WIDTH) * FOV;

        // Calculate ray direction
        float rayDirX = cos(rayAngle);
        float rayDirY = sin(rayAngle);

        // Calculate initial ray position
        float rayPosX = playerX;
        float rayPosY = playerY;

        // Step size for ray increments
        float stepSize = 0.1;

        // Perform raycasting steps
        while (map[(int)rayPosX][(int)rayPosY] == 0) {
            rayPosX += rayDirX * stepSize;
            rayPosY += rayDirY * stepSize;
        }

        // Draw the wall segment
        int ceiling = SCREEN_HEIGHT / 2 - (SCREEN_HEIGHT / (2 * rayPosY));
        int floor = SCREEN_HEIGHT - ceiling;

        SDL_SetRenderDrawColor(renderer, WALL_RED, WALL_GREEN, WALL_BLUE, WALL_ALPHA);
        SDL_RenderDrawLine(renderer, x, ceiling, x, floor);
    }
    // Present the renderer
    SDL_RenderPresent(renderer);
}
