#include "IWindowGroup.h"
#include "WindowFactory.h"

class DefaultWindowGroup : public IWindowGroup
{
    public:
        DefaultWindowGroup();
        ~DefaultWindowGroup();

        void AddWindow(Window* window);
        void ArrangeWindows();
        void ProcessInput(int ncode, WPARAM wParam, LPARAM lParam);
        void BroadcastKeyInput(UINT vk, WPARAM wParam, LPARAM lParam);
        void ChangeBroadcast(UINT vk);

        UINT* FKEYS; //{0x70,0x71,0x72,0x73};
        UINT* MKEYS; //= {0x41,0x44,0x53,0x57};
        UINT* SKEYS; // = {0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39};

        bool BroadcastMovement;
        bool BroadcastSpells;
};