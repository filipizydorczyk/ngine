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

            uniform mat4 u_ViewProjection;
            uniform mat4 u_Transform;

            void main()
            {
                gl_Position = u_Transform * vec4(a_Position, 1.0);
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

        float r = 0.0f;
        float increment = 0.05f;

        while (!this->m_AppWindow->ShouldClose())
        {
            Renderer::Clear();
            Renderer::DrawSquare(this->m_Shader, glm::vec4(r,1.0f,0.25f,1.0f), glm::vec2(0.5f,0.5f));
            Renderer::DrawTriangle(this->m_Shader, glm::vec4(r,0.20f,1.0f,1.0f), glm::vec2(0.25f,0.125f));
            this->m_AppWindow->Update();
            this->m_Shader->Unbind();
            glfwPollEvents();

            r += increment;
            if(r > 1.0f){
                increment = -0.05f;
            }
            else if(r < 0.0f){
                increment = 0.05f;
            }
        }

        this->m_AppWindow->Close();
    };

    void Application::Close()
    {
        this->m_AppWindow->Close();
    };
};