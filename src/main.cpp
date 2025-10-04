#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main(void)
{
    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "Error! Failed to initialize glfw!" << std::endl;

        return -1;
    }

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow*  pWindow = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!pWindow)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);

    if (!gladLoadGL())
    {
        std::cout << "Error! Can't load GLAD!" << std::endl;
        return -1;
    }

    std::cout << "OpenGL" << GLVersion.major << "." << GLVersion.minor << std::endl;

    glClearColor(100, 100, 0, 100);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pWindow))
    {
        /* Render here */
       glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
