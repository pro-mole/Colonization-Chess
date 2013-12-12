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

//Custom types and general global constants
namespace terrachess {
	//Global Constants
	extern const char* version_number;
	extern const char* version_name;
	
	//SDL Global Variables
	extern SDL_Window* main_screen;
	extern SDL_Renderer* main_render;

	//Special enum types
	//Player types
	enum Players { P_NEUTRAL, P_NATURE, P_INDUSTRY };

	//Tile types
	enum Tiles { T_BASE, T_TERRAIN, T_UNIT, T_BUILDING };

	//Tile action types
	enum Actions { ACT_MOVE, ACT_CONVERT, ACT_ATTACK, ACT_BOOST, ACT_BUILD };

	//Tile mapping(will be mapped to x/y positions via std::map)
	enum TileNames {
		//Generic board tiles, yay
		TILE_EMPTY,
		TILE_BASE,
		TILE_UNIT,
		TILE_STRUCTURE
	};
	
	//Tile position on board
	struct BoardPosition {
		int X;
		int Y;
	};
	
	//Tile position on map
	struct MapPosition {
		int X;
		int Y;
	};
}

//Color related constants
namespace color {
	extern SDL_Color
		C_BACKGROUND,
		C_FOREGROUND,
		//Player Colors
		C_NEUTRAL,
		C_NATURE,
		C_INDUSTRY;
}
#endif
