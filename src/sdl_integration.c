#include <stdio.h>
#include <stdlib.h>
#include "../inc/sdl_integration.h"
#include <SDL2/SDL.h>
#include "../inc/header.h"

static SDL_Renderer *renderer;
static color_t *colorBuffer;
static SDL_Texture *colorBufferTexture;
static SDL_Window *window;
/**
 * initializeWindow - Initialize window to display the maze
 * Return: true in case of success, false if it fails
*/
bool initializeWindow(void)
{
    /*Initialize SDL*/
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error initializing SDL.\n");
        return (false);
    }

    /*Get the display mode and set fullscreen dimensions*/
    SDL_DisplayMode display_mode;
    int fullScreenWidth, fullScreenHeight;
    SDL_GetCurrentDisplayMode(0, &display_mode);
    fullScreenWidth = display_mode.w;
    fullScreenHeight = display_mode.h;

    /*Create SDL window*/
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        fullScreenWidth,
        fullScreenHeight,
        SDL_WINDOW_BORDERLESS
    );
    if (!window)
    {
        fprintf(stderr, "Error creating SDL window.\n");
        return (false);
    }

    /*Create SDL renderer*/
    renderer = SDL_CreateRenderer(window, -1, 1);
    if (!renderer)
    {
        fprintf(stderr, "Error creating SDL renderer.\n");
        return (false);
    }

    /*Set render blend mode*/
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    /*Allocate memory for the color buffer*/
    colorBuffer = malloc(sizeof(color_t) * SCREEN_WIDTH * SCREEN_HEIGHT);

    /*Create an SDL_Texture to display the color buffer*/
    colorBufferTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32,
        SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);

    return (true);
}

/**
 * destroyWindow - destroy window when the game is over
 *
*/
void destroyWindow(void)
{
    /*Free allocated memory and destroy SDL components*/
    free(colorBuffer);
    SDL_DestroyTexture(colorBufferTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/**
 * clearColorBuffer - clear buffer for every frame
 * @color: color buffer
*/
void clearColorBuffer(color_t color)
{
    /*Set all pixels in the color buffer to the specified color*/
    int i;
    for (i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
        colorBuffer[i] = color;
}

/**
 * renderColorBuffer - render buffer for every frame
 *
*/
void renderColorBuffer(void)
{
    /*Update the SDL_Texture with the color buffer data*/
    SDL_UpdateTexture(
        colorBufferTexture,
        NULL,
        colorBuffer,
        (int)(SCREEN_WIDTH * sizeof(color_t))
    );

    /*Copy the texture to the renderer and present the renderer*/
    SDL_RenderCopy(renderer, colorBufferTexture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

/**
 * drawPixel - assign a color to each pixel
 * @x: x pixel coordinate
 * @y: y pixel coordinate
 * @color: pixel color
*/
void drawPixel(int x, int y, color_t color)
{
    /*Set the color of a specific pixel in the color buffer*/
    colorBuffer[(SCREEN_WIDTH * y) + x] = color;
}

