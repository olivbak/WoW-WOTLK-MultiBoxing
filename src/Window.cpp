#include "Window.h"

Window::Window(HWND handle, std::string name)
{
    this->handle = handle;
    this->name = name;
}

Window::~Window()
{
    // bla bla
}


void Window::SetWindowPos(int X, int Y, int width, int height)
{
    WindowTools::SetWindowPos(this->handle,X,Y,width,height);
}

void Window::ChangeWindowName(std::string newName)
{
    WindowTools::SetText(this->handle, newName);
    this->name = newName;
}

void Window::UpdateHandle()
{
    this->handle = WindowTools::FindWindowByName(this->name);
}