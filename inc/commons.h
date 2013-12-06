#ifndef COMMONS_H_
#define COMMONS_H_

#include <SDL.h>
#include <SDL_main.h>
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <cmath>

namespace color {
	extern SDL_Color
		C_BACKGROUND,
		C_FOREGROUND,
		//Player Colors
		C_NEUTRAL,
		C_NATURE,
		C_INDUSTRY;
}

namespace cchess {
	//Global Constants
	extern const char* version_number;
	extern const char* version_name;

	//Special enum types
	//Player types
	typedef enum { P_NEUTRAL, P_NATURE, P_INDUSTRY } T_players;

	//Tile types
	typedef enum { T_BASE, T_TERRAIN, T_UNIT, T_BUILDING } T_tiles;

	//Tile action types
	typedef enum { ACT_MOVE, ACT_CONVERT, ACT_ATTACK, ACT_BOOST, ACT_BUILD } T_actions;

	//Tile mapping(will be mapped to x/y positions via std::map)
	typedef enum {
		TILE_EMPTY
	} T_tilemap;
	
	//Tile position on board
	typedef struct {
		int X;
		int Y;
	} board_position;
}
#endif
