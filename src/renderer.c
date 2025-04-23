#include "renderer.h"

void drawRect(Rect rect, Color color){
    glColor4f(color.r, color.g, color.b, color.a);

    glBegin(GL_QUADS);
        glVertex2f(rect.top_left.x, rect.top_left.y);
        glVertex2f(rect.top_right.x, rect.top_right.y);
        glVertex2f(rect.bottom_right.x, rect.bottom_right.y);
        glVertex2f(rect.bottom_left.x, rect.bottom_left.y);
    glEnd();
}

void drawCircle(Circle circle, Color color){
    glColor4f(color.r, color.g, color.b, color.a);

    // atan methods finds the tangent angle (in radians)
    // thats how we get pi
    const double pi = 4.0f * atan(1.0f);

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < circle.segments; i++){
        float theta = 2.0f * pi * (float) i / (float) circle.segments;
        float x = circle.radius * cos(theta) + circle.center.x;
        float y = circle.radius * sin(theta) + circle.center.y;
        glVertex2f(x, y);
    }
    glEnd();
}