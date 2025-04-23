cmake_minimum_required(VERSION 3.5)
project(DarwinSimulation VERSION 1.0)

set(CMAKE_C_STANDARD 11)

set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/glfw3/" ${CMAKE_PREFIX_PATH})

set(SOURCES 
    src/main.c
    src/renderer.c
    src/window.c
    src/utils.c
)

add_executable(DarwinSimulation ${SOURCES})

target_include_directories(DarwinSimulation PRIVATE include)

cmake_policy(SET CMP0072 NEW)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

target_link_libraries(DarwinSimulation PRIVATE glfw GLEW::GLEW OpenGL::GL)
