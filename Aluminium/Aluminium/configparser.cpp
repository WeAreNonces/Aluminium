#include "configparser.h"
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include "Aluminium.h"


std::string strip(std::string s) {
    while (s.front() == ' ' || s.back() == ' ') {
        if (s.front() == ' ')
            s.erase(0, 1);
        if (s.back() == ' ')
            s.pop_back();
    }
    return s;
}

bool isdigit(std::string s) {
    for (char c : s) {
        if (std::isdigit(c) == 0)
            return false;
    }
    return true;
}

// Parses the file
// Possible errors:
// "OP_CONFIG_OPEN_FAILURE" -> Configuration file not found or failed to open
config::Parser config::parse(std::string filename) {
    config::Parser f = {};
	std::ifstream config{"config.txt"};
	if (!config)
		throw "OP_CONFIG_OPEN_FAILURE";
	while (config) {
        std::string line;
        std::getline(config, line);
		if (line[0] == '#')
			continue;
        std::vector<std::string> s = alm::split(line, '=');
        if (s.size() == 2)
            f[strip(s[0])] = strip(s[1]);
        else
            continue;
	}
    return f;
}

config::ParseValue config::get(config::Parser ParseObject, std::string key) {
    try {
        ParseObject.at(key);
    }
    catch(std::out_of_range) {
        return config::InvalidValue();
    }
    std::string value = ParseObject[key];
    // Before you complain cube, switch() only allows int, enum, char, etc.
    if (value == "true")
        return true;
    else if (value == "false")
        return false;
    else if (isdigit(value))
        return std::stoi(value);
    return value;
}