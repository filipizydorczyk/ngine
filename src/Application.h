#pragma once
#include "./Window.h"
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
        // bool m_IsRunning = false;
    };
};