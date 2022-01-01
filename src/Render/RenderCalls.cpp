#include "./RenderCalls.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace NGine {
    
    /**
     * @brief Clears screen
     */
    void RenderCalls::Clear() {
        glClear(GL_COLOR_BUFFER_BIT);
    };

    /**
     * @brief Draw currently bound index array
     * 
     * @param count ammount of indecies to draw
     */
    void RenderCalls::DrawIndexed(uint32_t count) {
        glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
    };

    /**
     * @brief Draws currently bound array buffer
     * 
     * @param first starting index in the enabled array
     * @param count number of indices to be rendered. 
     */
    void RenderCalls::DrawArrays(int32_t first, uint32_t count) {
        glDrawArrays(GL_TRIANGLES, first, count);
    };
};