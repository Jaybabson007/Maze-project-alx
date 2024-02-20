#include "../inc/header.h" 

/**
 * movePlayer - set the next position of the player
 * @DeltaTime: time elapsed since the last frame
*/
void movePlayer(float DeltaTime)
{
    float moveStep, newPlayerX, newPlayerY;

    /*Update the player's rotation angle based on turnDirection and turnSpeed*/
    player.rotationAngle += player.turnDirection * player.turnSpeed * DeltaTime;

    /*Calculate the step size for player movement based on walkDirection and walkSpeed*/
    moveStep = player.walkDirection * player.walkSpeed * DeltaTime;

    /*Calculate the new player position using trigonometric functions*/
    newPlayerX = player.x + cos(player.rotationAngle) * moveStep;
    newPlayerY = player.y + sin(player.rotationAngle) * moveStep;

    /*Check for collision before updating the player's position*/
    if (!DetectCollision(newPlayerX, newPlayerY))
    {
        player.x = newPlayerX;
        player.y = newPlayerY;
    }
}

/**
 * renderPlayer - render the player
*/
void renderPlayer(void)
{
    /*Draw a rectangle on the screen representing the player*/
    drawRect(
        player.x * MINIMAP_SCALE_FACTOR,
        player.y * MINIMAP_SCALE_FACTOR,
        player.width * MINIMAP_SCALE_FACTOR,
        player.height * MINIMAP_SCALE_FACTOR,
        0xFFFFFFFF
    );
}

