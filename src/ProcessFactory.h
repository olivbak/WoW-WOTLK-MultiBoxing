#pragma once
#include<string>
#include "WindowTools.h"

class ProcessFactory
{
    public:
        static void RunExecutableAsNewProcess(std::string path);
};