#include "KeyboardHookInjector.h"
#include <iostream> 

KeyboardHookInjector* KeyboardHookInjector::p_this = NULL;
HHOOK KeyboardHookInjector::hHook = NULL;


KeyboardHookInjector::KeyboardHookInjector(IHookObserver* observer)
{
    this->observer = observer;
}

LRESULT KeyboardHookInjector::KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    this->observer->ProcessInput(nCode, wParam, lParam);
    return CallNextHookEx(KeyboardHookInjector::p_this->hHook, nCode, wParam, lParam);
}

 

