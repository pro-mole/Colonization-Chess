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
	map<cchess::T_players, Player*> players;
	int size;
	
	public:
		//The board (size)
		Board(int size);
		
		//Get player
		Player* getPlayer(cchess::T_players player);
		
		//Get tile at position
		Tile* getTile(int x, int y);
};

#endif
