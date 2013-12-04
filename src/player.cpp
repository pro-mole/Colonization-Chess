#include <player.h>

Player::Player()
{
	side = cchess::P_NEUTRAL;
}

Player::Player(cchess::T_players _side)
{
	side = _side;
}
