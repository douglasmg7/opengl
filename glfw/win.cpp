#include "include/glad/glad.h"
/* 
    https://www.glfw.org/
    GLFW, as the name implies, is a C library specifically designed for use with OpenGL.
    Unlike SDL and SFML it only comes with the absolute necessities: window and context creation and input management.
    It offers the most control over the OpenGL context creation out of these three libraries.
    /usr/include/GLFW/glfw3.h
    /usr/lib/libglfw.so 
*/
#include <GLFW/glfw3.h>     

#include <iostream>
using namespace std;

void error_callback(int, const char*);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    // Inint glfw.
    if (!glfwInit()){
        fprintf(stderr, "Error initializing glfw.\n");
    }
    // Error calback.
    glfwSetErrorCallback(error_callback);
    // The glfwWindowHint function is used to specify additional requirements for a window.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    // The GLFW_OPENGL_PROFILE option specifies that we want a context that only supports the new core functionality.
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    // Create window and context.
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL", NULL, NULL); // Windowed.
    // GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL", glfwGetPrimaryMonitor(), nullptr); // Fullscreen.
    if (window == NULL)
    {
        cout << "Window or OpenGL context creation failed" << endl;
        glfwTerminate();
        return 1;
    }
    // Current OpenGL context.
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }

    // Color.
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    // Render loop.
    while(!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers.
        glfwSwapBuffers(window);
        // Poll IO events (keys pressed/released, mouse moved etc.).
        glfwPollEvents();    

        // if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            // glfwSetWindowShouldClose(window, GL_TRUE);
    }

    // Destroy window.
    glfwDestroyWindow(window);
    // Finalize glfw.
    glfwTerminate();
}

void error_callback(int error, const char* description)
{
    cout << "Error: " << description << endl;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
