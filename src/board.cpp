#include <board.h>

Board::Board(int size)
{
	board = vector<Tile*>(size * size);
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
		{
			std::cerr << "Board cell " << j << "," << i << "\n";
			board[j*size + i] = new Tile();
		}
	}
}

Player* Board::getPlayer(cchess::T_players player)
{
	return NULL;
}

Tile* Board::getTile(int x, int y)
{
	return NULL;
}
