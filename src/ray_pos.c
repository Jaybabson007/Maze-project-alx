#include "../inc/header.h" 

/**
 * distanceBetweenPoints - Finds horizontal intersection with the wall
 * @x1: x coordinate of the starting point
 * @y1: y coordinate of the starting point
 * @x2: x coordinate of the end point
 * @y2: y coordinate of the end point
 * Return: the distance between two points
 */
float distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
    /*Calculate the Euclidean distance between two points using the Pythagorean theorem*/
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

/**
 * isRayFacingDown - check if the ray is facing down
 * @angle: current ray angle
 * Return: true or false
 */
bool isRayFacingDown(float angle)
{
    /*Check if the ray angle is between 0 and PI (exclusive)*/
    return (angle > 0 && angle < PI);
}

/**
 * isRayFacingUp - check if the ray is facing up
 * @angle: current ray angle
 * Return: true or false
 */
bool isRayFacingUp(float angle)
{
    /*Invert the result of isRayFacingDown to check if the ray is facing up*/
    return (!isRayFacingDown(angle));
}

/**
 * isRayFacingRight - check if the ray is facing to the right
 * @angle: current ray angle
 * Return: true or false
 */
bool isRayFacingRight(float angle)
{
    /*Check if the ray angle is in the right half-plane (0 to 0.5 * PI or 1.5 * PI to 2 * PI)*/
    return (angle < 0.5 * PI || angle > 1.5 * PI);
}

/**
 * isRayFacingLeft - check if the ray is facing to the left
 * @angle: current ray angle
 * Return: true or false
 */
bool isRayFacingLeft(float angle)
{
    /*Invert the result of isRayFacingRight to check if the ray is facing left*/
    return (!isRayFacingRight(angle));
}

