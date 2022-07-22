#ifndef GENE_TOOL_READER_CSV_READER
#define GENE_TOOL_READER_CSV_READER

#include <string>
#include <vector>
#include <fstream>

#include "../console.hpp"

namespace gtool
{
    class CSVReader
    {
    private:
        std::ifstream file;

        char delim;

        std::string filePath;

        void throwFileOpenErr(const std::string &line)
        {
            gtool::err("./lib/tool/reader/csv_reader.hpp", line, "readFileError");
        }

    public:
        void open(std::string path, char pattern = ',')
        {
            filePath = path;
            delim = pattern;
        }

        std::vector<std::vector<std::string>> readTable()
        {

            std::vector<std::vector<std::string>> out;

            file.open(filePath);
            if (!file.is_open())
                throwFileOpenErr("33");
            while (!file.eof())
            {

                std::vector<std::string> rowLine;

                std::string line;
                std::getline(file, line);

                std::string s = "";
                for (int i = 0; i < line.length(); i++)
                {
                    if (line[i] != delim)
                    {
                        s += line[i];
                    }
                    else
                    {
                        rowLine.push_back(std::string(s));
                        s = "";
                    }
                }
                rowLine.push_back(std::string(s));
                s = "";

                out.push_back(rowLine);
            }
            file.close();
            out.erase(out.end());
            return out;
        }

        void print()
        {
            file.open(filePath);
            if (!file.is_open())
                throwFileOpenErr("72");
            while (!file.eof())
            {
                std::string line;
                std::getline(file, line);

                for (int i = 0; i < line.length(); i++)
                {
                    if (line[i] == delim)
                    {
                        printf(" ");
                    }
                    else
                    {
                        printf("%c", line[i]);
                    }
                }
                puts("");
            }
            file.close();
        }
    };
}

#endif
