#ifndef _TILEMAP_H_
#define _TILEMAP_H_
#include <commons.h>

class Tilemap {
	SDL_Surface* tilemap_surface;
	int tile_h, tile_w; //Tile dimensions
	
	std::map<char,terrachess::MapPosition> charmap;
	std::map<terrachess::TileNames,terrachess::MapPosition> tilemap;
	
	Tilemap();
	public:
		Tilemap(SDL_Surface*, int, int);
		Tilemap(SDL_Surface*, int);
		Tilemap(const char*, int, int);
		Tilemap(const char*, int);

		SDL_Surface* drawTile(SDL_Renderer*, terrachess::MapPosition);
		SDL_Surface* drawTile(SDL_Renderer*, char);
		SDL_Surface* drawTile(SDL_Renderer*, terrachess::TileNames);
};

#endif
