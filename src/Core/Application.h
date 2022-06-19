#pragma once
#include "./Window.h"
#include "../Render/Shader.h"
#include <memory>

namespace NGine
{
    class Application
    {
    public:
        Application();
        ~Application();
        void Run();
        void Close();

    private:
        std::unique_ptr<NGine::Window> m_AppWindow;
        std::unique_ptr<NGine::Shader> m_Shader;
        // bool m_IsRunning = false;
    };
};