#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <stdio.h>

#include "Snake.h"

#define WIDTH 800
#define HEIGHT 600

typedef struct {
	SDL_Window *window;
	SDL_Surface *screen;
	SDL_Renderer *renderer;
	int running;
} Game;

void start_game(Game *game);
void game_loop(Game *game);
void stop_game(Game *game);

void update();
void render();

#endif // GAME_H
