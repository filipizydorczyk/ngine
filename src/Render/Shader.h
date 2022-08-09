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
        void UploadUniformFloat3(const std::string& name, const glm::vec3& value);

        void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);

    private:
        unsigned int m_ProgramId;

        int GetLocation(const std::string& name);
    };
};
