#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "./Logger.h"
#include "./Window.h"

int main(void)
{
    NGINE_INFO("Test info");
    NGINE_ERROR("Test error");
    NGINE_WARN("Test warn");

    glfwInit();
    NGine::Window window = NGine::Window({1280, 720});
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    while (!window.ShouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);

        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);

        glEnd();
        window.Update();
        glfwPollEvents();
    }

    window.Close();
    return 0;
}