#include <board.h>

Board::Board(int size)
{
	board = new Tile**[size];
	for (int i=0; i<size; i++)
	{
		board[i] = new Tile*[size];
		for (int j=0; j<size; j++)
		{
			board[j][i] = new Tile();
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
