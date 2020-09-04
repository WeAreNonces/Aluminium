#include <string>
// A list of useful functions
#ifndef _FUNCTIONS
#define _FUNCTIONS

namespace functions {
	bool startswith(std::string str, std::string starts) {
		if (starts.size() > str.size())
			return false;
		for (int i = 0; i < starts.size(); i++) {
			if (str[i] != starts[i])
				return false;
		}
		return true;
	}
}

#endif