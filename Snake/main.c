#include <Game.h>

int main(int argc, char* args[]) {
	Game *game;
	start_game(game);
	game_loop(game);
	stop_game(game);
	return 0;
}
