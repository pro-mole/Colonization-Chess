#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <commons.h>

class Player {
	cchess::T_players side;
	
	Player();
	public:
		Player(cchess::T_players);
};

#endif
