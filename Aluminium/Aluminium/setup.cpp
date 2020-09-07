#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include "setup.h"
#include "Aluminium.h"

std::string default_config = R"(
# Aluminium's Configuration file.

# If set to a value, the nicknames of the tokens will be changed when raiding a server.
# Leave at `none` to keep the names as they are.
nickname = none

# If set to true, the tokens will ping @everyone in the beginning of the messages
# This will only work if the server allows it.
ping_everyone = false

# Verifies if the tokens are functional and valid when the program starts
# If an invalid token is found, it's removed from the list and tells you which token is invalid.
# We recommend keeping this at true, but if you have a lot of tokens and you're sure they're functional, you're welcome to keep this at false.
verify_tokens = false

# This is the amount of time it waits between message (in milliseconds)
# By default this is at `250`, but if you have a low amount of tokens we recommend making this higher.
# If you have a lot of tokens (above 100) then we recommend making this lower.
# If you notice the bot stops sending messages after a while then make this higher.
time_between_message = 250
)";

std::string default_tokens = R"(
# Tokens file
# Place all your discord tokens below this line
)";

bool setup::configsExist() {
	std::filesystem::path current_path = std::filesystem::current_path();
	std::string file = "config.txt";
	return std::filesystem::is_regular_file(current_path / file);
}

bool setup::tokensExist() {
	std::filesystem::path current_path = std::filesystem::current_path();
	std::string file = "tokens.txt";
	return std::filesystem::is_regular_file(current_path / file);
}

void setup::createDefaultConfig() {
	std::ofstream config{ "config.txt" };
	std::vector<std::string> splitconfig = alm::split(default_config, '\n');
	for (std::string line : splitconfig) {
		config << line << '\n';
	}
}

void setup::createDefaultTokens() {
	std::ofstream tokens{ "tokens.txt" };
	std::vector<std::string> splitTokens = alm::split(default_tokens, '\n');
	for (std::string line : splitTokens) {
		tokens << line << '\n';
	}
}