#include <Windows.h>
#include <string>
#include <iostream>
#include "Console.h"
#include "Aluminium.h"
#include "Discord.h"
#include "configparser.h"
#include <fstream>

int main() {
	std::string logo = R"(`                                                                                                                                                              
                                                                                                                                                              
               AAA               lllllll                                             iiii                     iiii                                            
              A:::A              l:::::l                                            i::::i                   i::::i                                           
             A:::::A             l:::::l                                             iiii                     iiii                                            
            A:::::::A            l:::::l                                                                                                                      
           A:::::::::A            l::::l uuuuuu    uuuuuu     mmmmmmm    mmmmmmm   iiiiiiinnnn  nnnnnnnn    iiiiiii uuuuuu    uuuuuu     mmmmmmm    mmmmmmm   
          A:::::A:::::A           l::::l u::::u    u::::u   mm:::::::m  m:::::::mm i:::::in:::nn::::::::nn  i:::::i u::::u    u::::u   mm:::::::m  m:::::::mm 
         A:::::A A:::::A          l::::l u::::u    u::::u  m::::::::::mm::::::::::m i::::in::::::::::::::nn  i::::i u::::u    u::::u  m::::::::::mm::::::::::m
        A:::::A   A:::::A         l::::l u::::u    u::::u  m::::::::::::::::::::::m i::::inn:::::::::::::::n i::::i u::::u    u::::u  m::::::::::::::::::::::m
       A:::::A     A:::::A        l::::l u::::u    u::::u  m:::::mmm::::::mmm:::::m i::::i  n:::::nnnn:::::n i::::i u::::u    u::::u  m:::::mmm::::::mmm:::::m
      A:::::AAAAAAAAA:::::A       l::::l u::::u    u::::u  m::::m   m::::m   m::::m i::::i  n::::n    n::::n i::::i u::::u    u::::u  m::::m   m::::m   m::::m
     A:::::::::::::::::::::A      l::::l u::::u    u::::u  m::::m   m::::m   m::::m i::::i  n::::n    n::::n i::::i u::::u    u::::u  m::::m   m::::m   m::::m
    A:::::AAAAAAAAAAAAA:::::A     l::::l u:::::uuuu:::::u  m::::m   m::::m   m::::m i::::i  n::::n    n::::n i::::i u:::::uuuu:::::u  m::::m   m::::m   m::::m
   A:::::A             A:::::A   l::::::lu:::::::::::::::uum::::m   m::::m   m::::mi::::::i n::::n    n::::ni::::::iu:::::::::::::::uum::::m   m::::m   m::::m
  A:::::A               A:::::A  l::::::l u:::::::::::::::um::::m   m::::m   m::::mi::::::i n::::n    n::::ni::::::i u:::::::::::::::um::::m   m::::m   m::::m
 A:::::A                 A:::::A l::::::l  uu::::::::uu:::um::::m   m::::m   m::::mi::::::i n::::n    n::::ni::::::i  uu::::::::uu:::um::::m   m::::m   m::::m
AAAAAAA                   AAAAAAAllllllll    uuuuuuuu  uuuummmmmm   mmmmmm   mmmmmmiiiiiiii nnnnnn    nnnnnniiiiiiii    uuuuuuuu  uuuummmmmm   mmmmmm   mmmmmm
                                                                                                                                                              )";
	std::cout << logo << '\n';
	std::vector<std::string> tokens = alm::getTokens("tokens.txt");
	config::Parser configuration = config::parse("config.txt");
	bool isFunctional = true;

	if (std::get<bool>(config::get(configuration, "verify_tokens"))) {
		console::print("Verifying tokens... (disable this in config)\n");

		for (int i = 0; i < tokens.size(); i++) {
			discord::Account acc = { tokens[i] };
			if (!acc.verifyToken()) {
				console::print("Found invalid token: " + acc.getToken() + '\n', true);
				tokens.erase(tokens.begin() + i);
				isFunctional = false;
			}
		}
		if (isFunctional)
			console::print("All tokens functional\n");
	}

	SetConsoleTitleA("Aluminium");
	console::print("Do `help` for a list of commands\n");

	do {
		console::print("Input a command: ");
		std::string cmd;
		std::getline(std::cin, cmd);
		console::ParseCmds(cmd, tokens);

	} while (true);

	return 0;
}