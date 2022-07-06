#ifndef GENE_TOOL_CONSOLE
#define GENE_TOOL_CONSOLE

#include <iostream>
#include <string>
#include <stdlib.h>

namespace gtool
{
    void err(std::string msg)
    {
        printf("%s\n", msg.c_str());
        exit(-1);
    }
    void warn(std::string msg)
    {
        printf("%s\n", msg.c_str());
    }
}

#endif
