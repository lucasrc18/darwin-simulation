#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

/** Window dimensions constants */
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

/**
 * Color representation in RGBA format
 * 
 * Represents a color with red, green, blue, and alpha (opacity) components.
 * Each component is a float value typically between 0.0 and 1.0.
 */
typedef struct {
    float r, g, b;  /**< Red, green, blue components (0.0-1.0) */
    float a;        /**< Alpha/opacity component (0.0-1.0) */
} Color;

/** 
 * Window properties and instances 
 * 
 * Represents a window with its frame and background color.
 * */
typedef struct {
    GLFWwindow* frame;
    Color backgroundColor;
} Window;

/**
 * 2D vector representation
 * 
 * Represents a point or vector in 2D space with x and y coordinates.
 */
typedef struct {
    float x, y; 
} Vec2;

/**
 * Rectangle representation 
 *
 * Represents a rectangle by its four CORNERS in 2D space.
 */
typedef struct {
    Vec2 top_left;     
    Vec2 top_right;   
    Vec2 bottom_left; 
    Vec2 bottom_right; 
} Rect;

/**
 * Circle representation
 * 
 * Represents a circle with a center point, radius, and number of segments (vertex)
 * for rendering.
 *
 * note: increasing amount of segments improves circle quality but on the other hand
 * it requires more computational resources
 */
typedef struct {
    Vec2 center;
    float radius;
    int segments;
} Circle;

/**
 * Creates a new 2D vector
 * 
 * @param x The x-coordinate
 * @param y The y-coordinate
 * @return Vec2 A new vector (Vec2 struct) with the specified coordinates
 * 
 * @example Vec2 position = newVec2(100.0f, 200.0f);
 */
Vec2 newVec2(float x, float y);

/**
 * Creates a new square (a rectangle with equal width and height)
 * 
 * @param top_left The top-left coordinate of the square
 * @param size The size (width and height) of the square
 * @return Rect A new square (Rect struct) with corner coordinates calculated
 * by his specified side size
 * 
 * @example Rect square = newSquare(newVec2(10.0f, 10.0f), 50.0f);
 */
Rect newSquare(Vec2 top_left, float size);

/**
 * Creates a new rectangle
 * 
 * @param top_left The top-left coordinate of the rectangle
 * @param width The width of the rectangle
 * @param height The height of the rectangle
 * @return Rect A new rectangular shape (Rect struct) with corner coordinates
 * calculated by his specified side size
 * 
 * @example Rect rectangle = newRect(newVec2(10.0f, 10.0f), 100.0f, 50.0f);
 */
Rect newRect(Vec2 top_left, float width, float height);

/**
 * Creates a new rectangle centered in the window
 * 
 * @param width The width of the rectangle
 * @param height The height of the rectangle
 * @return Rect A new rectangle (Rect struct) centered within the window based on WINDOW_WIDTH and WINDOW_HEIGHT)
 * 
 * @example Rect centeredRect = newCentralizedRect(100.0f, 100.0f);
 */
Rect newCentralizedRect(float width, float height);

/**
 * Centers an existing rectangle in the window
 * 
 * @param rect The rectangle to centralize
 * @return Rect A new rectangle (Rect struct) with the same dimensions but centered in the window
 * 
 * @example Rect centered = centralizeRect(myRect);
 */
Rect centralizeRect(Rect rect);

/**
 * Creates a new circle
 * 
 * @param center The center point of the circle
 * @param radius The radius of the circle
 * @param segments The number of segments used to approximate the circle when rendering
 * @return Circle A new circle (Circle struct) with the specified parameters
 * 
 * @note Higher segment counts result in smoother circles but may impact performance
 * @example Circle c = newCircle(newVec2(400.0f, 300.0f), 50.0f, 100);
 */
Circle newCircle(Vec2 center, float radius, int segments);

/**
 * Creates a new color with full opacity
 * 
 * @param r Red component (0.0-1.0)
 * @param g Green component (0.0-1.0)
 * @param b Blue component (0.0-1.0)
 * @return Color A new color (Color struct) with the specified RGB values and alpha=1.0
 * 
 * @example Color red = newColor(1.0f, 0.0f, 0.0f);
 */
Color newColor(float r, float g, float b);

/**
 * Sets the opacity of a color
 * 
 * @param color The color to modify
 * @param opacity The opacity value (0.0-1.0)
 * @return Color A new color (Color struct) with the same RGB values but modified opacity
 * 
 * @example Color transparentRed = colorSetOpacity(newColor(1.0f, 0.0f, 0.0f), 0.5f);
 */
Color colorSetOpacity(Color color, float opacity);

#endif