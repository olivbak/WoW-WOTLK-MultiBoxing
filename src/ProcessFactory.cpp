#include "ProcessFactory.h"

void ProcessFactory::RunExecutableAsNewProcess(std::string path)
{
    std::ostringstream format;
    format << "\"" << path << "\"";
    
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory (&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    CreateProcess(
        path.c_str(),
        NULL,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi
    );
    CloseHandle( pi.hProcess);
    CloseHandle (pi.hThread);

    Sleep(1000);
}
