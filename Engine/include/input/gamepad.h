#pragma once

#include "keycode.h"

#include <unordered_map>
#include <vector>

namespace Scarlet
{
    class Gamepad
    {
        public:
            struct State
            {
                std::unordered_map<GamepadButton, bool> buttons;
                std::unordered_map<GamepadAxis, float> axes;
            };

            static void Update();
            static bool IsButtonPressed(int gamepadID, GamepadButton button);
            static bool IsButtonReleased(int gamepadID, GamepadButton button);
            static bool IsButtonHeld(int gamepadID, GamepadButton button);
            static bool IsGamepadConnected(int gamepadID);
            static float GetAxisValue(int gamepadID, GamepadAxis axis);

        private:
            static std::vector<State> s_GamepadState;
            static void PollGamepadState(int gamepadID);
            static constexpr int MAX_GAMEPADS = 16;
    };
}