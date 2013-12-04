#ifndef _TILE_H_
#define _TILE_H_
#include <commons.h>
#include <player.h>

class Tile {
	cchess::T_tiles type;
	Player* owner;
	Tile();
	public:
		Tile(Player*, cchess::T_tiles);
		
		void setType(cchess::T_tiles);
		
		void setPlayer(Player*);
};

#endif