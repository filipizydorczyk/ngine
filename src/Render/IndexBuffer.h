#pragma once
#include <stdint.h>

namespace NGine
{
    class IndexBuffer
    {
    public:
        IndexBuffer(uint32_t *indices, uint32_t count);
        ~IndexBuffer();

        void Bind() const;
        void Unbind() const;

    private:
        unsigned int m_IndexBufferId;
    };
};