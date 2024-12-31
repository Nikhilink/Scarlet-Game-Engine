#pragma once

#include <unordered_map>
#include "keycode.h"
#include <GLFW/glfw3.h>

namespace Scarlet
{
    class InputMappings
    {
        public:
            static KeyCode MapKey(int glfwKey);
            static MouseButton MapMouseButton(int glfwMouseButton);
            static GamepadButton MapGamepadButton(int glfwGamepadButton);
            static GamepadAxis MapGamepadAxis(int glfwGamepadAxis);

    };
}