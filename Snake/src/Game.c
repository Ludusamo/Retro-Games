#include <Game.h>

void start_game(Game *game) {
	printf("Initializing Game\n");
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL Failed to Init. SDL Error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	game->window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (!game->window) {
		printf("Window could not be created. SDL Error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	game->screen = SDL_GetWindowSurface(game->window);
	SDL_FillRect(game->screen, NULL, SDL_MapRGB(game->screen->format, 0xFF, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(game->window);
	SDL_Delay(2000);
}

void stop_game(Game *game) {
	printf("Stopping game\n");
	SDL_DestroyWindow(game->window);
	printf("Destroyed Window\n");
}
