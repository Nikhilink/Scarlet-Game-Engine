#include "input/gamepad.h"
#include "input/input_mapping.h"

#include<GLFW/glfw3.h>

namespace Scarlet
{
    std::vector<Gamepad::State> Gamepad::s_GamepadState(16);

    void Gamepad::Update()
    {
        for(int gamepadId = 0; gamepadId < s_GamepadState.size(); gamepadId++)
        {
            if(glfwJoystickPresent(gamepadId))
            {
                PollGamepadState(gamepadId);
            }
        }
    }

    void Gamepad::PollGamepadState(int gamepadID)
    {
        State& state = s_GamepadState[gamepadID];

        int buttonCount;
        const unsigned char* buttons = glfwGetJoystickButtons(gamepadID, &buttonCount);
        for(int i = 0; i < buttonCount; i++)
        {
            GamepadButton mappedButton = InputMappings::MapGamepadButton(i);
            state.buttons[mappedButton] = (buttons[i] == static_cast<int>(KeyState::PRESS));
        }

        int axisCount;
        const float* axes = glfwGetJoystickAxes(gamepadID, &axisCount);
        for(int i = 0;i < axisCount;i++)
        {
            GamepadAxis mappedAxis = InputMappings::MapGamepadAxis(i);
            state.axes[mappedAxis] = axes[i];
        }
    }

    bool Gamepad::IsButtonPressed(int gamepadID, GamepadButton button)
    {
        if(gamepadID < 0 || gamepadID >= s_GamepadState.size()) return false;
        return s_GamepadState[gamepadID].buttons[button];
    }

    bool Gamepad::IsButtonReleased(int gamepadID, GamepadButton button)
    {
        if(gamepadID < 0 || gamepadID >= s_GamepadState.size()) return false;
        return !s_GamepadState[gamepadID].buttons[button];
    }

    bool Gamepad::IsButtonHeld(int gamepadID, GamepadButton button)
    {
        return IsButtonPressed(gamepadID, button);
    }

    bool Gamepad::IsGamepadConnected(int gamepadID)
    {
        return glfwJoystickPresent(gamepadID) == GLFW_TRUE;
    }

    float Gamepad::GetAxisValue(int gamepadID, GamepadAxis axis)
    {
        if(gamepadID < 0 || gamepadID >= s_GamepadState.size()) return 0.0f;
        return s_GamepadState[gamepadID].axes[axis];
    }
}