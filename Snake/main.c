#include <Game.h>

int main(int argc, char* args[]) {
	Game *game;
	start_game(game);
	stop_game(game);
	SDL_Quit();	
	return 0;
}
