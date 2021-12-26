#include "./Renderer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace NGine
{
    struct RendererData
    {
        unsigned int triangleBuffer;
    };

    static RendererData s_RendererData;

    /**
     * This method needs to be run before any draw calls. Some functions may work without 
     * initialization like (for example Renderer::DrawTriangleLegacy) but others wont
     * (like Renderer::DrawTriangle)
     */
    void Renderer::Init()
    {
        float trianglePostitions[3 * 2] = {
            -0.5f, -0.5f,
             0.0f,  0.5f,
             0.5f, -0.5f
        };

        glGenBuffers(1, &s_RendererData.triangleBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, s_RendererData.triangleBuffer);
        glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), trianglePostitions, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

    }

    /**
     * This function will draw a simple triangle usign modern opengl api. For now
     * it uses only vertex buffer but will be refactored to using index buffer
     */
    void Renderer::DrawTriangle()
    {
        glBindBuffer(GL_ARRAY_BUFFER, s_RendererData.triangleBuffer);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    /**
     * This methond will draw a triangle. This is more for testing purposes
     * at early stage than for actuall usage. Mayby in futere it will be removed
     * or refactored
     *
     * @param position coordinates where center of triangle should be placed
     * @param base length of triangle base
     * @param height length of triangle height
     */
    void Renderer::DrawTriangleLegacy(glm::vec2 position, float base, float height)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);

        glVertex2f(position.x, position.y + 0.5f * height);
        glVertex2f(position.x - 0.5f * base, position.y - 0.5f * height);
        glVertex2f(position.x + 0.5f * base, position.y - 0.5f * height);

        glEnd();
    }
};