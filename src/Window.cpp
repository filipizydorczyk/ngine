#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "spdlog/spdlog.h"
#include "./Window.h"
#include "./Logger.h"

namespace NGine
{
    Window::Window(WindowData data)
    {
        this->Init(data);
    }

    Window::~Window() = default;

    void Window::Init(WindowData data)
    {
        this->m_WindowData = data;
        this->m_Window = glfwCreateWindow(this->m_WindowData.width, this->m_WindowData.height, "Hello World", NULL, NULL);
        if (!this->m_Window)
            this->Close();

        glfwMakeContextCurrent(this->m_Window);

        /* Registering window events */
        glfwSetWindowSizeCallback(this->m_Window, [](GLFWwindow *window, int width, int height){
            NGINE_INFO("{0}, {1}", width, height);
            glViewport(0,0,width,height); 
        });
    }

    bool Window::ShouldClose() const
    {
        return glfwWindowShouldClose(this->m_Window);
    }

    void Window::Update()
    {
        glfwSwapBuffers(this->m_Window);
    }

    void Window::Close()
    {
        glfwTerminate();
    }
}