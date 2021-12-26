#pragma once
#include <glm/glm.hpp>

namespace NGine
{

    class Renderer
    {
    public:
        static void Init();

        static void DrawTriangle();
        static void DrawTriangleLegacy(glm::vec2 position, float base, float height);

        static void Clear();
    };
};
