#ifndef _TILE_H_
#define _TILE_H_
#include <commons.h>

class Player;

class Tile {
	cchess::T_tiles type;
	Player* owner;
	cchess::board_position pos;
	
	Tile();
	public:
		Tile(int, int, Player*, cchess::T_tiles);
		
		void draw(SDL_Renderer*, int, int);
		
		cchess::T_tiles getType();
		void setType(cchess::T_tiles);
		
		Player* getPlayer();
		void setPlayer(Player*);
		
		SDL_Color getColor();
		
		int getX();
		int getY();
		cchess::board_position getPosition();
};

#endif