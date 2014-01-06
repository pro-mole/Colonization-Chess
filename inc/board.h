//Board class
//Represents everything that is on the board
#ifndef _BOARD_H_
#define _BOARD_H_
#include <commons.h>
#include <tilemap.h>
#include <player.h>
#include <tile.h>

using namespace std;

class Board
{
	vector<Tile*> board;
	map<terrachess::Players, Player*> players; //The player list
	terrachess::Players whosturn; //Who plays now
	int size;
	terrachess::BoardPosition cursor;
	
	public:
		//The board (size)
		Board(int size);
		
		//Drawing routine
		void draw(SDL_Renderer*, int, int);
		
		//Get player
		Player* getPlayer(terrachess::Players player);
		
		//Get tile at position
		Tile* getTile(int x, int y);
		
		//Start player's turn(reposition cursor, etc)
		void startTurn(terrachess::Players);
		
		//Keyboard handling
		void keydown(SDL_KeyboardEvent);
};

#endif
