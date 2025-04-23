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

Rect centralizeRect(Rect rect){
    const float width = rect.top_right.x - rect.top_left.x;
    const float height = rect.bottom_left.y - rect.top_left.y;
    
    return newCentralizedRect(width, height);
}

Rect newCentralizedRect(float width, float height){
    const float xoffset = width / 2.0f;
    const float yoffset = height / 2.0f;

    return newRect(newVec2((WINDOW_WIDTH / 2.0f) - xoffset, (WINDOW_HEIGHT / 2.0f) - yoffset), width, height);
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

Circle newCircle(Vec2 center, float radius, int segments){
    Circle circle;
    
    circle.center.x = center.x;
    circle.center.y = center.y;

    circle.radius = radius;
    circle.segments = segments;
    
    return circle;
}