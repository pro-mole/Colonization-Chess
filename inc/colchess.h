#include <commons.h>
#include <board.h>
#include <player.h>
#include <tile.h>

//The game class, as usual
class ColonizationChess
{
	static ColonizationChess* instance;//Let's make this a singleton, just in case
	static SDL_Window* screen; //Main screen, where we draw all the stuff
	static SDL_Renderer* render; //Main renderer, default to draw everything
	
	public:
		static ColonizationChess* getInstance();
	
		//Starts the game
		//Create SDL window, set up a new board, the stuff
		static void init();
		
		//Clean up and finish
		static void end();
};