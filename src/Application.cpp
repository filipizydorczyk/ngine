#include "./Application.h"
#include "./Window.h"
#include "./Renderer.h"

namespace NGine
{
    Application::Application()
    {
        glfwInit();
        this->m_AppWindow = std::make_unique<NGine::Window>(NGine::Window({1280, 720}));
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    };

    Application::~Application() = default;

    void Application::Run()
    {
        while (!this->m_AppWindow->ShouldClose())
        {
            Renderer::DrawTriangle(glm::vec2(0.0f, 0.0f), 0.5f, 0.5f);
            this->m_AppWindow->Update();
            glfwPollEvents();
        }

        this->m_AppWindow->Close();
    }

    void Application::Close()
    {
        this->m_AppWindow->Close();
    }
};