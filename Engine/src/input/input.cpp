#include "input/input.h"

namespace Scarlet
{
    GLFWwindow* Input::s_Window = nullptr;

    void Input::SetWindow(GLFWwindow* window)
    {
        s_Window = window;
    }

    bool Input::IsKeyPressed(int key)
    {
        if(s_Window) return false;
        int state = glfwGetKey(s_Window, key);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool Input::IsMouseButtonPressed(int button)
    {
        if(s_Window) return false;
        int state = glfwGetMouseButton(s_Window, button);
        return state == GLFW_PRESS;
    }

    std::pair<float, float> Input::GetMousePosition()
    {
        if(s_Window) return {0.0f, 0.0f};
        double x, y;
        glfwGetCursorPos(s_Window, &x, &y);

        return {static_cast<float>(x), static_cast<float>(y)};
    }

    float Input::GetMouseX()
    {
        return GetMousePosition().first;
    }

    float Input::GetMouseY()
    {
        return GetMousePosition().second;
    }

    bool Input::IsGamepadConnected(int gamepad)
    {
        return glfwJoystickPresent(gamepad);
    }

    float Input::GetGamepadAxis(int gamepad, int axis)
    {
        if(!glfwJoystickPresent(gamepad)) return 0.0f;
        int count;
        const float* axes = glfwGetJoystickAxes(gamepad, &count);
        if(axis < count) return axes[axis];
        return 0.0f;
    }

    bool Input::IsGamepadButtonPressed(int gamepad, int button)
    {
        if(!glfwJoystickPresent(gamepad)) return false;
        int count;
        const unsigned char* buttons = glfwGetJoystickButtons(gamepad, &count);
        if(button < count) return buttons[button] == GLFW_PRESS;

        return false;
    }
};