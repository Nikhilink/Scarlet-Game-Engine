#include "input/keyboard.h"
#include "input/input_mapping.h"

namespace Scarlet
{
    std::unordered_map<KeyCode, bool> Keyboard::s_KeyStates;

    void Keyboard::KeyCallback(int key, int scancode, int action, int mods)
    {
        KeyCode mappedKey = InputMappings::MapKey(key);
        if(static_cast<KeyState>(action) == KeyState::PRESS || static_cast<KeyState>(action) == KeyState::REPEAT)
        {
            s_KeyStates[mappedKey] = true;
        }
        else if(static_cast<KeyState>(action) == KeyState::RELEASE)
        {
            s_KeyStates[mappedKey] = false;
        }
    }
    
    bool Keyboard::IsKeyPressed(KeyCode key)
    {
        return s_KeyStates[key];
    }
}