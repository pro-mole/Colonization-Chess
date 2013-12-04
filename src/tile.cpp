#include <tile.h>

Tile::Tile(): Tile(NULL, cchess::T_TERRAIN)
{
}

Tile::Tile(Player* _player, cchess::T_tiles _type)
{
	owner = _player;
	type = _type;
}

void Tile::setType(cchess::T_tiles _type)
{
	type = _type;
}
		
void Tile::setPlayer(Player* _player)
{
	owner = _player;
}
