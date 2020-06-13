#pragma once
#include "Window.h"
#include "IHookObserver.h"

class IWindowGroup : public IHookObserver
{
    public:
        std::vector<Window*>* windows = new std::vector<Window*>();
        int maxWindows;        

        virtual void AddWindow(Window* window) = 0;
        virtual void ArrangeWindows() = 0;
        virtual void BroadcastKeyInput(UINT vk,WPARAM wParam, LPARAM lParam) = 0;
        
};