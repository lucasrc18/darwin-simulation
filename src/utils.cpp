#include "utils.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

/* ======================== COLOR ======================== */

Color::Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}

void Color::setOpacity(float opacity) { this->a = opacity; }

// CONSTANTS

/** Color white representation (1, 1, 1) - 0xFFFFFF */
extern const Color WHITE = Color(1.0f, 1.0f, 1.0f);
/** Color black representation (0, 0, 0) - 0x000000 */
extern const Color BLACK = Color(0.0f, 0.0f, 0.0f);

/** Color red representation (1, 0, 0) - 0xFF0000 */
extern const Color RED = Color(1.0f, 0.0f, 0.0f);
/** Color green representation (0, 1, 0) - 0x00FF00 */
extern const Color GREEN = Color(0.0f, 1.0f, 0.0f);
/** Color blue representation (0, 0, 1) - 0x0000FF */
extern const Color BLUE = Color(0.0f, 0.0f, 1.0f);

/* ======================== Vectors ======================== */

Vector2::Vector2(float x, float y) : x(x), y(y) {}

Vector3::Vector3(float x, float y, float depth) : x(x), y(y), z(depth) {}

Vector3 ConvertToVector3(Vector2 vec2){
    return Vector3(vec2.x, vec2.y, 0.0f);
}

Vector2 ConvertToVector2(Vector3 vec3){
    return Vector2(vec3.x, vec3.y);
}

/* ======================== Shapes Constructors ======================== */

Square::Square(float x, float y, float size) {
    this->center.x = x;
    this->center.y = y;
    
    this->topLeft.x = x - (size / 2);
    this->topLeft.y = y + (size / 2);
    
    this->topRight.x = x + (size / 2);
    this->topRight.y = y + (size / 2);
    
    this->bottomLeft.x = x - (size / 2);
    this->bottomLeft.y = y - (size / 2);
    
    this->bottomRight.x = x + (size / 2);
    this->bottomRight.y = y - (size / 2);
}

Square::Square(Vector2 position, float size) {
    this->center.x = position.x;
    this->center.y = position.y;
    
    this->topLeft.x = position.x - (size / 2);
    this->topLeft.y = position.y + (size / 2);
    
    this->topRight.x = position.x + (size / 2);
    this->topRight.y = position.y + (size / 2);
    
    this->bottomLeft.x = position.x - (size / 2);
    this->bottomLeft.y = position.y - (size / 2);
    
    this->bottomRight.x = position.x + (size / 2);
    this->bottomRight.y = position.y - (size / 2);
}

Rect::Rect(Vector2 position, float width, float height){
    this->center.x = position.x;
    this->center.y = position.y;   

    this->topLeft.x = position.x - (width / 2);
    this->topLeft.y = position.y + (height / 2);

    this->topRight.x = position.x + (width / 2);
    this->topRight.y = position.y + (height / 2);

    this->bottomLeft.x = position.x - (width / 2);
    this->bottomLeft.y = position.y - (height / 2);
    
    this->bottomRight.x = position.x + (width / 2);
    this->bottomRight.y = position.y - (height / 2);
}

Rect::Rect(float x, float y, float width, float height){
    this->center.x = x;
    this->center.y = y;

    this->topLeft.x = x - (width / 2);
    this->topLeft.y = y + (height / 2);
    
    this->topRight.x = x + (width / 2);
    this->topRight.y = y + (height / 2);
    
    this->bottomLeft.x = x - (width / 2);
    this->bottomLeft.y = y - (height / 2);
    
    this->bottomRight.x = x + (width / 2);
    this->bottomRight.y = y - (height / 2); 
}

Circle::Circle(Vector2 position, float radius, int segments){
    this->center.x = position.x;
    this->center.y = position.y;

    this->v = segments;
    this->radius = radius;
    this->angle = 2.0f * M_PI / (float) this->v;

    for(int i = 0; i < this->v; i++){
        float theta = 2.0f * M_PI * (float) i / (float) this->v; 
        
        float x = position.x + radius * cos(theta);
        float y = position.y + radius * sin(theta);
        
        this->vertices[i] = Vector2(x, y);
    }
}

Circle::Circle(float x, float y, float radius, int segments){
    this->center.x = x;
    this->center.y = y;

    this->v = segments;
    this->radius = radius;

    this->vertices = new Vector2[this->v];
    this->angle = 2.0f * M_PI / (float) this->v;

    for (int i = 0; i < this->v; i++){
        float theta = 2.0f * M_PI * (float) i / (float) this->v; 
        
        x += radius * cos(theta);
        y += radius * sin(theta);
        
        this->vertices[i] = Vector2(x, y);
    } 
}

/* ======================== Shapes Renderers ======================== */
void Polygon4::render(Color color){
    glDisable(GL_TEXTURE_2D);
    glColor4f(color.r, color.g, color.b, color.a);

    glBegin(GL_QUADS);
        glVertex2f(this->topLeft.x, this->topLeft.y);
        glVertex2f(this->topRight.x, this->topRight.y);
        glVertex2f(this->bottomRight.x, this->bottomRight.y);
        glVertex2f(this->bottomLeft.x, this->bottomLeft.y);
    glEnd();
}

void Circle::render(Color color){
    glDisable(GL_TEXTURE_2D);
    glColor4f(color.r, color.g, color.b, color.a);

    glBegin(GL_LINE_LOOP);
        for(int i = 0; i < this->v; i++){
            Vector2 vertex = this->vertices[i];
            glVertex2f(vertex.x, vertex.y);
        }
    glEnd();
}
