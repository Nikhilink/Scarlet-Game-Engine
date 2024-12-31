#include "shader.h"

#include <glad/glad.h>

#include <fstream>
#include <sstream>
#include <iostream>

namespace Scarlet
{
    Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
    {
        
        std::string vertexSource = ReadFile(vertexPath);
        std::string fragmentSource = ReadFile(vertexPath);

        m_RendererID = CreateProgram(vertexSource, fragmentSource);

    }

    Shader::~Shader()
    {
        glDeleteProgram(m_RendererID);
    }

    void Shader::Bind() const
    {
        glUseProgram(m_RendererID);
    }

    void Shader::Unbind() const
    {
        glUseProgram(0);
    }

    unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
    {
        
        unsigned int id = glCreateShader(type);
        const char* src = source.c_str();
        
        glShaderSource(id, 1, &src, nullptr);
        glCompileShader(id);

        int result;

        glGetShaderiv(id, GL_COMPILE_STATUS, &result);
        if(!result)
        {
            char infoLog[512];
            glGetShaderInfoLog(id, 512, nullptr, infoLog);

            std::cerr<<"Shader compilation failed: " << infoLog << std::endl;
            glDeleteShader(id);

            return 0;
        }

        return id;

    }

    std::string Shader::ReadFile(const std::string& filePath)
    {
        std::ifstream file(filePath);
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    unsigned int Shader::CreateProgram(const std::string& vertexSource, const std::string& fragmentSource)
    {
        unsigned int program = glCreateProgram();
        unsigned int vertexShader = CompileShader(GL_VERTEX_SHADER, vertexSource);
        unsigned int fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentSource);

        glAttachShader(program, fragmentShader);
        glAttachShader(program, fragmentShader);
        glLinkProgram(program);
        glValidateProgram(program);
        glValidateProgram(program);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        return program;
    }

    void Shader::SetUniform(const std::string& name, float value)
    {
        glUniform1f(glGetUniformLocation(m_RendererID, name.c_str()), value);
    }

    void Shader::SetUniform(const std::string &name, int value)
    {
        glUniform1i(glGetUniformLocation(m_RendererID, name.c_str()), value);
    }

    void Shader::SetUniform(const std::string& name, const glm::vec3& value)
    {
        glUniform3fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, &value[0]);
    }

    void Shader::SetUniform(const std::string& name, const glm::mat4& value)
    {
        glUniformMatrix4fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, GL_FALSE, &value[0][0]);
    }
}