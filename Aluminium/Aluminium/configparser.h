#include <iostream>
#include <vector>
#include <map>
#include <variant> // C++17
#ifndef _CONFIG
#define _CONFIG

namespace config {
	class InvalidValue {};
	typedef std::map<std::string, std::string> Parser;
	typedef std::variant<int, bool, std::string, InvalidValue> ParseValue;
	// Parses the configuration file and returns a parser
	// View configparser.cpp for better documentation
	config::Parser parse(std::string filename);
	// Gets the value, while parse objects can be retrieved through config::parser[key], this handles values better.
	// This is more recommended than config::parser[key].
	// Returns config::InvalidValue if the key is incorrect.
	// Important note: value must be fetched through std::get, ask vi for more information
	ParseValue get(config::Parser ParseObject, std::string key);
}

#endif