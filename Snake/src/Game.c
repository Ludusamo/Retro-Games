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

	game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
	if (game->renderer == NULL) {
		printf("Renderer could not be created. SDL Error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	game->screen = SDL_GetWindowSurface(game->window);
	SDL_FillRect(game->screen, NULL, SDL_MapRGB(game->screen->format, 0xFF, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(game->window);
	game->running = 1;
}

void game_loop(Game *game) {
	Snake snake = create_snake();
	SDL_Event e;
	while (game->running) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				stop_game(game);
			}
		}

		SDL_SetRenderDrawColor(game->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(game->renderer);
		move_snake(&snake);
		render_snake(game->renderer, &snake);
		SDL_RenderPresent(game->renderer);
		SDL_Delay(500);
	}
}

void stop_game(Game *game) {
	game->running = 0;
	printf("Stopping game\n");
	SDL_DestroyWindow(game->window);
	printf("Destroyed Window\n");
	SDL_Quit();	
}
