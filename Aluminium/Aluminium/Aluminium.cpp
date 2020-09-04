#include <thread>
#include "Aluminium.h"
#include "Discord.h"
#include <string>
#include <vector>
#include <fstream>
#include <tuple>

// Returns the amount of threads needed
int alm::ReturnThreads(int tokens) {
	return tokens * 85 / 100;
}

// Well.. It's obvious what this does or atleast I hope so
void alm::Raid(uint64_t channelId,std::string message) {
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
std::tuple<std::vector<std::string>, int> alm::getTokens(std::string filepath) {
	std::ifstream tokens{ filepath };

	// if we fail to open the file, throw an error and exit early
	if (!tokens) {
		std::cout << "[ Aluminium ] Error opening tokens.";
		std::exit(2);
	}
	// Read all of the contents in the file, I will regret writting this later
	std::vector<std::string> file = {};
	std::string line;
	int count = 0;
	while (tokens) {
		tokens >> line;
		file.push_back(line);
		count++;
	}
	return std::make_tuple(file, count);
}