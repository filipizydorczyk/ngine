#pragma once
#include <stdint.h>

namespace NGine
{
    class ArrayBuffer
    {
    public:
        ArrayBuffer();
        ~ArrayBuffer();

        void Bind() const;
        void Unbind() const;
    private:
        unsigned int m_ArrayBufferId;
    };
};