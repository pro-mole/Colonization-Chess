#include <board.h>

Board::Board(int _size)
{
	size = _size;
	board = vector<Tile*>(size * size);
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
		{
			std::cerr << "Board cell " << j << "," << i << "\n";
			board[j*size + i] = new Tile(NULL, cchess::T_TERRAIN);
		}
	}
	
	//Create Players
	players[cchess::P_NEUTRAL] = NULL;
	players[cchess::P_NATURE] = new Player(cchess::P_NATURE);
	players[cchess::P_INDUSTRY] = new Player(cchess::P_INDUSTRY);
	
	//Position players
	int midway = ceil(size/2.0);
	Tile* base = getTile(size, midway);
	base->setType(cchess::T_BASE);
	base->setPlayer(getPlayer(cchess::P_NATURE));
	
	base = getTile(1, midway);
	base->setType(cchess::T_BASE);
	base->setPlayer(getPlayer(cchess::P_INDUSTRY));
}

Player* Board::getPlayer(cchess::T_players player)
{
	return players[player];
}

Tile* Board::getTile(int x, int y)
{
	x = x-1;
	y = y-1;
	if (x > size || y > size || x < 0 || y < 0)
		return NULL;
	return board[y * size + x];
}
