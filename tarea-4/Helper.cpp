#include "Helper.h"

string Helper::ReplaceAll(string str)
{
    size_t start_pos = 0;
    string from = "  ";
    string to = " ";
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }

    return str;
}

