#ifndef _TILEMAP_H_
#define _TILEMAP_H_
#include <commons.h>

class Tilemap {
	SDL_Surface* tilemap;
	int tile_h, tile_w; //Tile dimensions
	
	Tilemap();
	public:
		Tilemap(SDL_Surface*, int, int);
		Tilemap(SDL_Surface*, int);
		Tilemap(const char*, int, int);
		Tilemap(const char*, int);
};

#endif