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