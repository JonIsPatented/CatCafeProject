#include "StringManip.h"

#include <sstream>
#include <algorithm>

std::vector<std::string> cc::splitString(const std::string& _s, const char delimiter)
{
    std::vector<std::string> result;
    std::stringstream ss(_s);
    std::string item;
    
    while (std::getline(ss, item, delimiter))
        result.push_back(item);

    return result;
}

std::string cc::toLowerCase(const std::string& _s)
{
    std::string _ls{ _s };
    std::transform(_ls.begin(), _ls.end(), _ls.begin(),
        [](unsigned char c) { return tolower(c); });
    return _ls;
}
