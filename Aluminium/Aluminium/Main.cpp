#include <iostream>
#include "Discord.h"
#include "Aluminium.h"

int main() {
	auto [tokens, count] = alm::getTokens("tokens.txt");

	std::cout << "Tokens found: " << count << '\n';
	std::cout << "Threads needed: " << alm::getThreadCount(count) << '\n';

	for (auto token : tokens) {

		std::cout << "TOKEN: " << token << '\n';
		discord::Account thing{ token };
		std::cout << thing.joinserver("6hNAYP") << '\n';
		thing.send(751591956597178402,"poopy poop poop xDDD");
	
	}
	
	return 0;
}