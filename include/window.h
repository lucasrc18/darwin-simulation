#ifndef WINDOW_H
#define WINDOW_H

#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "utils.h"

typedef struct {
    GLFWwindow* frame;
    Color backgroundColor;
} Window;

int setContext(Window* window);
int terminateWindow(Window* window);
void mainLoop(Window* window, void (*toRender)());
void* createWindow(const char* title);

#endif