#pragma once

#include "shader.h"

#include <glm/glm.hpp>
#include <string>
#include <memory>

namespace Scarlet
{
    class Renderer2D
    {
        public:
            static void Init();
            static void Clear(const glm::vec4& color);
            static void Draw();
            static void Shutdown();

            static void DrawSquare(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
            static void DrawCircle(const glm::vec2& position, float radius, const glm::vec4& color);

        private:
            static unsigned int s_SquareVAO, s_SquareVBO, s_SquareEBO;
            static std::shared_ptr<Shader> s_Shader;
    };
}