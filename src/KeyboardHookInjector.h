#pragma once
#include "Window.h"
#include "IHookObserver.h"

class KeyboardHookInjector
{
    public:
        static KeyboardHookInjector* p_this;
        static HHOOK hHook;

        IHookObserver* observer;
        MSG msg;
        KeyboardHookInjector(IHookObserver* observer);

        void InjectHook()
        {
            p_this = this;
            hHook = ::SetWindowsHookEx(WH_KEYBOARD_LL,StaticKeyboardProc, NULL, 0);
        }

        static LRESULT __stdcall StaticKeyboardProc(int ncode, WPARAM wParam, LPARAM lParam)
        {
            return p_this->KeyboardProc(ncode,wParam,lParam);
        }

        LRESULT KeyboardProc(int ncode, WPARAM wParam, LPARAM lparam);
    


};