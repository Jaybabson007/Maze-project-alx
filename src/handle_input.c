#include "../inc/header.h" /*Includes the necessary header file*/

/**
 * SDL_KEYDOWN_FUNC - process input when a key is down
 * @event: union that contains structures for the different event types
*/
void SDL_KEYDOWN_FUNC(SDL_Event event)
{
    /*Checks the key pressed and update player's walk and turn directions accordingly*/
    if (event.key.keysym.sym == SDLK_ESCAPE)
        GameRunning = false; /*If the 'ESC' key is pressed, set GameRunning to false, indicating that the game should stop*/
    if (event.key.keysym.sym == SDLK_UP)
        player.walkDirection = +1; /*If the 'UP' arrow key is pressed, set player's walk direction to +1*/
    if (event.key.keysym.sym == SDLK_DOWN)
        player.walkDirection = -1; /*If the 'DOWN' arrow key is pressed, set player's walk direction to -1*/
    if (event.key.keysym.sym == SDLK_RIGHT)
        player.turnDirection = +1; /*If the 'RIGHT' arrow key is pressed, set player's turn direction to +1*/
    if (event.key.keysym.sym == SDLK_LEFT)
        player.turnDirection = -1; /*If the 'LEFT' arrow key is pressed, set player's turn direction to -1*/
    if (event.key.keysym.sym == SDLK_w)
        player.walkDirection = +1; /*If the 'W' key is pressed, set player's walk direction to +1*/
    if (event.key.keysym.sym == SDLK_s)
        player.walkDirection = -1; /*If the 'S' key is pressed, set player's walk direction to -1*/
    if (event.key.keysym.sym == SDLK_a)
        player.turnDirection = -1; /*If the 'A' key is pressed, set player's turn direction to -1*/
    if (event.key.keysym.sym == SDLK_d)
        player.turnDirection = +1; /*If the 'D' key is pressed, set player's turn direction to +1*/
}

/**
 * SDL_KEYUP_FUNC - process input when a key is up
 * @event: union that contains structures for the different event types
*/
void SDL_KEYUP_FUNC(SDL_Event event)
{
    /*Check the key released and reset player's walk and turn directions to 0*/
    if (event.key.keysym.sym == SDLK_UP)
        player.walkDirection = 0; /*If the 'UP' arrow key is released, set player's walk direction to 0*/
    if (event.key.keysym.sym == SDLK_DOWN)
        player.walkDirection = 0; /*If the 'DOWN' arrow key is released, set player's walk direction to 0*/
    if (event.key.keysym.sym == SDLK_RIGHT)
        player.turnDirection = 0; /*If the 'RIGHT' arrow key is released, set player's turn direction to 0*/
    if (event.key.keysym.sym == SDLK_LEFT)
        player.turnDirection = 0; /*If the 'LEFT' arrow key is released, set player's turn direction to 0*/
    if (event.key.keysym.sym == SDLK_w)
        player.walkDirection = 0; /*If the 'W' key is released, set player's walk direction to 0*/
    if (event.key.keysym.sym == SDLK_s)
        player.walkDirection = 0; /*If the 'S' key is released, set player's walk direction to 0*/
    if (event.key.keysym.sym == SDLK_a)
        player.turnDirection = 0; /*If the 'A' key is released, set player's turn direction to 0*/
    if (event.key.keysym.sym == SDLK_d)
        player.turnDirection = 0; /*If the 'D' key is released, set player's turn direction to 0*/
}

/**
 * handleInput - process input from the keyboard
*/
void handleInput(void)
{
    SDL_Event event;

    SDL_PollEvent(&event); /*Poll for events*/

    /*Check the type of event and call corresponding functions*/
    if (event.type == SDL_QUIT)
        GameRunning = false; /*If the event is a quit event, set GameRunning to false*/
    else if (event.type == SDL_KEYDOWN)
        SDL_KEYDOWN_FUNC(event); /*If the event is a key down event, call SDL_KEYDOWN_FUNC to process the key press*/
    else if (event.type == SDL_KEYUP)
        SDL_KEYUP_FUNC(event); /*If the event is a key up event, call SDL_KEYUP_FUNC to process the key release*/
}

