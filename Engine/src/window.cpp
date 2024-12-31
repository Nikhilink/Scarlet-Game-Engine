#include "window.h"

#include <iostream>

namespace Scarlet
{
        Window::Window(const Properties& properties) {
        Init(properties);
    }

    Window::~Window() {
        Shutdown();
    }

    void Window::Init(const Properties& properties) {
        m_Properties = properties;

        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW!" << std::endl;
            exit(EXIT_FAILURE);
        }

        // Set OpenGL version (4.6 core for now)
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_Window = glfwCreateWindow(m_Properties.width, m_Properties.height,
                                    m_Properties.title.c_str(), nullptr, nullptr);

        if (!m_Window) {
            std::cerr << "Failed to create GLFW window!" << std::endl;
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(m_Window);
        glfwSwapInterval(1); // Enable V-Sync

        InputManager::Initialize(m_Window);
    }

    void Window::Shutdown() {
        if (m_Window) {
            glfwDestroyWindow(m_Window);
        }
        glfwTerminate();
    }

    void Window::OnUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }
};