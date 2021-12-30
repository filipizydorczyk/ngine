#include "./Renderer.h"
#include "./VertexBuffer.h"
#include "./ArrayBuffer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <stdint.h>
#include <memory>

namespace NGine
{
    struct RendererData
    {
        unsigned int squareIndexBuffer;

        std::unique_ptr<NGine::VertexBuffer> triangleVertexBuffer = nullptr;
        std::unique_ptr<NGine::ArrayBuffer> triangleArrayBuffer = nullptr;
        
        std::unique_ptr<NGine::VertexBuffer> squareVertexBuffer = nullptr;
        std::unique_ptr<NGine::ArrayBuffer> squareArrayBuffer = nullptr;
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
        
        s_RendererData.triangleArrayBuffer = std::make_unique<NGine::ArrayBuffer>();
        s_RendererData.triangleVertexBuffer = std::make_unique<NGine::VertexBuffer>(
            trianglePostitions, 6
        );

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
        
        s_RendererData.triangleVertexBuffer->Unbind();
        s_RendererData.triangleArrayBuffer->Unbind();

        float squarePostitions[4 * 2] = {
            -0.5f, -0.5f,
             0.5f,  0.5f,
             0.5f, -0.5f,
            -0.5f,  0.5f
        };

        unsigned int squareIndecies[] = {
            0, 1, 2,
            3, 0, 1
        };

        s_RendererData.squareArrayBuffer = std::make_unique<NGine::ArrayBuffer>();
        s_RendererData.squareVertexBuffer = std::make_unique<NGine::VertexBuffer>(
            squarePostitions, 8
        );

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

        glGenBuffers(1, &s_RendererData.squareIndexBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s_RendererData.squareIndexBuffer);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), squareIndecies, GL_STATIC_DRAW);
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        s_RendererData.squareVertexBuffer->Unbind();
        s_RendererData.squareArrayBuffer->Unbind();
    };

    /**
     * This function will draw a simple triangle usign modern opengl api. For now
     * it uses only vertex buffer but will be refactored to using index buffer
     */
    void Renderer::DrawTriangle()
    {
        s_RendererData.triangleArrayBuffer->Bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        s_RendererData.triangleArrayBuffer->Unbind();
    };

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
        glBegin(GL_TRIANGLES);

        glVertex2f(position.x, position.y + 0.5f * height);
        glVertex2f(position.x - 0.5f * base, position.y - 0.5f * height);
        glVertex2f(position.x + 0.5f * base, position.y - 0.5f * height);

        glEnd();
    };

    /**
     * Draws simple square. For now it's basic inmplementation with made with index
     * buffer.
     */
    void Renderer::DrawSquare(){
        s_RendererData.squareArrayBuffer->Bind();
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s_RendererData.squareIndexBuffer);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        s_RendererData.squareArrayBuffer->Unbind();
    };

    /**
     * Just clears the screen from all redered stuff
     */
    void Renderer::Clear(){
        glClear(GL_COLOR_BUFFER_BIT);
    };
};