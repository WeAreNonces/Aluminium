#include <iostream>
#include "Discord.h"
#include "Aluminium.h"
#include <thread>


int main() {
	std::vector<std::string> tokens = alm::getTokens("tokens.txt");
	std::vector<std::thread> threads = {};
	alm::joinServer("N3p4Ru");
	for(int i = 0; i < alm::getThreadCount(tokens.size()); i++) {
		std::thread t(alm::ServerRaid, 751591956597178402, "Test1234");
		t.join();
		threads.push_back(t);
	}
	return 0;
}