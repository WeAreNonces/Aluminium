#include <iostream>
#include "Discord.h"
#include "Aluminium.h"

int main() {
	discord::Account acc = {"NzUxNjExNDQ0NzM4NTIzMTc4.X1LmuA.MJH92hDWtOEHfqgycni5hq8PvnU"};
	acc.leaveserver(751591956597178399);
	//auto [tokens, count] = alm::getTokens("tokens.txt");

	//std::cout << "Tokens found: " << count << '\n';
	//std::cout << "Threads needed: " << alm::getThreadCount(count) << '\n';

	//for (auto token : tokens) {

	//	std::cout << "TOKEN: " << token << '\n';
	//	discord::Account thing{ token };
	//	std::cout << thing.joinserver("6hNAYP") << '\n';
	//	thing.send(751591956597178402,"poopy poop poop xDDD");
	
	//}
	
	return 0;
}