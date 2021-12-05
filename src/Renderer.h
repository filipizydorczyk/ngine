#pragma once
#include <glm/glm.hpp>

namespace NGine
{

    class Renderer
    {
    public:
        static void DrawTriangle(glm::vec2 position, float base, float height);
    };
};
