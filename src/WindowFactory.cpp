#include "WindowFactory.h"
#include "ProcessFactory.h"

Window* WindowFactory::CreateNewWindow(std::string path, std::string name)
{
    ProcessFactory::RunExecutableAsNewProcess(path);
    return new Window(WindowTools::FindWindowByName(name), name);
}