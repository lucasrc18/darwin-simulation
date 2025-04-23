#include "utils.h"

Vec2 newVec2(float x, float y){
    Vec2 vec2;
    
    vec2.x = x;
    vec2.y = y;
    
    return vec2;
}

Rect newSquare(Vec2 top_left, float size){
    return newRect(top_left, size, size);
}

Rect newRect(Vec2 top_left, float width, float height){
    Rect rect;
    
    rect.top_left.x = top_left.x;
    rect.top_left.y = top_left.y;

    rect.top_right.x = top_left.x + width;
    rect.top_right.y = top_left.y;

    rect.bottom_left.x = top_left.x;
    rect.bottom_left.y = top_left.y + height;

    rect.bottom_right.x = rect.top_right.x;
    rect.bottom_right.y = rect.bottom_left.y;
    
    return rect;
}

Color newColor(float r, float g, float b){
    Color color;
    
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = 1.0f;
    
    return color;
}

Color colorSetOpacity(Color color, float opacity){
    color.a = opacity;
    return color;
}