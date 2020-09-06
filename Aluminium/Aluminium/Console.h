#include <string>
#ifndef CONSOLE
#define CONSOLE

namespace console {
	template<typename T>
	void print(T msg);
	void ParseCmds(std::string cmd);
}

#endif