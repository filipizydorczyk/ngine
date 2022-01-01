#pragma once
#include <stdint.h>

namespace NGine
{
    class RenderCalls {
        public:
            static void Clear();
            static void DrawIndexed(uint32_t count);
            static void DrawArrays(int32_t first, uint32_t count);
    };
};