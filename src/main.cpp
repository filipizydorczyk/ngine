#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "./logger.h"
#include "./window.h"

int main(void)
{
    NGINE_INFO("Test info");
    NGINE_ERROR("Test error");
    NGINE_WARN("Test warn");

    glfwInit();
    NGine::Window window = NGine::Window({1280,720});
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    while (!window.shouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);

        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);

        glEnd();
        window.update();
        glfwPollEvents();
    }

    window.close();
    return 0;
}