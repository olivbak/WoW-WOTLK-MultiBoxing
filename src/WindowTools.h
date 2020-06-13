#pragma once
#include<winuser.h>
#include<windows.h>
#include<iostream>
#include<string>
#include<sstream>
#include<cstdint>
#include<vector>
#include<cstdint>

class WindowTools
{
    public:
        static void RunExecutable(std::string path);
        static HWND FindWindowByName(std::string name);
        static void SetText(HWND hwnd, std::string text);
        static void SetWindowPos(HWND hwnd, int X, int Y, int width, int heigth);
};