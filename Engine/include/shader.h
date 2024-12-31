#pragma once

#include <string>
#include <glm/glm.hpp>

namespace Scarlet
{
    class Shader
    {
        public:
            Shader(const std::string& vertexPath, const std::string& fragmnetPath);
            ~Shader();

            void Bind() const;
            void Unbind() const;

            // Set Uniforms
            void SetUniform(const std::string& name, float value);
            void SetUniform(const std::string& name, int value);
            void SetUniform(const std::string& name, const glm::vec3& value);
            void SetUniform(const std::string& name, const glm::mat4& value);

        private:
            unsigned int m_RendererID;

            unsigned int CompileShader(unsigned int type, const std::string& source);
            std::string ReadFile(const std::string& filepath);
            unsigned int CreateProgram(const std::string& vertexSource, const std::string& fragmentSource);
    };
}