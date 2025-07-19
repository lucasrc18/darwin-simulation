#ifndef POLYGONS_HPP
#define POLYGONS_HPP

#include "utils.hpp"

/* ======================== Polygons Declarations ======================== */

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