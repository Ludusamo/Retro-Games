#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <stdio.h>

#include "Snake.h"
#include "Collectible.h"

#define WIDTH 800
#define HEIGHT 600

typedef struct {
	SDL_Window *window;
	SDL_Surface *screen;
	SDL_Renderer *renderer;
	int running;
	int reset;
} Game;

void start_game(Game *game);
void game_loop(Game *game);
void stop_game(Game *game);

void clear_screen(Game *game);
void update(Game *game, Snake *snake, Collectible *col);
void render(Game *game, Snake *snake, Collectible *col);

#endif // GAME_H
