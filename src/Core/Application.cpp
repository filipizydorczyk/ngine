#include <glm/glm.hpp>
#include "./Application.h"
#include "./Window.h"
#include "../Render/Renderer.h"

namespace NGine
{
    Application::Application()
    {
        glfwInit();
        this->m_AppWindow = std::make_unique<NGine::Window>(NGine::Window({1280, 720}));
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

        std::string vertexShader = R"(
            #version 330 core

            layout(location = 0) in vec3 a_Position;

            void main()
            {
                gl_Position = vec4(a_Position, 1.0);
            }
        )";

        std::string fragmentShader = R"(
            #version 330 core

            layout(location = 0) out vec4 color;

            uniform vec4 u_Color;

            void main()
            {
                color = u_Color;
            }
        )";

        this->m_Shader.reset(new NGine::Shader(vertexShader,fragmentShader));
    };

    Application::~Application() = default;

    void Application::Run()
    {
        Renderer::Init();

        while (!this->m_AppWindow->ShouldClose())
        {
            Renderer::Clear();
            this->m_Shader->Bind();
            this->m_Shader->UploadUniformFloat4("u_Color", glm::vec4(0.5f,1.0f,0.25f,1.0f));
            Renderer::DrawSquare();
            // Renderer::DrawTriangle();
            this->m_AppWindow->Update();
            this->m_Shader->Unbind();
            glfwPollEvents();
        }

        this->m_AppWindow->Close();
    };

    void Application::Close()
    {
        this->m_AppWindow->Close();
    };
};