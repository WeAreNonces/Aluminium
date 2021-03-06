#include <iostream>
#include <vector>
#include "Console.h"
#include "Windows.h"
#include "Aluminium.h"

/*
    COLOR CODES:
    BLACK 0, BLUE 1, GREEN 2, CYAN 3, RED 4, MAGENTA 5,
    BROWN 6, LIGHT GREY 7, DARK GREY 8, LIGHT BLUE 9,
    LIGHT GREEN 10, LIGHT CYAN 11, LIGHT RED 12,
    LIGHT MAGENTA 13, YELLOW 14, WHITE 15,
*/

template<typename T>
void console::print(T msg) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 4);
    std::cout << "[ ALUMINUM ] ";
    SetConsoleTextAttribute(h, 15);
    std::cout << msg;
}

void console::warn(std::string msg) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
    std::cout << "[ ! ] ";
    SetConsoleTextAttribute(h, 15);
    std::cout << msg;
};

void console::success(std::string msg) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_GREEN);
    std::cout << "[ : ] ";
    SetConsoleTextAttribute(h, 15);
    std::cout << msg;
};

void console::error(std::string msg) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << "[ FATAL ] ";
    SetConsoleTextAttribute(h, 15);
    std::cout << msg;
};

void console::ParseCmds(std::string cmd, std::vector<std::string> tokens) {

    std::vector<std::string> args = alm::split(cmd, ' ');
    if (args.size() == 0) {
        std::cout << "Please enter a command (do help for a list of commands)\n";
        return;
    }

    if (args[0] == "help") {
        console::print("Here are the commands available: ");
        std::cout << R"(   
        help - console::prints out this message
        join [invite] - makes the bots join a server
        config - Opens up config.txt
        tokens - Opens up tokens.txt
        raid [channelid] [message] - spams messages to a channel
        leave [guildid] - Leaves a server
        spamfriendrequests/spamfrs [userid] - Sends a friend request to a user
        clear - Clears the console
        version - Gets the current version of Aluminium
)";
    }

    else if (args[0] == "join") {
        if (args.size() >= 2) {
            console::print("Joining " + args[1] + '\n');
            alm::joinServer(args[1]);
        }
        else
            console::print("join [invite] - Makes the bots join a server\n");
    }

    else if (args[0] == "spamfriendrequests" || args[0] == "spamfrs") {
        if (args.size() == 2) {
            alm::spamFriendRequests(args[1]);
        }
        else
            console::print("sendfriendrequests [userid] - Makes the bots join a server\n");
    }

    else if (args[0] == "raid") {
        if (args.size() >= 3) {
            console::print("Starting raid, press ESC to stop.\n");
            std::string message = "";
            for (int i = 2; i < args.size(); i++) {
                message += args[i] + ' ';
            }
            alm::ServerRaid(std::stoull(args[1]), message);
        }
        else {
            console::print("raid [channelid] - Makes the bots join a server\n");
        }
    }
    else if (args[0] == "clear" || args[0] == "cls")
        system("cls");

    else if (args[0] == "config")
        system("start config.txt");
    else if (args[0] == "tokens")
        system("start tokens.txt");

    else if (args[0] == "version")
        console::print("1.0.3\n");

    else
        console::print("Unknown command '" + args[0] + "'\n");
}