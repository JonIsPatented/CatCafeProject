#ifndef JC_STRING_MANIP_H
#define JC_STRING_MANIP_H

#include <string>
#include <vector>

namespace cc
{
	std::vector<std::string> splitString(const std::string&, char);
	std::string toLowerCase(const std::string&);
}

#endif
