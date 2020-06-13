#include "DefaultWindowGroup.h"
#include<algorithm>

bool ArrayContains(UINT* arr, int ar_len, UINT vk)
{
    for(int i = 0; i<ar_len; i++)
    {
        if(arr[i]==vk) return true;
    }
    return false;
}

void PressKey(HWND handle, UINT vk)
{
    PostMessage(handle,WM_KEYDOWN,vk,0);
    Sleep(10);
    PostMessage(handle,WM_KEYUP,vk,0);
}

DefaultWindowGroup::DefaultWindowGroup() : IWindowGroup()
{
    this->maxWindows = 5;
    this->FKEYS = new UINT[4]{0x70,0x71,0x72,0x73};
    this->MKEYS = new UINT[4]{0x41,0x44,0x53,0x57};
    this->SKEYS = new UINT[10]{0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39};
    this->BroadcastSpells = true;
    this->BroadcastMovement = true;
}

DefaultWindowGroup::~DefaultWindowGroup()
{

}

void DefaultWindowGroup::ProcessInput(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode < 0) return;
    if( (*this->windows)[0]->handle != GetForegroundWindow()) return;
    if( wParam == WM_KEYDOWN) return;

    //KBDLLHOOKSTRUCT kbd;
    UINT vk = (*((KBDLLHOOKSTRUCT*)lParam)).vkCode;
    std::cout << vk << std::endl;

    if ( ArrayContains(this->FKEYS,4,vk))
    {
        this->ChangeBroadcast(vk); 
        return;
    }
    else if( ArrayContains(this->MKEYS,4,vk) && this->BroadcastMovement)

    {
        this->BroadcastKeyInput( vk, wParam, lParam);
        return;
    }
    else if( ArrayContains(this->SKEYS,10,vk) && this->BroadcastSpells)
    {
        this->BroadcastKeyInput( vk, wParam, lParam);
        return;
    }
}

void DefaultWindowGroup::BroadcastKeyInput(UINT vk, WPARAM wParam, LPARAM lParam)
{
    for( int i = 1; i<this->maxWindows ; i++)
    {
        //PostMessage((*this->windows)[i]->handle, WM_KEYUP, vk ,0);
        PressKey((*this->windows)[i]->handle,vk);
    }
}

void DefaultWindowGroup::AddWindow(Window* window)
{
    if(this->windows->size() <= this->maxWindows)
    {
        this->windows->push_back(window);
    }
}

void DefaultWindowGroup::ChangeBroadcast(UINT vk)
{
    switch(vk)
    {
        case 0x70:
            this->BroadcastMovement = !BroadcastMovement;
            break;
        case 0x71:
            this->BroadcastSpells = !BroadcastSpells;
            break;
        default:
            break;
    }
}

void DefaultWindowGroup::ArrangeWindows()
{
    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop,&desktop);
    int horizontal = desktop.right;
    int vertical = desktop.bottom;
    int v_size = vertical/4;

    for(int i = 1; i<(std::min(this->maxWindows, 5)) ; i++)
    {
       (*this->windows)[i]->SetWindowPos(0,v_size*(i-1),horizontal*0.2,v_size);
    }

    (*this->windows)[0]->SetWindowPos(horizontal*0.2,0,horizontal*0.8,vertical);
}