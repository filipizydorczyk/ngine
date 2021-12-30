#pragma once

namespace NGine
{
    class VertexBuffer
    {
    public:
        VertexBuffer();
        VertexBuffer(float* vertices, uint32_t size);
        ~VertexBuffer();

        void Bind() const;
        void Unbind() const;

        void SetData(float* vertices, uint32_t size);

    private:
        unsigned int m_vertexBufferId;
    };
};