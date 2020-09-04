#include <iostream>
#include "Discord.h"
#include "Aluminium.h"
#include <fstream>
#include <vector>
#include <Windows.h>
#include <tuple>
/*
	Exit Codes:
	0 - Success
	1 - Unknown error
	2 - Failed to open tokens
*/

// returns a string with all of the tokens the user gave us

int main() {
	auto [tokens, count] = alm::getTokens("tokens.txt");
	std::cout << "Tokens found: " << count << '\n';
	std::cout << "Threads needed: " << alm::ReturnThreads(count) << '\n';
	for (auto asd : tokens) {
		std::cout << "TOKEN: " << asd << '\n';
	}
	
	return 0;
}