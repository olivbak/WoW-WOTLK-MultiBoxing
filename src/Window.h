#pragma once
#include "WindowTools.h"

class Window
{
    public:
        Window(HWND handle, std::string name);
        ~Window();
        
        HWND handle;
        std::string name;

        void SetWindowPos(int X, int Y, int width, int height);
        void ChangeWindowName(std::string newName);
        void UpdateHandle(); // I don't know behavior of ChangeWindowName yet. Might not be neccesarry

    private:

};