#include <iostream>

#include "window.h"

#include "input/keyboard.h"
#include "input/mouse.h"
#include "input/gamepad.h"

int main()
{
    Scarlet::Window::Properties windowProps("Sandbox Application", 1280, 720);

    Scarlet::Window window(windowProps);

    bool isGamepadConnected = false;


    if(Scarlet::Gamepad::IsGamepadConnected(GLFW_JOYSTICK_1))
    {
        std::cout<<"Gamepad connected. Axis 0: ";
        isGamepadConnected = true;
    }

    while(!window.ShouldClose())
    {
        window.OnUpdate();

        if(isGamepadConnected)
        {
            Scarlet::Gamepad::Update();
            std::cout<<Scarlet::Gamepad::GetAxisValue(GLFW_JOYSTICK_1, Scarlet::GamepadAxis::LEFT_X) << std::endl;
        }

    }
}