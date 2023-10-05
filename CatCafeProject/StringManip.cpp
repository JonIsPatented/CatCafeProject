#include "StringManip.h"

#include <sstream>

std::vector<std::string> cc::splitString(const std::string& _s, const char delimiter)
{
	std::vector<std::string> result;
	std::stringstream ss(_s);
	std::string item;
	
	while (std::getline(ss, item, delimiter))
		result.push_back(item);

	return result;
}
