#include "utils.hpp"

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