#include <iostream>
#include "Discord.h"
#include "Aluminium.h"
#include <thread>
#include <string>


int main() {
	/*
		Visual Studio's Intellisense keeps having a fucking seizure
		So working on this will probably take me 3 hours. YAY!
	*/
	std::vector<std::string> tokens = alm::getTokens("tokens.txt"); // This will read all of our tokens and store them in an std::vector
	alm::joinServer("N3p4Ru");
	for(int i = 0; i < alm::getThreadCount(tokens.size()); i++) {
		std::thread t(alm::ServerRaid, 751591956597178402, "Test1234");
		t.join();
	}
	return 0;
}