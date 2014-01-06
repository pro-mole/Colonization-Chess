#ifndef _TILEMAP_H_
#define _TILEMAP_H_
#include <commons.h>

class Tilemap {
	SDL_Surface* tilemap_surface;
	SDL_Texture* tilemap_texture;
	int tile_h, tile_w; //Tile dimensions
	
	std::map<char,terrachess::MapPosition> charmap;
	std::map<terrachess::TileNames,terrachess::MapPosition> tilemap;
	
	Tilemap();
	public:
		Tilemap(SDL_Surface*, int, int);
		Tilemap(SDL_Surface*, int);
		Tilemap(const char*, int, int);
		Tilemap(const char*, int);

		int drawTile(SDL_Renderer*, terrachess::MapPosition, int, int);
		int drawTile(SDL_Renderer*, char, int, int);
		int drawTile(SDL_Renderer*, terrachess::TileNames, int, int);
};

#endif
