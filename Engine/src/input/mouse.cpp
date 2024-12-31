#include "input/mouse.h"

#include <unordered_map>

namespace Scarlet
{
    std::unordered_map<MouseButton, bool> Mouse::s_ButtonStates;
    float Mouse::s_MouseX = 0.0f;
    float Mouse::s_MouseY = 0.0f;
    float Mouse::s_ScrollOffset = 0.0f;

    void Mouse::MouseButtonCallback(int button, int action, int mods)
    {
        s_ButtonStates[static_cast<MouseButton>(button)] = (static_cast<KeyState>(action) == KeyState::PRESS);
    }

    void Mouse::CursorPositionCallback(double xPos, double yPos)
    {
        s_MouseX = static_cast<float>(xPos);
        s_MouseY = static_cast<float>(yPos);
    }

    void Mouse::ScrollCallback(double xOffset, double yOffset)
    {
        s_ScrollOffset = static_cast<float>(yOffset);
    }

    bool Mouse::IsButtonPressed(MouseButton button)
    {
        return s_ButtonStates[button];
    }

    std::pair<float, float> Mouse::GetPosition()
    {
        return {s_MouseX, s_MouseY};
    }

    float Mouse::GetScrollOffset()
    {
        return s_ScrollOffset;
    }
}