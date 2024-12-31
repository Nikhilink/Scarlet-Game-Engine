#include "input/input_mapping.h"

namespace Scarlet
{
    KeyCode InputMappings::MapKey(int glfwKey)
    {
        static const std::unordered_map<int, KeyCode> glfwToKeyCode = {
            {GLFW_KEY_A, KeyCode::A}, {GLFW_KEY_B, KeyCode::B}, {GLFW_KEY_C, KeyCode::C}, {GLFW_KEY_D, KeyCode::D}, {GLFW_KEY_E, KeyCode::E}, {GLFW_KEY_F, KeyCode::F}, {GLFW_KEY_G, KeyCode::G}, {GLFW_KEY_H, KeyCode::H}, {GLFW_KEY_I, KeyCode::I}, {GLFW_KEY_J, KeyCode::J}, {GLFW_KEY_K, KeyCode::K}, {GLFW_KEY_L, KeyCode::L}, {GLFW_KEY_M, KeyCode::M}, 
            {GLFW_KEY_N, KeyCode::N}, {GLFW_KEY_O, KeyCode::O}, {GLFW_KEY_P, KeyCode::P}, {GLFW_KEY_Q, KeyCode::Q}, {GLFW_KEY_R, KeyCode::R}, {GLFW_KEY_S, KeyCode::S}, {GLFW_KEY_T, KeyCode::T}, {GLFW_KEY_U, KeyCode::U}, {GLFW_KEY_V, KeyCode::V}, {GLFW_KEY_W, KeyCode::W}, {GLFW_KEY_X, KeyCode::X}, {GLFW_KEY_Y, KeyCode::Y}, {GLFW_KEY_Z, KeyCode::Z}, 
            {GLFW_KEY_ESCAPE, KeyCode::ESCAPE}, {GLFW_KEY_ENTER, KeyCode::ENTER}, 
            {GLFW_KEY_SPACE, KeyCode::SPACE}, {GLFW_KEY_LEFT_SHIFT, KeyCode::SHIFT_LEFT},
            {GLFW_KEY_RIGHT_SHIFT, KeyCode::SHIFT_RIGHT}
        };

        auto it = glfwToKeyCode.find(glfwKey);

        return it != glfwToKeyCode.end() ? it->second : KeyCode::UNKNOWN;
    }

    MouseButton InputMappings::MapMouseButton(int glfwMouseButton)
    {
        static const std::unordered_map<int, MouseButton> glfwToMouseButton = {
            {GLFW_MOUSE_BUTTON_LEFT, MouseButton::LEFT},
            {GLFW_MOUSE_BUTTON_RIGHT, MouseButton::RIGHT},
            {GLFW_MOUSE_BUTTON_MIDDLE, MouseButton::MIDDLE}
        };

        auto it = glfwToMouseButton.find(glfwMouseButton);
        return it != glfwToMouseButton.end() ? it->second : MouseButton::LEFT;
    }

    GamepadButton InputMappings::MapGamepadButton(int glfwGamepadButton)
    {
        static const std::unordered_map<int, GamepadButton> glfwToGamepadButton = {
            {GLFW_GAMEPAD_BUTTON_A, GamepadButton::A},
            {GLFW_GAMEPAD_BUTTON_B, GamepadButton::B},
            {GLFW_GAMEPAD_BUTTON_X, GamepadButton::X},
            {GLFW_GAMEPAD_BUTTON_Y, GamepadButton::Y},
            {GLFW_GAMEPAD_BUTTON_LEFT_BUMPER, GamepadButton::LEFT_BUMPER},
            {GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER, GamepadButton::RIGHT_BUMPER},
            {GLFW_GAMEPAD_BUTTON_BACK, GamepadButton::BACK},
            {GLFW_GAMEPAD_BUTTON_START, GamepadButton::START},
            {GLFW_GAMEPAD_BUTTON_LEFT_THUMB, GamepadButton::LEFT_THUMB},
            {GLFW_GAMEPAD_BUTTON_RIGHT_THUMB, GamepadButton::RIGHT_THUMB},
        };

        auto it = glfwToGamepadButton.find(glfwGamepadButton);
        return it != glfwToGamepadButton.end() ? it -> second : GamepadButton::A;
    }

    GamepadAxis InputMappings::MapGamepadAxis(int glfwGamepadAxis)
    {
        static const std::unordered_map<int, GamepadAxis> glfwToGamepadAxis = {
            {GLFW_GAMEPAD_AXIS_LEFT_X, GamepadAxis::LEFT_X},
            {GLFW_GAMEPAD_AXIS_LEFT_Y, GamepadAxis::LEFT_Y},
            {GLFW_GAMEPAD_AXIS_RIGHT_X, GamepadAxis::RIGHT_X},
            {GLFW_GAMEPAD_AXIS_RIGHT_Y, GamepadAxis::RIGHT_Y},
            {GLFW_GAMEPAD_AXIS_LEFT_TRIGGER, GamepadAxis::LEFT_TRIGGER},
            {GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER, GamepadAxis::RIGHT_TRIGGER}
        };

        auto it = glfwToGamepadAxis.find(glfwGamepadAxis);
        return it != glfwToGamepadAxis.end() ? it -> second : GamepadAxis::LEFT_X;
    }

} // namespace Scarlet