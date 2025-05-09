cmake_minimum_required(VERSION 3.5)
project(DarwinSimulation VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/glfw3/" ${CMAKE_PREFIX_PATH})

set(SOURCES 
    src/main.cpp
    src/window.cpp
    src/utils.cpp
)

add_executable(DarwinSimulation ${SOURCES})

target_include_directories(DarwinSimulation PRIVATE include)

cmake_policy(SET CMP0072 NEW)

find_package(OpenCV REQUIRED PATHS /usr/lib/x86_64-linux-gnu/cmake/opencv4)

target_include_directories(DarwinSimulation PRIVATE ${OpenCV_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(DarwinSimulation PRIVATE ${OpenCV_LIBS} glfw GLEW::GLEW OpenGL::GL m)