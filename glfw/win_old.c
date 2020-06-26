#include <stdio.h>
#include "include/glad/glad.h"
#include <GLFW/glfw3.h>

void error_callback(int, const char*);

int main() {
    // Inint glfw.
    if (!glfwInit()){
        fprintf(stderr, "Error initializing glfw.\n");
    }
    // Error calback.
    glfwSetErrorCallback(error_callback);
    // Min version.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    // Create window and context.
    GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
    if (!window)
    {
        fprintf(stderr, "Window or OpenGL context creation failed\n");
    }
    // Current OpenGL context.
    glfwMakeContextCurrent(window);
    /* gladLoadGL(glfwGetProcAddress); */




    // Destroy window.
    glfwDestroyWindow(window);
    // Finalize glfw.
    glfwTerminate();
}

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}
