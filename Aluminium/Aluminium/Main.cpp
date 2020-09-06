#include <Windows.h>
#include <string>
#include <iostream>
#include "Console.h"


int main() {
	SetConsoleTitleA("Aluminium 1.0");
	do {
		console::print("Do `help` for a list of commands\n");
		console::print("Input a command: ");
		std::string cmd;
		std::getline(std::cin, cmd);
		console::ParseCmds(cmd);
	} while (true);
	return 0;
}