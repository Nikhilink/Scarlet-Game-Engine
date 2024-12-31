#pragma once

#include <utility>
#include <unordered_map>

#include "keycode.h"

namespace Scarlet
{
    class Mouse
    {
        public:
            static void MouseButtonCallback(int button, int action, int mods);
            static void CursorPositionCallback(double xPos, double yPos);
            static void ScrollCallback(double xOffset, double yOffset);

            static bool IsButtonPressed(MouseButton button);
            static std::pair<float, float> GetPosition();
            static float GetScrollOffset();

        private:
            static std::unordered_map<MouseButton, bool> s_ButtonStates;
            static float s_MouseX, s_MouseY;
            static float s_ScrollOffset;
    };
}