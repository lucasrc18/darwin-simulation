#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <cstdio>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "utils.hpp"

/* ======================== Window Class ======================== */

/**
 * Window class for GLFW graphics
 */
class Window {
public: 
    // Background color when nothing over it
    Color background;
    // GLFW Window actual object
    GLFWwindow* frame;
    
    int width, height;

    /**
     * Create a window with specified title
     * 
     * @param title The title of the window
     * 
     * @see Window(const char* title, int width, int height)
     * 
     * @example Window window = Window("Darwin Theory Simulation [800x600] v1.0");
     * 
     * @note The default window size is 800x600
     */
    Window(const char* title);

    /**
     * Create a window with specified title and size
     * 
     * @param title The title of the window
     * @param width The width of the window
     * @param height The height of the window
     * 
     * @example Window window = Window("Darwin Theory Simulation [800x600] v1.0", 800, 600);
     */
    Window(const char* title, int width, int height);

    /**
     * Destroy the window and terminate GLFW
     * 
     * @return 0 on success, -1 on failure
     * 
     * @see terminateAllWindow()
     */
    int terminate();

    /**
     * Main loop for the window
     * 
     * @param window The window to run the loop on
     * @param toRender The function to call to render the scene
     */ 
    void mainLoop(void (*render)());
};

/* ======================== Window Functions ======================== */

/**
 * Destroy the window and terminate GLFW
 * 
 * @param window The window to terminate
 * @return 0 on success, -1 on failure
 */
int terminateAllWindow();

/**
 * Set up context for the window, and define it
 * as the current context
 * 
 * @param window The window to set up context for
 * @return 0 on success, -1 on failure
 */
int setContext(Window window);

#endif