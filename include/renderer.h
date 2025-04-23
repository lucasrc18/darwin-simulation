#ifndef RENDERER_H
#define RENDERER_H

#include "utils.h"
#include <math.h>
#include <GL/glew.h>

/** 
 * Draws a rectangle on the screen
 * 
 * @param rect The rectangle to draw
 * @param color The color of the rectangle
*/
void drawRect(Rect rect, Color color);

/**
 * Draws a circle on the screen
 * 
 * @param circle The circle to draw
 * @param color The color of the circle
*/
void drawCircle(Circle circle, Color color);

#endif