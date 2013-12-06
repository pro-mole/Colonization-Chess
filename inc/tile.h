#ifndef _TILE_H_
#define _TILE_H_
#include <commons.h>

class Player;

class Tile {
	terrachess::Tiles type;
	Player* owner;
	terrachess::BoardPosition pos;
	
	Tile();
	public:
		Tile(int, int, Player*, terrachess::Tiles);
		
		void draw(SDL_Renderer*, int, int);
		
		terrachess::Tiles getType();
		void setType(terrachess::Tiles);
		
		Player* getPlayer();
		void setPlayer(Player*);
		
		SDL_Color getColor();
		
		int getX();
		int getY();
		terrachess::BoardPosition getPosition();
};

#endif