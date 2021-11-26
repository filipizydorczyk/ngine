#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "spdlog/spdlog.h"
#include "./logger.h"

int main(void)
{
    NGINE_INFO("Test info");
    NGINE_ERROR("Test error");
    NGINE_WARN("Test warn");

    GLFWwindow *window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    gladLoadGL();

    glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height){
        NGINE_INFO("{0}, {1}", width, height);
    });

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);

        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);

        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}