#ifndef WINDOW_H
#define WINDOW_H

#include "utils.h"

/**
 * Set up context for the window, and define it
 * as the current context
 * 
 * @param window The window to set up context for
 * @return 0 on success, -1 on failure
 */
int setContext(Window* window);

/**
 * Destroy the window and terminate GLFW
 * 
 * @param window The window to terminate
 * @return 0 on success, -1 on failure
 */
int terminateWindow(Window* window);

/**
 * Main loop for the window
 * 
 * @param window The window to run the loop on
 * @param toRender The function to call to render the scene
 */
void mainLoop(Window* window, void (*toRender)());

/**
 * Create a GLFW window
 * 
 * @param title The title of the window
 * @return A pointer to the window on success, NULL on failure
 */
void* createWindow(const char* title);

#endif