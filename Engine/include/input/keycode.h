#pragma once

namespace Scarlet
{
    enum class KeyCode
    {
        UNKNOWN = 0,
        A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T,U, V, W, X, Y, Z,
        NUM_0, NUM_1, NUM_2, NUM_3, NUM_4, NUM_5, NUM_6, NUM_7, NUM_8, NUM_9,
        ESCAPE, ENTER, TAB, SPACE, BACKSPACE, LEFT, RIGHT, UP, DOWN,
        F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
        SHIFT_LEFT, SHIFT_RIGHT, CONTROL_LEFT, CONTROL_RIGHT, ALT_LEFT, ALT_RIGHT,  
    };

    enum class MouseButton
    {
        LEFT = 0,
        RIGHT,
        MIDDLE,
        BUTTON_4,
        BUTTON_5
    };

    enum class GamepadButton
    {
        A = 0,
        B,
        X,
        Y,
        LEFT_BUMPER,
        RIGHT_BUMPER,
        BACK,
        START,
        LEFT_THUMB,
        RIGHT_THUMB,
        LEFT_TRIGGER,
        RIGHT_TRIGGER
    };

    enum class GamepadAxis
    {
        LEFT_X = 0,
        LEFT_Y,
        RIGHT_X,
        RIGHT_Y,
        LEFT_TRIGGER,
        RIGHT_TRIGGER
    };

    enum class KeyState
    {
        RELEASE = 0,
        PRESS,
        REPEAT,
    };
}