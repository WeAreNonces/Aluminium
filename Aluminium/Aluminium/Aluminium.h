#ifndef ALM
#define ALM
#include <iostream>
#include <vector>
#include <tuple>

namespace alm {
	int ReturnThreads(int tokens);
	void Raid(uint64_t channelId, std::string message);
	std::vector<std::string> split(std::string str, char separator);
	std::tuple<std::vector<std::string>, int> getTokens(std::string filepath);
}

#endif