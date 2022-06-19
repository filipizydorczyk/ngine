#include <glad/glad.h>
#include "../Core/Logger.h"
#include "./Shader.h"

namespace NGine
{

    static unsigned int CompileShader(unsigned int type, const std::string& sourceString){
        unsigned int id = glCreateShader(type);
        const char* src = sourceString.c_str();
        glShaderSource(id, 1, &src, nullptr);
        glCompileShader(id);


        int result;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);

        if(!result){
            int length;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
            char* message = (char*)alloca(length * sizeof(char));
            glGetShaderInfoLog(id, length, &length, message);
            NGINE_ERROR(message);

            glDeleteShader(id);
            return 0;
        }

        return id;
    };

    Shader::Shader(const std::string& vertexSrc, const std::string& fragmentSrc){
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

    Shader::~Shader(){
        glDeleteProgram(this->m_ProgramId);
    };

    void Shader::Bind() const {
        glUseProgram(this->m_ProgramId);
    };

    void Shader::Unbind() const {
        glUseProgram(0);
    };

};