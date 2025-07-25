#include <iostream>
#include <cstdlib>

#include "window.hpp"
#include "polygons.cpp"

/**
 * Function that handles states and other updates in the main loop
 */
void update();

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
    Window window = Window("Darwin Theory Simulation [800x600] v1.0");

    if(setContext(window) != 0){
        std::cerr << "Failed to initialize window." << std::endl;
        return -1;
    }

    window.mainLoop(render);

    // it should return 0 on sucessful termination
    return terminateAllWindow();
}

void update(){
    
}

void render(){
    Rect r = Rect(Vector2(100.0f, 100.0f), 20.f, 40.f);
    Circle c = Circle(Vector2(400.0f, 300.0f), 50.0f);
    
    c.render(Color(1.0f, 0.0f, 0.0f, 1.0f));
    r.render(Color(0.0f, 1.0f, 0.0f, 1.0f));
}  