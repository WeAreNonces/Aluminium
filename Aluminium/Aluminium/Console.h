#include <string>
#include <vector>
#ifndef CONSOLE
#define CONSOLE

namespace console {
	template<typename T>
	void print(T msg);
	void warn(std::string msg);
	void success(std::string msg);
	void error(std::string msg);
	void ParseCmds(std::string cmd, std::vector<std::string> tokens);
}

#endif