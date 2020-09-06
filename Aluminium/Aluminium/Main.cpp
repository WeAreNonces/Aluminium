#include <iostream>
#include "Discord.h"
#include "Aluminium.h"
#include <thread>
#include <string>


int main() {
	do {
		alm::print("Please input a command: ");
		std::string cmd;
		std::getline(std::cin, cmd);
		alm::ParseCmds(cmd);
	} while (true);
	return 0;
}