#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace NGine
{

    class Window
    {
    public:
        struct WindowData
        {
            unsigned int width;
            unsigned int height;
        };

        Window(WindowData data);
        ~Window();
        void Init(WindowData data);
        void Update();
        bool ShouldClose() const;
        void Close();

    private:
        WindowData m_WindowData;
        GLFWwindow *m_Window;
    };
};