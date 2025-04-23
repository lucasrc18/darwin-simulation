#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

typedef struct {
    float r, g, b;
    float a;
} Color;

typedef struct {
    float x, y;
} Vec2;

typedef struct {
    Vec2 top_left; 
    Vec2 top_right; 
    Vec2 bottom_left; 
    Vec2 bottom_right; 
} Rect;

Vec2 newVec2(float x, float y);

Rect newSquare(Vec2 top_left, float size);
Rect newRect(Vec2 top_left, float width, float height);

Color newColor(float r, float g, float b);
Color colorSetOpacity(Color color, float opacity);

#endif