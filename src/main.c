#include <stdio.h>

#include "window.h"
#include "renderer.h"

/**
 * Function that handles rendering in the main loop
 */
void render();

/**
 * Entry point of the program
 *  The program flow is based on
 *  1. Initializing the window
 *  2. Attempting to set up context for the window 
 *  3. Entering the main loop
 *  4. Terminating the window on user close
 *  
 *  @return 0 on success, -1 on failure
 */
int main(void){
    Window* window = createWindow("Darwin Theory Simulation [800x600] v1.0");

    if (setContext(window) != 0) { 
        fprintf(stderr, "Failed to initialize window.\n");
        return -1;
    }

    mainLoop(window, render);

    // it should return 0 on successful closure
    return terminateWindow(window);
}

void render(){
    Rect r1 = newCentralizedRect(100.0f, 100.0f);

    Rect r2 = newRect(newVec2(0.0f, 0.0f), 30.0f, 30.0f);
    r2 = centralizeRect(r2);

    drawRect(r1, newColor(1.0f, 0.0f, 0.0f));
    drawRect(r2, newColor(0.0f, 1.0f, 0.0f));
}