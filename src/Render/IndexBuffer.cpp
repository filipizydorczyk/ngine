#include "./IndexBuffer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace NGine
{

    /**
     * @brief Construct a new Index Buffer:: Index Buffer object. It will
     * also bind this buffer so if you want this unbound you need to unbind this
     * yourself
     * 
     * @param indices list of indexes to draw
     * @param count size of list in bytes
     */
    IndexBuffer::IndexBuffer(uint32_t *indices, uint32_t count)
    {
        glGenBuffers(1, &this->m_IndexBufferId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_IndexBufferId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count, indices, GL_STATIC_DRAW);
    };

    /**
     * @brief Destroy the Index Buffer:: Index Buffer object
     */
    IndexBuffer::~IndexBuffer()
    {
        glDeleteBuffers(1, &this->m_IndexBufferId);
    };

    /**
     * @brief Bind this index buffer
     */
    void IndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_IndexBufferId);
    };

    /**
     * @brief Unbind this index buffer
     */
    void IndexBuffer::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    };
};