#include "Aluminium.h"
#include "Discord.h"
#include <thread>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>

// Returns the amount of threads needed
int alm::getThreadCount(int tokens) {
	int c = tokens * 75 / 100;
    return c == 0 ? 1 : c;
}

// Well.. It's obvious what this does or atleast I hope so
void alm::ServerRaid(uint64_t channelId,std::string message) {
	discord::Account asd{"test"};
	asd.send(channelId, message);
}

std::vector<std::string> alm::split(std::string str, char separator) {
    std::vector<std::string> sp = {};
    std::string buffer = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == separator) {
            sp.push_back(buffer);
            buffer = "";
            continue;
        }
        buffer += str[i];
    }
    if (buffer != "")
        sp.push_back(buffer);
    return sp;
}


// returns a string with all of the tokens the user gave us
std::vector<std::string> alm::getTokens(std::string filepath) {
    std::vector<std::string> tokens = {};
    std::ifstream config{ filepath };
    if (!config)
        throw "OPEN_FAILURE";
    while (config) {
        std::string line;
        std::getline(config, line);
        if (line[0] == '#' || line.size() == 0)
            continue;
        tokens.push_back(line);
    }
    return tokens;
}