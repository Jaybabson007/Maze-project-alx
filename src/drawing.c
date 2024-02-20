#include "../inc/header.h" /* Include the necessary header file*/

/**
 * drawRect - draw a rectangle
 * @x: x coordinate
 * @y: y coordinate
 * @width: rectangle width
 * @height: rectangle height
 * @color: pixel color
*/
void drawRect(int x, int y, int width, int height, color_t color)
{
    int i, j;

    /*Nested loops to iterate through each pixel in the rectangle*/
    for (i = x; i <= (x + width); i++)
        for (j = y; j <= (y + height); j++)
/*Call drawPixel function to draw a pixel at (i, j) with the specified color*/
            drawPixel(i, j, color);
}

/**
 * drawLine - draw a line
 * @x0: x coordinate init
 * @y0: y coordinate init
 * @x1: x coordinate init
 * @y1: y coordinate end
 * @color: pixel color
*/
void drawLine(int x0, int y0, int x1, int y1, color_t color)
{
    float xIncrement, yIncrement, currentX, currentY;
    int i, longestSideLength, deltaX, deltaY;

    deltaX = (x1 - x0);
    deltaY = (y1 - y0);

    /*Determine the longest side of the line*/
    longestSideLength = (abs(deltaX) >= abs(deltaY)) ? abs(deltaX) : abs(deltaY);

    /*Calculate the incremental values for x and y to draw the line*/
    xIncrement = deltaX / (float)longestSideLength;
    yIncrement = deltaY / (float)longestSideLength;

    currentX = x0;
    currentY = y0;

    /*Iterate through each point along the line and draw a pixel*/
    for (i = 0; i < longestSideLength; i++)
    {
/*Call drawPixel function to draw a pixel at (i, j) with the specified color*/
        drawPixel(round(currentX), round(currentY), color); 
        currentX += xIncrement;
        currentY += yIncrement;
    }
}

