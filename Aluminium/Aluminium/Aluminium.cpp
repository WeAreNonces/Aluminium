#include "Aluminium.h"
#include "Discord.h"
#include "Console.h"
#include <string> // for std::getline
#include <vector>
#include <fstream> // for std::ifstream
#include <Windows.h>
#include <future>
#include <cpr/cpr.h>

// Returns the amount of threads needed
int alm::getThreadCount(int tokens) {
	int c = tokens * 65 / 100;
    return c == 0 ? 1 : c;
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

// For async
// TODO: move to lambda
static void joinserver(discord::Account account, std::string invite) {
    account.asyncJoinServer(invite);
}

// For async
// TODO: move to lambda
static void sendmessage(discord::Account account, std::uint64_t channelId, std::string content) {
    account.asyncSend(channelId, content);
}

// Makes all tokens join servers
// TODO: std::filesystem to check if tokens.txt exists
void alm::joinServer(std::string invite) {
    std::vector<std::string> tokens = alm::getTokens("tokens.txt");
    std::vector<std::future<void>> futures = {};
    for (auto x : tokens) {
        discord::Account acc = {x};
        futures.push_back(std::async(std::launch::async, joinserver, acc, invite));
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

// Well.. It's obvious what this does or atleast I hope so
void alm::ServerRaid(uint64_t channelId, std::string message) {
    std::vector<std::string> tokens = alm::getTokens("tokens.txt");
    std::vector<std::future<void>> futures = {};
    while (true) {
        for (auto token : tokens) {
            discord::Account account{ token };
            futures.push_back(std::async(std::launch::async, sendmessage, account, channelId, message));
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
        }
    }
}