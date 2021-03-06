#include <iostream>
#include <vector>
#include <tuple>
#ifndef ALM
#define ALM
namespace alm {
	
	int getThreadCount(int tokens);
	void ServerRaid(uint64_t channelId, std::string message);
	std::vector<std::string> split(std::string str, char separator);
	std::vector<std::string> getTokens(std::string filepath);
	void joinServer(std::string invite);
	void spamFriendRequests(std::string user);
}

#endif