#include "../inc/header.h" // Include the necessary header file

/*2D array representing the game map with different values indicating the type of each cell*/
    
static const int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
/*Map data (values represent different types of cells)*/
	{6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
	{6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 6},
	{6, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6},
	{6, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 6, 0, 7, 7, 0, 0, 0, 0, 6},
	{6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 7, 0, 6},
	{6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 6},
	{6, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 1, 0, 0, 0, 0, 7, 7, 0, 6},
	{6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
	{6, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 1, 0, 6},
	{6, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 1, 0, 6},
	{6, 0, 0, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
	{6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
	{6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}
};

/**
 * DetectCollision - Checks if there could be a collision
 * with the wall in the next player advance
 * @x: next x coordinate
 * @y: next y coordinate
 * Return: true if collision is detected, false otherwise
*/
bool DetectCollision(float x, float y)
{
    int mapGridX, mapGridY;

    /*Check if the next player position is outside the map boundaries*/
    if (x < 0 || x >= MAP_NUM_COLS * TILE_SIZE ||
        y < 0 || y >= MAP_NUM_ROWS * TILE_SIZE)
        return true; // Collision detected

   /*Calculate the grid coordinates in the map for the next player position*/
    mapGridX = floor(x / TILE_SIZE);
    mapGridY = floor(y / TILE_SIZE);

   /*Check if the map cell at the calculated position is a wall (non-zero value)*/
    return (map[mapGridY][mapGridX] != 0);
}

/**
 * isInsideMap - check if we continue within the map
 * @x: next x coordinate
 * @y: next y coordinate
 * @Return: true if it is within the map, false otherwise
*/
bool isInsideMap(float x, float y)
{
   /*Check if the given coordinates are within the boundaries of the map*/
    return (x >= 0 && x <= MAP_NUM_COLS * TILE_SIZE &&
            y >= 0 && y <= MAP_NUM_ROWS * TILE_SIZE);
}

/**
 * getMapValue - check if we continue within the map
 * @row: map row to check
 * @col: map column to check
 * @Return: The position value in the map
*/
int getMapValue(int row, int col)
{
   /*Return the value at the specified position in the map*/
    return map[row][col];
}

/**
 * renderMap - render the map
*/
void renderMap(void)
{
    int i, j, tileX, tileY;
    color_t tileColor;

    /*Loop through each row and column in the map*/
    for (i = 0; i < MAP_NUM_ROWS; i++)
    {
        for (j = 0; j < MAP_NUM_COLS; j++)
        {
            /*Calculate screen coordinates for the current map cell*/
            tileX = j * TILE_SIZE;
            tileY = i * TILE_SIZE;

            /*Set the color based on whether the map cell is a wall or empty*/
            tileColor = map[i][j] != 0 ? 0xFFFFFFFF : 0x00000000;

            /*Draw a rectangle on the screen representing the map cell*/
            drawRect(
                tileX * MINIMAP_SCALE_FACTOR,
                tileY * MINIMAP_SCALE_FACTOR,
                TILE_SIZE * MINIMAP_SCALE_FACTOR,
                TILE_SIZE * MINIMAP_SCALE_FACTOR,
                tileColor
            );
        }
    }
}

