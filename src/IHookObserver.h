#pragma once
#include "Window.h"

class IHookObserver
{
    public:
        virtual void ProcessInput(int nCode, WPARAM wParam, LPARAM lParam) = 0;
};