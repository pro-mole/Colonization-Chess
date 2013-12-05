//Board class
//Represents everything that is on the board
#ifndef _BOARD_H_
#define _BOARD_H_
#include <commons.h>
#include <player.h>
#include <tile.h>

using namespace std;

class Board
{
	vector<Tile*> board;
	map<cchess::T_players, Player*> players; //The player list
	cchess::T_players whosturn; //Who plays now
	int size;
	cchess::board_position cursor;
	
	public:
		//The board (size)
		Board(int size);
		
		//Drawing routine
		void draw(SDL_Renderer*, int, int);
		
		//Get player
		Player* getPlayer(cchess::T_players player);
		
		//Get tile at position
		Tile* getTile(int x, int y);
		
		//Start player's turn(reposition cursor, etc)
		void startTurn(cchess::T_players);
};

#endif
