#pragma once
#include <glm/glm.hpp>
#include <memory>
#include "./Shader.h"

namespace NGine
{
    class Renderer
    {
    public:
        static void Init();

        static void DrawTriangle();
        static void DrawTriangleLegacy(glm::vec2 position, float base, float height);
        static void DrawSquare(const std::unique_ptr<NGine::Shader>& m_Shader, const glm::vec4& color);

        static void Clear();
    };
};
