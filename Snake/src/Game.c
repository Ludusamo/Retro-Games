#include <Game.h>

void start_game(Game *game) {
	printf("Initializing Game\n");
	srand(time(NULL));
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
	Collectible *col = spawn_collectible();
	SDL_Event e;
	const Uint8* currentKeyStates;
	while (game->running) {
		if (game->reset) {
			snake = create_snake();
			free(col);
			col = spawn_collectible();
			game->reset = 0;
		}

		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				stop_game(game);
			}
		}

		currentKeyStates = SDL_GetKeyboardState(NULL);	
		if (snake.head->dir != DOWN && currentKeyStates[SDL_SCANCODE_UP])
			snake.head->dir = UP;
		else if (snake.head->dir != UP && currentKeyStates[SDL_SCANCODE_DOWN])
			snake.head->dir = DOWN;
		else if (snake.head->dir != RIGHT && currentKeyStates[SDL_SCANCODE_LEFT])
			snake.head->dir = LEFT;
		else if (snake.head->dir != LEFT && currentKeyStates[SDL_SCANCODE_RIGHT])
			snake.head->dir = RIGHT;
		if (currentKeyStates[SDL_SCANCODE_D])
			add_segment(&snake);

		clear_screen(game);		
		update(game, &snake, col);
		render(game, &snake, col);
		SDL_Delay(250);
	}
}

void stop_game(Game *game) {
	game->running = 0;
	printf("Stopping game\n");
	SDL_DestroyWindow(game->window);
	printf("Destroyed Window\n");
	SDL_Quit();	
}

void clear_screen(Game *game) {
	SDL_SetRenderDrawColor(game->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(game->renderer);
}

void update(Game *game, Snake *snake, Collectible *col) {
	int collided = move_snake(snake);
	if (collided) {
		game->reset = 1;
	}
	if (snake->head->x == col->x && snake->head->y == col->y) {
		free(col);
		col = spawn_collectible();
		add_segment(snake);
	}
}

void render(Game *game, Snake *snake, Collectible *col) {
	render_snake(game->renderer, snake);
	render_collectible(game->renderer, col);
	SDL_RenderPresent(game->renderer);
}
