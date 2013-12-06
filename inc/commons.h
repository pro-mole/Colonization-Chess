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
	typedef enum { P_NEUTRAL, P_NATURE, P_INDUSTRY } Players;

	//Tile types
	typedef enum { T_BASE, T_TERRAIN, T_UNIT, T_BUILDING } Tiles;

	//Tile action types
	typedef enum { ACT_MOVE, ACT_CONVERT, ACT_ATTACK, ACT_BOOST, ACT_BUILD } Actions;

	//Tile mapping(will be mapped to x/y positions via std::map)
	typedef enum {
		//Generic board tiles, yay
		TILE_EMPTY,
		TILE_BASE,
		TILE_UNIT,
		TILE_STRUCTURE
	} TileNames;
	
	//Tile position on board
	typedef struct {
		int X;
		int Y;
	} BoardPosition;
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
