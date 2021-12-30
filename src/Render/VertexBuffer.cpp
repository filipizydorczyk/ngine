#include "./VertexBuffer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace NGine
{
    /**
     * @brief Construct a new Vertex Buffer:: Vertex Buffer object
     */
    VertexBuffer::VertexBuffer() {
        glGenBuffers(1, &this->m_vertexBufferId);
    };

    /**
     * @brief Construct a new Vertex Buffer:: Vertex Buffer object
     * and writes data to it. This will also bind this buffer so
     * that it writes to correct one. It is your responsibility to
     * to unbind this buffer if it's necessery
     * 
     * @param vertices list of floats to write to data
     * @param size ammount of vertecies to write
     */
    VertexBuffer::VertexBuffer(float* vertices, uint32_t size) {
        glGenBuffers(1, &this->m_vertexBufferId);
        glBindBuffer(GL_ARRAY_BUFFER, this->m_vertexBufferId);
        glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), vertices, GL_STATIC_DRAW);
    };

    /**
     * @brief Destroy the Vertex Buffer:: Vertex Buffer object
     */
    VertexBuffer::~VertexBuffer() {
        glDeleteBuffers(1, &this->m_vertexBufferId);
    };

    /**
     * @brief Binds this buffer
     */
    void VertexBuffer::Bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, this->m_vertexBufferId);
    };

    /**
     * @brief Writes data to this buffer. This will also bind this 
     * buffer so that it writes to correct one. It is your 
     * responsibility to to unbind this buffer if it's necessery
     * 
     * @param vertices list of floats to write to data
     * @param size ammount of vertecies to write
     */
    void VertexBuffer::SetData(float* vertices, uint32_t size) {
        glBindBuffer(GL_ARRAY_BUFFER, this->m_vertexBufferId);
        glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), vertices, GL_STATIC_DRAW);
    };

    /**
     * @brief Unbinds this buffer
     */
    void VertexBuffer::Unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    };
};