#include <stdio.h>

#include "window.h"
#include "renderer.h"

void render();

int main(void){
    Window* window = createWindow("Darwin Theory Simulation [800x600] v1.0");

    if (setContext(window) != 0) { 
        fprintf(stderr, "Failed to initialize window.\n");
        return -1;
    }

    mainLoop(window, render);

    terminateWindow(window);

    return 0;
}

void render(){
    Rect r1 = newCentralizedRect(100.0f, 100.0f);

    Rect r2 = newRect(newVec2(0.0f, 0.0f), 30.0f, 30.0f);
    r2 = centralizeRect(r2);

    drawRect(r1, newColor(1.0f, 0.0f, 0.0f));
    drawRect(r2, newColor(0.0f, 1.0f, 0.0f));
}