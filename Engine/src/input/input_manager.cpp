#include "input/input_manager.h"

#include "input/keyboard.h"
#include "input/mouse.h"
#include "input/gamepad.h"

namespace Scarlet
{


    void InputManager::Initialize(GLFWwindow* window)
    {
        glfwSetKeyCallback(window, [](GLFWwindow*, int key, int scancode, int action, int mods)
        {
            Keyboard::KeyCallback(key, scancode, action, mods);
        });

        glfwSetMouseButtonCallback(window, [](GLFWwindow*, int button, int action, int mods)
        {
            Mouse::MouseButtonCallback(button, action, mods);
        });

        glfwSetCursorPosCallback(window, [](GLFWwindow*, double xPos, double yPos)
        {
            Mouse::CursorPositionCallback(xPos, yPos);
        });

        glfwSetScrollCallback(window, [](GLFWwindow*, double xOffset, double yOffset)
        {
            Mouse::ScrollCallback(xOffset, yOffset);
        });

        
    }
}