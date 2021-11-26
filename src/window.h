#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace NGine{

    struct WindowData
    {
        unsigned int width;
        unsigned int height;
    };
    

    class Window {
        public:
            Window(WindowData data);
            ~Window();
            void init(WindowData data);
            void update();
            bool shouldClose();
            void close();

        private:
            WindowData m_WindowData;
            GLFWwindow *m_Window;

    };
}