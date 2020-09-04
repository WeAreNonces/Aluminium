#include "cpr/cpr.h"
#include "Discord.h"

#include <iostream>

std::string discord::getmessagestest() {
    cpr::Response r = cpr::Get(cpr::Url{ "https://discord.com/api/v8/channels/730838880260980908/messages?limit=50" });
   
    return r.text;
}