#include "renderer.h"

#include <glad/glad.h>

namespace Scarlet
{
    unsigned int Renderer2D::s_SquareVAO;
    unsigned int Renderer2D::s_SquareVBO;
    unsigned int Renderer2D::s_SquareEBO;

    std::shared_ptr<Shader> Renderer2D::s_Shader;
    void Renderer2D::Init()
    {

        float vertices[] = {
            0.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            1.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f
        };

        unsigned int indices[] = {
            0, 1, 2,
            3, 2, 0
        };

        glGenVertexArrays(1, &s_SquareVAO);
        glGenBuffers(1, &s_SquareVBO);
        glGenBuffers(1, &s_SquareEBO);

        glBindVertexArray(s_SquareVAO);

        glBindBuffer(GL_ARRAY_BUFFER, s_SquareVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glEnable(GL_DEPTH_TEST);

    }

    void Renderer2D::Clear(const glm::vec4& color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Renderer2D::Draw()
    {

    }

    void Renderer2D::Shutdown()
    {

    }
}