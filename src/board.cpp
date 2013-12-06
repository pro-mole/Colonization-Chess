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
			board[j*size + i] = new Tile(i+1, j+1, NULL, terrachess::T_TERRAIN);
		}
	}
	
	//Create Players
	players[terrachess::P_NEUTRAL] = NULL;
	players[terrachess::P_NATURE] = new PlayerNature();
	players[terrachess::P_INDUSTRY] = new PlayerIndustry();
	
	//Position players
	int midway = ceil(size/2.0);
	Tile* base;
	base = this->getTile(size, midway);
	base->setType(terrachess::T_BASE);
	this->getPlayer(terrachess::P_NATURE)->setBase(base);
	
	base = this->getTile(1, midway);
	base->setType(terrachess::T_BASE);
	this->getPlayer(terrachess::P_INDUSTRY)->setBase(base);
	
	startTurn(terrachess::P_NATURE);
}

Player* Board::getPlayer(terrachess::Players player)
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

void Board::startTurn(terrachess::Players player)
{
	//Put cursor on player's base
	cursor = this->getPlayer(player)->getBase()->getPosition();
	whosturn = player;
}

void Board::keydown(SDL_KeyboardEvent ev_key)
{
	switch(ev_key.keysym.sym)
	{
		case SDLK_LEFT:
			if (cursor.X > 1)
				cursor.X -= 1;
			break;
		case SDLK_RIGHT:
			if (cursor.X < size)
				cursor.X += 1;
			break;
		case SDLK_UP:
			if (cursor.Y > 1)
				cursor.Y -= 1;
			break;
		case SDLK_DOWN:
			if (cursor.Y < size)
				cursor.Y += 1;
			break;
	}
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
	SDL_Rect cursor_rect = {x+(cursor.X-1)*tile_w, y+(cursor.Y-1)*tile_h, tile_w, tile_h};
	SDL_SetRenderDrawColor(render, 255, 255,255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawRect(render, &cursor_rect);
}