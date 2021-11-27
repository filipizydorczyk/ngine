#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace NGine
{

    struct WindowData
    {
        unsigned int width;
        unsigned int height;
    };

    class Window
    {
    public:
        Window(WindowData data);
        ~Window();
        void Init(WindowData data);
        void Update();
        bool ShouldClose();
        void Close();

    private:
        WindowData m_WindowData;
        GLFWwindow *m_Window;
    };
}