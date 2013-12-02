#include <colchess.h>

using namespace std;

int main(int argc, char **argv) {
	//Start SDL
	SDL_Init( SDL_INIT_EVERYTHING );

	SDL_Window* screen = SDL_CreateWindow( "Colonization Chess", 0, 0, 640, 480, SDL_WINDOW_SHOWN );
	SDL_Renderer *render = SDL_CreateRenderer(screen, -1,  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	//Update Screen
	SDL_RenderClear(render);
	SDL_RenderPresent(render);

	//Pause
	SDL_Delay( 2000 );

	//Quit SDL
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(screen);
	SDL_Quit();

	return 0;
}
