#include <tile.h>
#include <player.h>

Tile::Tile()
{
	owner = NULL;
	type = terrachess::T_TERRAIN;
	pos = {-1, -1};
}

Tile::Tile(int x, int y, Player* _player, terrachess::Tiles _type)
{
	owner = _player;
	type = _type;
	pos = {x, y};
}

void Tile::setType(terrachess::Tiles _type)
{
	type = _type;
}

terrachess::Tiles Tile::getType()
{
	return type;
}

void Tile::setPlayer(Player* _player)
{
	owner = _player;
}

Player* Tile::getPlayer()
{
	return owner;
}

SDL_Color Tile::getColor()
{
	if (this->getPlayer() == NULL)
		return color::C_NEUTRAL;
	else
		return this->getPlayer()->getColor();
}

int Tile::getX()
{
	return pos.X;
}

int Tile::getY()
{
	return pos.Y;
}

terrachess::BoardPosition Tile::getPosition()
{
	return pos;
}

void Tile::draw(SDL_Renderer* render, int x, int y)
{
	SDL_Color player_color = this->getColor();
	SDL_Rect tile_pos = {x, y, 16, 16};
	SDL_SetRenderDrawColor(render, player_color.r, player_color.g, player_color.b, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(render, &tile_pos);
}