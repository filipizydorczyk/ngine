#include "./Renderer.h"
#include "./VertexBuffer.h"
#include "./ArrayBuffer.h"
#include "./IndexBuffer.h"
#include "./RenderCalls.h"
#include "./Shader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <stdint.h>
#include <memory>

namespace NGine
{
    struct RendererData
    {
        std::unique_ptr<NGine::VertexBuffer> triangleVertexBuffer = nullptr;
        std::unique_ptr<NGine::ArrayBuffer> triangleArrayBuffer = nullptr;
        
        std::unique_ptr<NGine::VertexBuffer> squareVertexBuffer = nullptr;
        std::unique_ptr<NGine::IndexBuffer> squareIndexBuffer = nullptr;
        std::unique_ptr<NGine::ArrayBuffer> squareArrayBuffer = nullptr;
    };

    static RendererData s_RendererData;

    /**
     * @brief This method needs to be run before any draw calls. Some functions may work without 
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

        s_RendererData.squareIndexBuffer = std::make_unique<NGine::IndexBuffer>(
            squareIndecies, 
            6 * sizeof(unsigned int)
        );
        
        s_RendererData.squareIndexBuffer->Unbind();
        s_RendererData.squareVertexBuffer->Unbind();
        s_RendererData.squareArrayBuffer->Unbind();
    };

    /**
     * @brief This function will draw a simple triangle usign modern opengl api. For now
     * it uses only vertex buffer but will be refactored to using index buffer
     */
    void Renderer::DrawTriangle(const std::unique_ptr<NGine::Shader>& shader, const glm::vec4& color, const glm::vec2& position)
    {
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), { position.x, position.y, 0 });

        s_RendererData.triangleArrayBuffer->Bind();
        shader->Bind();
        shader->UploadUniformFloat4("u_Color", color);
        shader->UploadUniformMat4("u_Transform", transform);
        RenderCalls::DrawArrays(0, 3);
        shader->Unbind();
        s_RendererData.triangleArrayBuffer->Unbind();
    };

    /**
     * @brief Draws simple square. For now it's basic inmplementation with made with index
     * buffer.
     */
    void Renderer::DrawSquare(const std::unique_ptr<NGine::Shader>& shader, const glm::vec4& color, const glm::vec2& position){
        // glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), { position.x, position.y, 0 });
        
        s_RendererData.squareArrayBuffer->Bind();
        s_RendererData.squareIndexBuffer->Bind();
        shader->Bind();
        shader->UploadUniformFloat4("u_Color", color);
        shader->UploadUniformMat4("u_Transform", transform);
        RenderCalls::DrawIndexed(6);
        shader->Unbind();
        s_RendererData.squareIndexBuffer->Unbind();
        s_RendererData.squareArrayBuffer->Unbind();
    };

    /**
     * @brief Just clears the screen from all redered stuff
     */
    void Renderer::Clear(){
        RenderCalls::Clear();
    };
};