#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

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

typedef struct {
    Vec2 center;
    float radius;
    int segments;
} Circle;

Vec2 newVec2(float x, float y);

Rect newSquare(Vec2 top_left, float size);
Rect newRect(Vec2 top_left, float width, float height);
Rect newCentralizedRect(float width, float height);
Rect centralizeRect(Rect rect);

Circle newCircle(Vec2 center, float radius, int segments);

Color newColor(float r, float g, float b);
Color colorSetOpacity(Color color, float opacity);

#endif