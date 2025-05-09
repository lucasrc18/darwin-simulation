#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstdlib>
#include <cmath>

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

/* ======================== Shapes Declarations ======================== */

/** Base class for polygons and shapes */
class Polygon {
public: 
    Vector2 center;

    virtual void render(Color color) = 0;

    virtual ~Polygon() {}
};

/** 
 * Base class for polygons with exactly 4 vertices as Squares and Rectangles
 */
class Polygon4 : public Polygon {
public:
    Vector2 topLeft, topRight;
    Vector2 bottomLeft, bottomRight;

    void render(Color color) override;
};

/** 
 * Base class for polygons with more than 4 vertices
 * 
 * @note This class is also used as base class for circles
*/
class PolygonN : public Polygon {
public: 
    int v;
    Vector2* vertices;
};

/**
 * Square representation 
 *
 * Represents a square by its four CORNERS in 2D space.
 */
class Square : public Polygon4 {
public:
    /**
     * Creates a new square (a rectangle with equal width and height)
     * 
     * @param x The x coordinate of the center point of the square
     * @param y The y coordinate of the center point of the square
     * @param size The size (width and height) of the square
     * @return Rect A new square (Rect struct) with corner coordinates calculated
     * by his specified side size
     * 
     * @example Rect square = newSquare(newVec2(10.0f, 10.0f), 50.0f);
     */
    Square(float x, float y, float size);

    /**
     * Creates a new square (a rectangle with equal width and height)
     * 
     * @param position The center coordinate point of the square
     * @param size The size (width and height) of the square
     * @return Rect A new square (Rect struct) with corner coordinates calculated
     * by his specified side size
     * 
     * @example Rect square = newSquare(newVec2(10.0f, 10.0f), 50.0f);
     */
    Square(Vector2 position, float size);
};

/**
 * Rectangle representation 
 *
 * Represents a rectangle by its four CORNERS in 2D space.
 */
class Rect : public Polygon4 {
public:
    /**
     * Creates a new rectangle
     * 
     * @param x The x coordinate of the center point of the rectangle
     * @param y The y coordinate of the center point of the rectangle
     * @param width The width of the rectangle
     * @param height The height of the rectangle
     * @return Rect A new rectangular shape (Rect struct) with corner coordinates
     * calculated by his specified side size
     * 
     * @example Rect rectangle = newRect(newVec2(10.0f, 10.0f), 100.0f, 50.0f);
     */
    Rect(float x, float y, float width, float height);


    /**
     * Creates a new rectangle
     * 
     * @param position The center coordinate point of the rectangle
     * @param width The width of the rectangle
     * @param height The height of the rectangle
     * @return Rect A new rectangular shape (Rect struct) with corner coordinates
     * calculated by his specified side size
     * 
     * @example Rect rectangle = newRect(newVec2(10.0f, 10.0f), 100.0f, 50.0f);
     */
    Rect(Vector2 position, float width, float height);
};

/**
 * Circle representation
 * 
 * Represents a circle with a center point, radius, vertices, angle between vertices and number of segments (vertex v)
 * for rendering.
 *
 * @note increasing amount of segments improves circle quality but on the other hand it requires more computational resources
 */
class Circle : PolygonN {
public:
    float radius, angle;

    /**
     * Creates a new circle
     * 
     * @param x The x coordinate of the center point of the circle
     * @param y The y coordinate of the center point of the circle
     * @param radius The radius of the circle
     * @param segments The number of segments used to approximate the circle when rendering
     * @return Circle A new circle (Circle class) with the specified parameters
     * 
     * @note Higher segment counts result in smoother circles but may impact performance
     * @example Circle c = Circle(400.0f, 200.0f, 50.0f, 100);
     */
    Circle(float x, float y, float radius, int segments = 16);

    /**
     * Creates a new circle
     * 
     * @param center The center point of the circle
     * @param radius The radius of the circle
     * @param segments The number of segments used to approximate the circle when rendering
     * @return Circle A new circle (Circle class) with the specified parameters
     * 
     * @note Higher segment counts result in smoother circles but may impact performance
     * @example Circle c = Circle(Vector2(400.0f, 300.0f), 50.0f, 100);
     */
    Circle(Vector2 position, float radius, int segments = 16);

    /**
     * Renders the circle with the specified color
     * 
     * @param color The color of the circle
     * 
     * @example c.render(Color(1.0f, 0.0f, 0.0f));
     */
    void render(Color color) override;
};

#endif