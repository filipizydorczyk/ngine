#include "./Renderer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace NGine
{
    /**
     * This methond will draw a triangle. This is more for testing purposes
     * at early stage than for actuall usage. Mayby in futere it will be removed
     * or refactored
     *
     * @param position coordinates where center of triangle should be placed
     * @param base length of triangle base
     * @param height length of triangle height
     */
    void Renderer::DrawTriangle(glm::vec2 position, float base, float height)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);

        glVertex2f(position.x, position.y + 0.5f * height);
        glVertex2f(position.x - 0.5f * base, position.y - 0.5f * height);
        glVertex2f(position.x + 0.5f * base, position.y - 0.5f * height);

        glEnd();
    }
};