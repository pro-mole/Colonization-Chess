#include <tileMap.h>

Tilemap::Tilemap()
{
	tilemap = NULL;
	tile_h = tile_w = 8;
}

Tilemap::Tilemap(SDL_Surface* _texture, int _w, int _h)
{
	tilemap = _texture;
	tile_w = _w;
	tile_h = _h;
}

Tilemap::Tilemap(SDL_Surface* _texture, int _size)
{
	tilemap = _texture;
	tile_h = tile_w = _size;
}

Tilemap::Tilemap(const char* _filename, int _w, int _h)
{
	tilemap = SDL_LoadBMP(_filename);
	tile_w = _w;
	tile_h = _h;
}

Tilemap::Tilemap(const char* _filename, int _size)
{
	tilemap = SDL_LoadBMP(_filename);
	tile_h = tile_w = _size;
}
