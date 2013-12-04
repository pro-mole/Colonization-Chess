#include <player.h>

Player::Player(): Player(cchess::P_NEUTRAL)
{
}

Player::Player(cchess::T_players _side)
{
	side = _side;
}