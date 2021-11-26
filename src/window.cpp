#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "spdlog/spdlog.h"
#include "./window.h"
#include "./logger.h"

namespace NGine {
    Window::Window(WindowData data){
        this->init(data);
    }

    Window::~Window(){}

    void Window::init(WindowData data){
        this->m_Window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
        if (!this->m_Window)
            this->close();

        glfwMakeContextCurrent(this->m_Window);
        // gladLoadGL();

        /* Registering window events */
        glfwSetWindowSizeCallback(this->m_Window, [](GLFWwindow* window, int width, int height){
            NGINE_INFO("{0}, {1}", width, height);
            glViewport(0,0,width,height);
        });


    }

    bool Window::shouldClose(){
        return glfwWindowShouldClose(this->m_Window);
    }

    void Window::update(){
        glfwSwapBuffers(this->m_Window);
    }

    void Window::close(){
        glfwTerminate();
    }
}