#include <colchess.h>

using namespace std;

const char* cchess::version_number = "0.1a";
const char* cchess::version_name = "amphioxus";

void ColonizationChess::init()
{
	if (screen == NULL)
	{
		//Start SDL
		SDL_Init( SDL_INIT_EVERYTHING );

		char* title = new char[256];
		sprintf(title, "Colonization Chess %s(%s)", cchess::version_number, cchess::version_name);
		screen = SDL_CreateWindow( title, 64, 64, 640, 480, SDL_WINDOW_SHOWN );
		render = SDL_CreateRenderer(screen, -1,  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	}

	board = new Board(9);
}

void ColonizationChess::end()
{
	if (screen != NULL)
	{
		SDL_DestroyRenderer(render);
		SDL_DestroyWindow(screen);
		SDL_Quit();
	}
}

int main(int argc, char **argv) {

	ColonizationChess* colchess = new ColonizationChess();
	colchess->init();
	
	SDL_Delay(2000);

	colchess->end();
	return 0;
}
