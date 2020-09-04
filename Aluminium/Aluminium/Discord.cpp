#include <iostream>
#include <string>
#include <random>
#include <math.h>
#include "cpr/cpr.h"
#include "Discord.h"
#include "Aluminium.h"

// Functions

int getRandomNumber(int min, int max)
{
    static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };  // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

inline const std::string const BoolToString(bool b)
{
    return b ? "true" : "false";
}


// Account class


// Sends a message in the given channelId
// Token must be in server (see api::Discord::joinserver)
// Returns a status code
int discord::Account::send(std::uint64_t channelId, std::string content, bool tts) {
    std::string url = "https://discord.com/api/v8/channels/" + std::to_string(channelId) + "/messages";
    cpr::Response r = cpr::Post(cpr::Url{ url },
        cpr::Header{ {"authorization", this->m_token}, {"content-type", "application/json"} },
        cpr::Body{ "{\"content\": \"" + content + "\", \"nonce\": " + std::to_string(getRandomNumber(99999999, 999999999)) + ", \"tts\": " + BoolToString(tts) + "}" });
    return r.status_code;
}

// Joins the server from the invite
int discord::Account::joinserver(std::string invite) {
    std::string url = "https://discord.com/api/v8/invites/" + invite;
    cpr::Response r = cpr::Post(cpr::Url{ url },
        cpr::Payload{ {"inputValue", invite}, {"with_counts", true} },
        cpr::Header{ {"authorization", this->m_token}, {"content-type", "application/json"} });
    return r.status_code;
}

// Changes the account's nickname
int discord::Account::changenick(std::uint64_t guildId, std::string newName) {
    std::string url = "https://discord.com/api/v8/guilds/" + std::to_string(guildId) + "/members/@me/nick";
    cpr::Response r = cpr::Patch(cpr::Url{ url },
        cpr::Header{ {"authorization", this->m_token}, {"content-type", "application/json"} },
        cpr::Body{ "{\"nick\": \"" + newName + "\"}" });
    return r.status_code;
}

// Sends a friend request to a user
// Example: Account::sendFriendRequest("vi#0049");
int discord::Account::sendFriendRequest(std::string name) {
    std::vector<std::string> n = alm::split(name, '#');
    n[1] = std::to_string(std::stoi(n[1])); // flushop
    std::string url = "https://discordapp.com/api/v8/users/@me/relationships";
    cpr::Response r = cpr::Post(cpr::Url{ url },
        cpr::Header{ {"Authorization", this->m_token}, {"Content-Type", "application/json"} },
        cpr::Body{ "{\"username\": \"" + n[0] + "\", \"discriminator\": " + n[1] + " }" });
    switch (r.status_code) {
    case 200:
    case 204:
        return 200;
    case 400:
        throw "Bad Request";
    case 401:
        throw "Unauthorized";
    case 403:
        throw "Forbidden";
    default:
        throw r.status_code;
    }
}

// Verifies if the token is valid
bool discord::Account::verifyToken() {
    std::string url = "https://discordapp.com/api/v8/users/@me";
    cpr::Response r = cpr::Get(cpr::Url{ url },
        cpr::Header{ {"Authorization", this->m_token} });
    switch (r.status_code) {
    case 200:
        return true;
    case 204:
        return true;
    default:
        return false;
    }
}