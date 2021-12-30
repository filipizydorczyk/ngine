#include "./ArrayBuffer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace NGine
{
    /**
     * @brief Construct a new Array Buffer:: Array Buffer object
     * Note that it will also bind this array buffer so it is
     * your responibility to unbind if it is necessery
     */
    ArrayBuffer::ArrayBuffer() {
        glGenVertexArrays(1, &this->m_ArrayBufferId);
        glBindVertexArray(m_ArrayBufferId);
    };

    /**
     * @brief Destroy the Array Buffer:: Array Buffer object
     */
    ArrayBuffer::~ArrayBuffer() {
        glDeleteVertexArrays(1, &this->m_ArrayBufferId);
    };

    /**
     * @brief Bind this array buffer
     */
    void ArrayBuffer::Bind() const {
        glBindVertexArray(m_ArrayBufferId);
    };

    /**
     * @brief Unbind this array buffer
     */
    void ArrayBuffer::Unbind() const {
        glBindVertexArray(0);
    };
};