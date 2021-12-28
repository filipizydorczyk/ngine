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
        Renderer::Init();

        while (!this->m_AppWindow->ShouldClose())
        {
            Renderer::Clear();
            Renderer::DrawSquare();
            // Renderer::DrawTriangle();
            this->m_AppWindow->Update();
            glfwPollEvents();
        }

        this->m_AppWindow->Close();
    };

    void Application::Close()
    {
        this->m_AppWindow->Close();
    };
};