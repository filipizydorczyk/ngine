#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "./Core/Logger.h"
#include "./Core/Window.h"
#include "./Core/Application.h"

int main(void)
{
    NGINE_INFO("Test info");
    NGINE_ERROR("Test error");
    NGINE_WARN("Test warn");

    NGine::Application app;
    app.Run();

    return 0;
}