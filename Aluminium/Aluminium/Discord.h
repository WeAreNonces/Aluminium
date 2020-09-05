#ifndef DISCORD_LIB
#define DISCORD_LIB
#include <iostream>
#include <ctime>


namespace discord {

	class Account {
	private:
		std::string m_token;
	public:
		Account(std::string token) : m_token{ token }
		{
			std::srand(static_cast<unsigned int>(std::time(nullptr)));
		}

		int send(std::uint64_t channelId, std::string content, bool tts = false);
		std::uint64_t joinserver(std::string invite);
		void leaveserver(std::uint64_t guildId);
		int changenick(std::uint64_t guildId, std::string newNickname);
		int sendFriendRequest(std::string name);
		bool verifyToken();
	};

}

#endif // !DISCORD_LIB
