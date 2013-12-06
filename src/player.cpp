#include <player.h>
#include <tile.h>

Player::Player()
{
	side = cchess::P_NEUTRAL;
	name = "PLAYER";
	color = color::C_NEUTRAL;
	player_base = NULL;
}

Player::Player(cchess::T_players _side, const string _name, SDL_Color _color)
{
	side = _side;
	name = _name;
	color = _color;
	player_base = NULL;
}

void Player::setBase(Tile* base_tile)
{
	player_base = base_tile;
	base_tile->setPlayer(this);
}

Tile* Player::getBase()
{
	return player_base;
}

SDL_Color Player::getColor()
{
	return color;
}
