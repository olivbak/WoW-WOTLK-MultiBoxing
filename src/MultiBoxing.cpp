#include "MultiBoxing.h"
#include "DefaultWindowGroup.h"

using namespace std;

MultiBoxing::MultiBoxing()
{
    this->wg = new DefaultWindowGroup();
    this->khi = new KeyboardHookInjector(this->wg);
    std::string path = "C:/Users/olive/Downloads/Wrath of the Lich King 3.3.5a (wod models)/Wow.exe";

    for(int i = 0; i<this->wg->maxWindows; i++)
    {
        std::stringstream format;
        format << "WOW" << i;
        Window* w = WindowFactory::CreateNewWindow(path,"World of Warcraft");
        w->ChangeWindowName(format.str());
        this->wg->AddWindow(w);
    }
    this->wg->ArrangeWindows();
    this->khi->InjectHook();
    while(!GetMessage(&(khi->msg),NULL,0,0))
    {
        TranslateMessage(&khi->msg);
        DispatchMessage(&khi->msg);
    }

    delete khi;
}

MultiBoxing::~MultiBoxing()
{

}