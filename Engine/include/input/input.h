#pragma once

#include <GLFW/glfw3.h>
#include <utility>

namespace Scarlet
{
    class Input
    {
        public:
            
            // Keyboard
            static bool IsKeyPressed(int key);

            // Mouse
            static bool IsMouseButtonPressed(int button);
            static std::pair<float, float> GetMousePosition();
            static float GetMouseX();
            static float GetMouseY();

            // Gamepad
            static bool IsGamepadConnected(int gamepad);
            static float GetGamepadAxis(int gamepad, int axis);
            static bool IsGamepadButtonPressed(int gamepad, int button);

            static void SetWindow(GLFWwindow* window);

        private:
            static GLFWwindow* s_Window;
    };
}