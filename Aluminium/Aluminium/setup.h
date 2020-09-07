#ifndef ALM_SETUP
#define ALM_SETUP

/* 
	Mainly for setting up the config
*/

namespace setup {
	bool configsExist();
	bool tokensExist();
	void createDefaultConfig();
	void createDefaultTokens();
}

#endif