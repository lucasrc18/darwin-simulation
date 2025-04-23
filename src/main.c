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

    Rect rect = newSquare(newVec2(100.0f, 100.0f), 50.0f);
    drawRect(rect, newColor(1.0f, 0.0f, 0.0f));

}