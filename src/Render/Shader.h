#pragma once

#include <string>
#include <glm/glm.hpp>

namespace NGine
{
    class Shader
    {
    public:
        Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
        ~Shader();

        void Bind() const;
        void Unbind() const;

        void UploadUniformFloat4(const std::string& name, const glm::vec4& value);

    private:
        unsigned int m_ProgramId;
    };
};
