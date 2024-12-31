#pragma once

#include "keycode.h"

#include <unordered_map>



namespace Scarlet
{
    class Keyboard
    {
        public:
            static void KeyCallback(int key, int scancode, int action, int mods);
            static bool IsKeyPressed(KeyCode key);

        private:
            static std::unordered_map<KeyCode, bool> s_KeyStates;
    };
}