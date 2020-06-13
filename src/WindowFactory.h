#pragma once
#include "Window.h"

class WindowFactory
{
    public:
        static Window* CreateNewWindow(std::string path, std::string name);
    private:
};