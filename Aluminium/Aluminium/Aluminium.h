#include <iostream>
#include <vector>
#include <tuple>

#ifndef ALM
#define ALM

namespace alm {
	
	int getThreadCount(int tokens);
	void Raid(uint64_t channelId, std::string message);
	std::vector<std::string> split(std::string str, char separator);
	
	std::tuple<std::vector<std::string>, int> getTokens(std::string filepath);
}

#endif