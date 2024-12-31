#pragma once

#include <string>

#include <GLFW/glfw3.h>

#include "input/input_manager.h"

namespace Scarlet
{
    class Window {
    public:
        struct Properties {
            std::string title;
            int width;
            int height;

            Properties(const std::string& title = "Game Engine",
                    int width = 800,
                    int height = 600)
                : title(title), width(width), height(height) {}
        };

        explicit Window(const Properties& properties = Properties());
        ~Window();

        void OnUpdate();
        inline bool ShouldClose() const { return glfwWindowShouldClose(m_Window); }

    private:
        void Init(const Properties& properties);
        void Shutdown();

        GLFWwindow* m_Window;
        Properties m_Properties;
    };
};