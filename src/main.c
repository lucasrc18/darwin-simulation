#include <stdio.h>

#include "window.h"
#include "renderer.h"

void render();

int main(void){
    Window* window = createWindow(800, 600, "Darwin Theory Simulation [800x600] v1.0");

    if (setContext(window) != 0) { 
        fprintf(stderr, "Failed to initialize window.\n");
        return -1;
    }

    mainLoop(window, render);

    terminateWindow(window);

    return 0;
}

void render(){

    Rect topleft = newRect(newVec2(-1, 0), 0.5, 0.5);

    Rect topRight = newRect(newVec2(0, 0), 0.5, 0.5);

    Rect bottomLeft = newRect(newVec2(-1, -1), 0.5, 0.5);

    Rect bottomRight = newRect(newVec2(0, -1), 0.5, 0.5);

    drawRect(topleft, newColor(1.0f, 0.0f, 0.0f));
    drawRect(topRight, newColor(0.0f, 1.0f, 0.0f));
    drawRect(bottomLeft, newColor(0.0f, 0.0f, 1.0f));
    drawRect(bottomRight, newColor(1.0f, 0.0f, 1.0f));

}