#include "window.hpp"

Window::Window(const char* title) {
    const int width = 800, height = 600;

    if(!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW.\n");
        exit(EXIT_FAILURE);
    }

    this->frame = (GLFWwindow*) glfwCreateWindow(width, height, title, NULL, NULL);
    
    extern const Color BLACK;
    this->background = BLACK;

    if(!this->frame){
        fprintf(stderr, "Failed to create GLFW window.\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}

Window::Window(const char* title, int width, int height) {
    if(!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW.\n");
        exit(EXIT_FAILURE);
    }

    this->frame = (GLFWwindow*) glfwCreateWindow(width, height, title, NULL, NULL);

    extern const Color BLACK;
    this->background = BLACK;

    if(!this->frame){
        fprintf(stderr, "Failed to create GLFW window.\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}

int Window::terminate(){
    glfwDestroyWindow(this->frame);

    delete this;

    return 0;
}

void Window::mainLoop(void (*render)()){
    while(!glfwWindowShouldClose(this->frame)){
        glClear(GL_COLOR_BUFFER_BIT);

        if(render != NULL){
            render();
        }

        glfwSwapBuffers(this->frame);
        glfwPollEvents();
    }
}

int terminateAllWindow(){
    glfwTerminate();

    return 0;
}

int setContext(Window window){
    if (window.frame == NULL) return -1;

    glfwMakeContextCurrent(window.frame);

    GLenum err = glewInit();
    if (err != GLEW_OK){
        fprintf(stderr, "Failed to initialize GLEW.\n");
        return -1;
    }

    Color background = window.background;
    glClearColor(background.r, background.g, background.b, background.a);

    // Configure viewport and projection matrix
    // by default top left is (0, 1) while bottom right is (1, 0)
    // now top left is (0, 0) while bottom right is (width, height)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // glOrtho(0, window.width, window.height, 0, -1, 1);
    glOrtho(0, 800, 600, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    return 0;
}
