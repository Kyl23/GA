#ifndef GENE_TOOL_READER_CONFIG_READER
#define GENE_TOOL_READER_CONFIG_READER

#include <iostream>
#include <fstream>
#include <map>
#include "../console.hpp"

namespace gtool
{
    class ConfigReader
    {
    private:
        std::ifstream file;
        char delim;
        char annotation;
        std::string filePath;

    public:
        void open(std::string path, char pattern = ':', char ignore = '#')
        {
            filePath = path;
            delim = pattern;
            annotation = ignore;
        }

        std::map<std::string, std::string> readObj()
        {
            std::map<std::string, std::string> out;
            file.open(filePath);
            if (!file.is_open())
                gtool::err("ConfigReader : open file error , in readObj()");

            std::string line;
            while (!file.eof())
            {
                std::string key, value;
                bool isValue = false;
                std::getline(file, line);
                if (line.empty() || line[0] == annotation)
                    continue;
                for (int i = 0; i < line.length(); i++)
                {
                    if (line[i] == delim)
                    {
                        isValue = true;
                        continue;
                    }
                    if (isValue)
                    {
                        value += line[i];
                    }
                    if (!isValue)
                    {
                        key += line[i];
                    }
                }
                out[key] = value;
            }
            return out;
        }

        void print()
        {
            file.open(filePath);
            if (!file.is_open())
                gtool::err("ConfigReader : open file error , in print()");

            std::string line;
            while (!file.eof())
            {
                std::getline(file, line);
                std::cout << line << std::endl;
            }

            file.close();
        }
    };
}

#endif
