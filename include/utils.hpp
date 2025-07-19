#ifndef UTILS_HPP
#define UTILS_HPP

/* ======================== COLOR ======================== */

/**
 * Color representation in RGBA format
 * 
 * Represents a color with red, green, blue, and alpha (opacity) components.
 * Each component is a float value typically between 0.0 and 1.0.
 */
class Color {
public: 
    float r, g, b; /**< Red, green, blue components (0.0-1.0) */
    float a; /**< Alpha component (0.0-1.0) */
    
    /**
     * Creates a new color with full opacity
     * 
     * @param r Red component (0.0-1.0)
     * @param g Green component (0.0-1.0)
     * @param b Blue component (0.0-1.0)
     * @return Color A new color (Color class) with the specified RGB values and alpha=1.0
     * 
     * @example Color translucidRed = Color();
     * @example red.r = 1.0f;
     * @example red.setOpacity(0.5f);
     */
    Color() : r(1.0f), g(1.0f), b(1.0f), a(1.0f) {} /**< Default constructor */

    /**
     * Creates a new color with full opacity
     * 
     * @param r Red component (0.0-1.0)
     * @param g Green component (0.0-1.0)
     * @param b Blue component (0.0-1.0)
     * @return Color A new color (Color class) with the specified RGB values and alpha=1.0
     * 
     * @example Color red = Color(1.0f, 0.0f, 0.0f);
     */

    Color(float r, float g, float b, float a = 1.0f); 

    /**
     * Sets the opacity of a color
     * 
     * @param color The color to modify
     * @param opacity The opacity value (0.0-1.0)
     * @return Color A new color (Color class) with the same RGB values but modified opacity
     * 
     * @example Color transparentRed = colorSetOpacity(Color(1.0f, 0.0f, 0.0f), 0.5f);
     */
    void setOpacity(float opacity);
};

/* ======================== Vectors ======================== */

/**
 * 2D vector representation
 * 
 * Represents a point or vector in 2D space with x and y coordinates.
 */
class Vector2 {
public:
    float x, y;

    Vector2() : x(0), y(0) {}

    /**
     * Creates a new 2D vector
     * 
     * @param x The x-coordinate
     * @param y The y-coordinate
     * @return Vec2 A new vector (Vector2 class) with the specified coordinates
     * 
     * @example Vec2 position = Vector2(100.0f, 200.0f);
     */
    Vector2(float x, float y);
};

/** 
 * 3D vector representation;
 * 
 * Represents a point or vector in 3D space with x, y, and z coordinates.
 * 
 * @note Z Coordinate a.k.a depth axis
*/
class Vector3 {
public:
    float x, y, z;
    
    /**
     * Creates a new 3D vector
     * 
     * @param x The x-coordinate
     * @param y The y-coordinate
     * @param z The z-coordinate
     * @return Vec3 A new vector (Vector3 class) with the specified coordinates
     * 
     * @example Vec3 position = Vector3(100.0f, 200.0f, 300.0f);
     */
    Vector3(float x, float y, float depth);
};

/**
 *  Convert a 2D vector to a 3D vector
 * 
 * @param vec2 The 2D vector to convert
 * @return Vec3 A new 3D vector (Vector3 class) with the same coordinates as the 2D vector
 * 
 * @example Vec3 position = convertToVec3(Vector2(100.0f, 200.0f));
 */
Vector3 ConvertToVector3(Vector2 vec2);

/**
 *  Convert a 3D vector to a 2D vector
 * 
 * @param vec3 The 3D vector to convert
 * @return Vec2 A new 2D vector (Vector2 class) with the same coordinates as the 2D vector
 * 
 * @note Any value for z axis is ignored
 * 
 * @example Vector2 position = convertToVec2(Vector3(100.0f, 200.0f, 100.0f));
 */
Vector2 ConvertToVector2(Vector3 vec3);

#endif