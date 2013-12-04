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
		cerr << "Window created\n";
		render = SDL_CreateRenderer(screen, -1,  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		cerr << "Rendered created\n";
	}

	board = new Board(9);
}

void ColonizationChess::update()
{
	SDL_UpdateWindowSurface(screen);
}

void ColonizationChess::end()
{
	if (screen != NULL)
	{
		SDL_DestroyRenderer(render);
		cerr << "Render destroyed\n";
		SDL_DestroyWindow(screen);
		cerr << "Window destroyed\n";
		SDL_Quit();
		cerr << "Bye bye\n";
	}
}

int main(int argc, char **argv) {
	
	cerr << "START\n";
	ColonizationChess* colchess = new ColonizationChess();
	cerr << "Starting game (v" << cchess::version_number << "/" << cchess::version_name << ")\n";
	colchess->init();
	
	//Event handler
	SDL_Event e;
	bool quit = false;
	int fps = 10;
	unsigned int timeout = 1000/fps;
	while (!quit)
	{
		unsigned int _framestart = SDL_GetTicks();
		while( SDL_PollEvent( &e ) != 0 )
		{
			if (e.type == SDL_QUIT)
				quit = true;
		}
		
		colchess->update();
		while ((SDL_GetTicks() - _framestart) < timeout)
		{
			SDL_Delay(10);
		}
	}

	colchess->end();
	return 0;
}
