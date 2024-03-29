#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "../Core/Logger.h"
#include "./Shader.h"

namespace NGine
{

    static unsigned int CompileShader(unsigned int type, const std::string &sourceString)
    {
        unsigned int id = glCreateShader(type);
        const char *src = sourceString.c_str();
        glShaderSource(id, 1, &src, nullptr);
        glCompileShader(id);

        int result;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);

        if (!result)
        {
            int length;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
            char *message = (char *)alloca(length * sizeof(char));
            glGetShaderInfoLog(id, length, &length, message);
            NGINE_ERROR(message);

            glDeleteShader(id);
            return 0;
        }

        return id;
    };

    /**
     * @brief Construct a new Shader:: Shader object. It will create program and
     * both fragment and vertex shaders. Then it will attach and link created
     * shaders to created programs and delete those shaders. Also if shader
     * compilarion will fail at runtime engine logger will log it as an error.
     *
     * @param vertexSrc opengl source code for vertex shader
     * @param fragmentSrc opengl source code for fragment shader
     */
    Shader::Shader(const std::string &vertexSrc, const std::string &fragmentSrc)
    {
        this->m_ProgramId = glCreateProgram();
        unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexSrc);
        unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentSrc);

        glAttachShader(m_ProgramId, vs);
        glAttachShader(m_ProgramId, fs);
        glLinkProgram(m_ProgramId);
        glValidateProgram(m_ProgramId);

        glDeleteShader(vs);
        glDeleteShader(fs);
    };

    /**
     * @brief deletes created shader program
     *
     */
    Shader::~Shader()
    {
        glDeleteProgram(this->m_ProgramId);
    };

    /**
     * @brief Bind will use program of created shader
     *
     */
    void Shader::Bind() const
    {
        glUseProgram(this->m_ProgramId);
    };

    /**
     * @brief Bind will use program with id 0 which
     * basically means unbinding shader program
     *
     */
    void Shader::Unbind() const
    {
        glUseProgram(0);
    };

    void Shader::UploadUniformFloat4(const std::string &name, const glm::vec4 &value)
    {
        int location = this->GetLocation(name);

        glUniform4f(location, value.x, value.y, value.z, value.w);
    };

    void Shader::UploadUniformFloat3(const std::string &name, const glm::vec3 &value)
    {
        int location = this->GetLocation(name);

        glUniform3f(location, value.x, value.y, value.z);
    };

    void Shader::UploadUniformMat4(const std::string &name, const glm::mat4 &matrix)
    {
        int location = this->GetLocation(name);

        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    };

    int Shader::GetLocation(const std::string &name)
    {
        int location = glGetUniformLocation(this->m_ProgramId, name.c_str());
        if (location == -1)
        {
            NGINE_WARN("Uniform " + name + " doesn't exist!");
        }

        return location;
    };

};