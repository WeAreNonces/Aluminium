#include <iostream>
#include "Discord.h"
#include "Aluminium.h"

// tokens: NzUxNjExNDQ0NzM4NTIzMTc4.X1LmuA.MJH92hDWtOEHfqgycni5hq8PvnU

int main() {
	auto tokens = alm::getTokens("tokens.txt");

	std::cout << "Tokens found: " << tokens.size() << '\n';
	std::cout << "Threads needed: " << alm::getThreadCount(tokens.size()) << '\n';

	for (auto token : tokens) {

		std::cout << "TOKEN: " << token << '\n';
		//discord::Account thing{ token };
		//std::cout << thing.joinserver("Kh6Ay9") << '\n';
		//thing.send(751591956597178402,"poopy poop poop xDDD");
	
	}
	
	return 0;
}