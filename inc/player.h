#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <commons.h>
#include <string>

class Tile;

using namespace std;

class Player {
	cchess::T_players side;
	string name;
	SDL_Color color;
	Tile* player_base;
	
	Player();
	public:
		Player(cchess::T_players, const string, SDL_Color);
		
		//Return the drawing color for the player
		SDL_Color getColor();
		
		//Set the player's base tile
		void setBase(Tile*);
		
		//Return the player's base tile
		Tile* getBase();
};

#endif
