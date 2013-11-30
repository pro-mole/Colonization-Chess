#include <colchess.h>

using namespace std;

int main(int argc, char **argv) {
	//Start SDL
	SDL_Init( SDL_INIT_EVERYTHING );

	SDL_Surface* screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );

	//Update Screen
	SDL_Flip( screen );

	//Pause
	SDL_Delay( 2000 );

	//Quit SDL
	SDL_Quit();

	return 0;
}
