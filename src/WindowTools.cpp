#include "WindowTools.h"
#include<iostream>

HWND WindowTools::FindWindowByName(std::string name)
{
    return FindWindowA(nullptr,name.c_str());
}

void WindowTools::SetText(HWND hwnd, std::string text)
{
    SetWindowTextA(hwnd, text.c_str());
}

void WindowTools::SetWindowPos(HWND hwnd, int X, int Y, int width, int heigth)
{
    ::SetWindowPos(hwnd,0,X,Y,width,heigth,SWP_NOZORDER);
}

