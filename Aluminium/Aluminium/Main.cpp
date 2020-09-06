#include <Windows.h>
#include <string>
#include <iostream>
#include "Console.h"
#include "Aluminium.h"
#include "Discord.h"
#include "configparser.h"


int main() {
	std::vector<std::string> tokens = alm::getTokens("tokens.txt");
	config::Parser configuration = config::parse("config.txt");
	bool isFunctional = true;
	if (std::get<bool>(config::get(configuration, "verify_tokens"))) {
		console::print("Verifying tokens... (disable this in config)\n");
		for (int i = 0; i < tokens.size(); i++) {
			discord::Account acc = {tokens[i]};
			if (!acc.verifyToken()) {
				console::print("[ ! ] Found invalid token: " + acc.getToken() + '\n');
				tokens.erase(tokens.begin()+i);
				isFunctional = false;
			}
		}
		if (isFunctional)
			console::print("All tokens functional\n");
	}

	SetConsoleTitleA("Aluminium 1.0");
	do {
		console::print("Do `help` for a list of commands\n");
		console::print("Input a command: ");
		std::string cmd;
		std::getline(std::cin, cmd);
		console::ParseCmds(cmd, tokens);
	} while (true);
	return 0;
}