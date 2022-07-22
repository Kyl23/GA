#ifndef GENE_TOOL_CONSOLE
#define GENE_TOOL_CONSOLE

#include <iostream>
#include <string>
#include <stdlib.h>

#define NONE "\033[m"
#define RED "\033[0;32;31m"
#define LIGHT_RED "\033[1;31m"
#define GREEN "\033[0;32;32m"
#define LIGHT_GREEN "\033[1;32m"
#define BLUE "\033[0;32;34m"
#define LIGHT_BLUE "\033[1;34m"
#define DARY_GRAY "\033[1;30m"
#define CYAN "\033[0;36m"
#define LIGHT_CYAN "\033[1;36m"
#define PURPLE "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN "\033[0;33m"
#define YELLOW "\033[1;33m"
#define LIGHT_GRAY "\033[0;37m"
#define WHITE "\033[1;37m"

namespace gtool
{
    void err(std::string path, std::string line, std::string msg)
    {
        printf("\n%s:%s" YELLOW " %s\n" NONE, path.c_str(), line.c_str(), msg.c_str());
        exit(-1);
    }
    void warn(std::string path, std::string line, std::string msg)
    {
        printf("\n%s:%s" YELLOW " %s\n" NONE, path.c_str(), line.c_str(), msg.c_str());
    }
    void log(std::string title_msg, std::string descript_msg)
    {
        printf(BLUE "\n%s" GREEN " %s\n" NONE, title_msg.c_str(), descript_msg.c_str());
    }
}

#endif
