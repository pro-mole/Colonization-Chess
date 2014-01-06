#include <tileMap.h>

Tilemap::Tilemap()
{
	tilemap_surface = NULL;
	tile_h = tile_w = 8;
}

Tilemap::Tilemap(SDL_Surface* _texture, int _w, int _h)
{
	tilemap_surface = _texture;
	tilemap_texture = SDL_CreateTextureFromSurface(terrachess::main_render, _texture);
	tile_w = _w;
	tile_h = _h;
}

Tilemap::Tilemap(SDL_Surface* _texture, int _size)
{
	tilemap_surface = _texture;
	tilemap_texture = SDL_CreateTextureFromSurface(terrachess::main_render, _texture);
	tile_h = tile_w = _size;
}

Tilemap::Tilemap(const char* _filename, int _w, int _h)
{
	tilemap_surface = SDL_LoadBMP(_filename);
	tilemap_texture = SDL_CreateTextureFromSurface(terrachess::main_render, tilemap_surface);
	tile_w = _w;
	tile_h = _h;
}

Tilemap::Tilemap(const char* _filename, int _size)
{
	tilemap_surface = SDL_LoadBMP(_filename);
	tilemap_texture = SDL_CreateTextureFromSurface(terrachess::main_render, tilemap_surface);
	tile_h = tile_w = _size;
}

int Tilemap::drawTile(SDL_Renderer* render, terrachess::MapPosition pos, int renderX, int renderY)
{
	SDL_Rect org = (SDL_Rect) {pos.X, pos.Y, tile_w, tile_h}, dst = (SDL_Rect) {renderX, renderY, tile_w, tile_h};
	return SDL_RenderCopy(render, tilemap_texture, &org, &dst);
}

int Tilemap::drawTile(SDL_Renderer* render, char chr, int renderX, int renderY)
{
	if (charmap.count(chr) > 0)
	{
		return drawTile(render, charmap[chr], renderX, renderY);
	}
	
	return -1;
}

int Tilemap::drawTile(SDL_Renderer* render, terrachess::TileNames name, int renderX, int renderY)
{
	if (tilemap.count(name) > 0)
	{
		return drawTile(render, tilemap[name], renderX, renderY);
	}
	
	return -1;
}
