#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "../inc/maze.h"
#include "../inc/raycasting.h"
#include "../inc/sdl_integration.h"
#include "../inc/header.h" /*Include the necessary header file*/

bool GameRunning = false; /*Global variable indicating whether the game is running or not*/
int TicksLastFrame; /*Variable to store the ticks of the last frame*/
player_t player; /*Global variable representing the player*/

/**
 * setup_game - initialize player variables and load wall textures
*/
void setup_game(void)
{
    /*Initialize player variables*/
    player.x = SCREEN_WIDTH / 2;
    player.y = SCREEN_HEIGHT / 2;
    player.width = 1;
    player.height = 30;
    player.walkDirection = 0;
    player.walkSpeed = 100;
    player.turnDirection = 0;
    player.turnSpeed = 45 * (PI / 180);
    player.rotationAngle = PI / 2;

    /*Load wall textures*/
    WallTexturesready();
}

/**
 * update_game - update_game delta time, the ticks last frame
 *          the player movement and the ray casting
*/
void update_game(void)
{
    float DeltaTime;
    int timeToWait = FRAME_TIME_LENGTH - (SDL_GetTicks() - TicksLastFrame);

    /*Delay the game loop to achieve a constant frame rate*/
    if (timeToWait > 0 && timeToWait <= FRAME_TIME_LENGTH)
    {
        SDL_Delay(timeToWait);
    }

    /*Calculate delta time*/
    DeltaTime = (SDL_GetTicks() - TicksLastFrame) / 1000.0f;

    TicksLastFrame = SDL_GetTicks(); /*Update TicksLastFrame*/

    movePlayer(DeltaTime); /*Update player's position based on input and delta time*/
    castAllRays(); /*Perform ray casting for rendering*/
}

/**
 * render_game - calls all functions needed for on-screen rendering
*/
void render_game(void)
{
    clearColorBuffer(0xFF000000); /*Clear the color buffer with a black color*/

    renderWall(); /*Render the walls*/
    renderMap(); /*Render the map*/
    renderRays(); /*Render the rays*/
    renderPlayer();/*Render the player*/

    renderColorBuffer(); /*Display the rendered frame on the screen*/
}

/**
 * destroy_game - free wall textures and destroy window
*/
void destroy_game(void)
{
    freeWallTextures(); /*Free the allocated wall textures*/
    destroyWindow(); /*Destroy the game window*/
}

/**
 * main - main function
 * Return: 0
*/
int main(void)
{
    GameRunning = initializeWindow(); /*Initialize the game window and set GameRunning to true if successful*/

    setup_game(); /*Perform initial setup for the game*/

    while (GameRunning)
    {
        handleInput(); /*Handle user input*/
        update_game(); /*Update game logic*/
        render_game(); /*Render the game*/
    }

    destroy_game(); /*Clean up and destroy game resources*/

    return (0);
}

