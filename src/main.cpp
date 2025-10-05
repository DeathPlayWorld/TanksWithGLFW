#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int g_windowSizeX = 640;
int g_windowSizeY = 480;

void glfwWindowCallback(GLFWwindow* pWindow, int width, int height)
{
    g_windowSizeX = width;
    g_windowSizeY = height;
    glViewport(0, 0, g_windowSizeX, g_windowSizeY);
}

void glfwKeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}

int main(void)
{
    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "GLFW: Error! Failed to initialize glfw!" << std::endl;

        return -1;
    }

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow*  pWindow = glfwCreateWindow(g_windowSizeX, g_windowSizeY, "Hello World", nullptr, nullptr);
    if (!pWindow)
    {
        std::cout << "GLFW: Error! Can't create window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeCallback(pWindow, glfwWindowCallback);
    glfwSetKeyCallback(pWindow, glfwKeyCallback);

    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);

    if (!gladLoadGL())
    {
        std::cout << "GLAD: Error! Can't load GLAD!" << std::endl;
        return -1;
    }

    std::cout << "Renderer:" << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version:" << glGetString(GL_VERSION) << std::endl;

    glClearColor(1, 1, 1, 1);

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
