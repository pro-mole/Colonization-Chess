#include <colchess.h>

using namespace std;

const char* terrachess::version_number = "0.1a";
const char* terrachess::version_name = "amphioxus";

SDL_Window* terrachess::main_screen = NULL;
SDL_Renderer* terrachess::main_render = NULL;

SDL_Color
	color::C_BACKGROUND = 	{0x00, 0x00, 0x00, 255},
	color::C_FOREGROUND = 	{0xff, 0xff, 0xff, 255},
	color::C_NEUTRAL = 	{0x48, 0x3C, 0x32, 255},
	color::C_NATURE = 		{0x00, 0xC0, 0x00, 255},
	color::C_INDUSTRY = 	{0x80, 0x80, 0x80, 255};
	
void ColonizationChess::init()
{
	if (screen == NULL)
	{
		//Start SDL
		SDL_Init( SDL_INIT_EVERYTHING );

		char* title = new char[256];
		sprintf(title, "Colonization Chess %s(%s)", terrachess::version_number, terrachess::version_name);
		screen = SDL_CreateWindow( title, 64, 64, 640, 480, SDL_WINDOW_SHOWN );
		terrachess::main_screen = screen;
		cerr << "Window created" << endl;
		render = SDL_CreateRenderer(screen, -1,  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		terrachess::main_render = render;
		cerr << "Renderer created" << endl;
	}

	board = new Board(9);
	tilemap = new Tilemap("assets/terminalfont_8x8",8);
}

void ColonizationChess::draw()
{
	SDL_RenderClear(render);
	//Fill the screen black for background
	SDL_SetRenderDrawColor(render, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(render, NULL);
	//SDL_UpdateWindowSurface(screen);
	
	cerr << "Draw the board\n";
	//Draw the board on top
	board->draw(render, (640-9*16)/2, (480-9*16)/2);
	
	SDL_RenderPresent(render);
}

void ColonizationChess::keydown(SDL_KeyboardEvent key)
{
	board->keydown(key);
}

void ColonizationChess::update()
{
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
	cerr << "Starting game (v" << terrachess::version_number << "/" << terrachess::version_name << ")\n";
	colchess->init();
	
	//Event handler
	SDL_Event e;
	bool quit = false;
	int fps = 25;
	unsigned int timeout = 1000/fps;
	while (!quit)
	{
		unsigned int _framestart = SDL_GetTicks();
		while( SDL_PollEvent( &e ) != 0 )
		{
			if (e.type == SDL_QUIT)
				quit = true;
				
			else if (e.type == SDL_KEYDOWN)
			{
				switch(e.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						quit = true; break;
				}
				
				colchess->keydown(e.key);
			}
		}
		
		colchess->draw();
		colchess->update();
		while ((SDL_GetTicks() - _framestart) < timeout)
		{
			SDL_Delay(10);
		}
	}

	colchess->end();
	delete colchess;
	return 0;
}
