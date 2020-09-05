#include <iostream>
#include "Discord.h"
#include "Aluminium.h"

int main() {
	auto [tokens, count] = alm::getTokens("tokens.txt");
	std::cout << "Tokens found: " << count << '\n';
	std::cout << "Threads needed: " << alm::ReturnThreads(count) << '\n';
	for (auto asd : tokens) {
		std::cout << "TOKEN: " << asd << '\n';
	}
	
	return 0;
}