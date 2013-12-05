#include <board.h>
#include <playerNature.h>
#include <playerIndustry.h>

Board::Board(int _size)
{
	size = _size;
	//std::cerr << size << "\n";
	board = vector<Tile*>(size * size);
	for (int i=0; i<size; i++)
	{	
		for (int j=0; j<size; j++)
		{
			std::cerr << "Board cell " << (i+1) << "," << (j+1) << "\n";
			board[j*size + i] = new Tile(i, j, NULL, cchess::T_TERRAIN);
		}
	}
	
	//Create Players
	players[cchess::P_NEUTRAL] = NULL;
	players[cchess::P_NATURE] = new PlayerNature();
	players[cchess::P_INDUSTRY] = new PlayerIndustry();
	
	//Position players
	int midway = ceil(size/2.0);
	Tile* base;
	base = this->getTile(size, midway);
	base->setType(cchess::T_BASE);
	this->getPlayer(cchess::P_NATURE)->setBase(base);
	
	base = this->getTile(1, midway);
	base->setType(cchess::T_BASE);
	this->getPlayer(cchess::P_INDUSTRY)->setBase(base);
	
	startTurn(cchess::P_NATURE);
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

void Board::startTurn(cchess::T_players player)
{
	//Put cursor on player's base
	cursor = this->getPlayer(player)->getBase()->getPosition();
	whosturn = player;
}

void Board::draw(SDL_Renderer* render, int x, int y)
{
	int tile_x = 0,
		tile_y = 0;
	const int tile_h = 16,
		tile_w = 16;
	
	for (tile_y = 0; tile_y < size; tile_y++)
	{
		cerr << "Draw tile at (" << (tile_x+1) << "," << (tile_y+1) << ")\n";
		for (tile_x = 0; tile_x < size; tile_x++)
		{
			this->getTile(tile_x+1,tile_y+1)->draw(render, x+tile_x*tile_w, y+tile_y*tile_h);
		}
	}
	
	//Draw grid lines
	
	//Draw cursor
	SDL_Rect cursor_rect = {x+cursor.X*tile_w, y+cursor.Y*tile_h, tile_w, tile_h};
	SDL_SetRenderDrawColor(render, 255, 255,255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawRect(render, &cursor_rect);
}