#include "window.h";

void* createWindow(int width, int height, const char* title) {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return NULL;
    }
    
    Window* window = (Window*) malloc(sizeof(Window));
    if (window == NULL) {
        fprintf(stderr, "Out of memory error!\n");
        return NULL;
    }

    window->frame = glfwCreateWindow(width, height, title, NULL, NULL);
    window->backgroundColor = newColor(0.0f, 0.0f, 0.0f);

    if (!window->frame) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return NULL;
    }

    // Configure viewport and projection matrix
    // by default top left is (0, 1) while bottom right is (1, 0)
    // now top left is (0, 0) while bottom right is (width, height)
    glOrtho(0, width, height, 0, -1, 1);

    return window;
}

int setContext(Window* window) {
    if (window->frame == NULL) return -1;
    
    glfwMakeContextCurrent((GLFWwindow*) window->frame);
    
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        fprintf(stderr, "GLEW initialization failed: %s\n", glewGetErrorString(err));
        return -1;
    }
    
    float r, g, b, a;
    r = window->backgroundColor.r;
    g = window->backgroundColor.g;
    b = window->backgroundColor.b;
    a = window->backgroundColor.a;
    
    glClearColor(r, g, b, a);
    
    return 0;
}

void mainLoop(Window* window, void (*toRender)()){
    while (!glfwWindowShouldClose(window->frame)){
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);
        
        // Call render function only if it's not NULL
        if (toRender != NULL) {
            toRender();
        }
        
        glfwSwapBuffers(window->frame);
        glfwPollEvents();
    }
}

int terminateWindow(Window* window){
    if (window) {
        if (window->frame){
            glfwDestroyWindow((GLFWwindow*) window->frame);
            glfwTerminate();
        }

        free(window);
    }

    return 0;
}
