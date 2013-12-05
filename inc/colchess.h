#include <commons.h>
#include <board.h>
#include <player.h>
#include <tile.h>

//The game class, as usual
class ColonizationChess
{
	ColonizationChess* instance;//Let's make this a singleton, just in case
	SDL_Window* screen; //Main screen, where we draw all the stuff
	SDL_Renderer* render; //Main renderer, default to draw everything
	
	Board* board; //The game board

	public:
		//Starts the game
		//Create SDL window, set up a new board, the stuff
		void init();
		
		//Update
		void update();
		
		//Draw
		void draw();
		
		//Keyboard handling
		void keydown(SDL_KeyboardEvent);
		
		//Clean up and finish
		void end();
};
