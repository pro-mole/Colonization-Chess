#include <colchess.h>

using namespace std;

const char* cchess::version_number = "0.1a";
const char* cchess::version_name = "amphioxus";

ColonizationChess* ColonizationChess::instance;
SDL_Window* ColonizationChess::screen;
SDL_Renderer* ColonizationChess::render;

ColonizationChess* ColonizationChess::getInstance()
{
	if (instance == NULL)
		instance = new ColonizationChess();
	
	return instance;
}

void ColonizationChess::init()
{
	if (screen == NULL)
	{
		//Start SDL
		SDL_Init( SDL_INIT_EVERYTHING );

		char* title = NULL;
		sprintf(title, "Colonization Chess %s(%s)", cchess::version_number, cchess::version_name);
		screen = SDL_CreateWindow( title, 64, 64, 640, 480, SDL_WINDOW_SHOWN );
		render = SDL_CreateRenderer(screen, -1,  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	}
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

	ColonizationChess::getInstance();
	ColonizationChess::init();
	
	SDL_Delay(2000);

	ColonizationChess::end();
	return 0;
}
