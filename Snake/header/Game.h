#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
	SDL_Window *window;
	SDL_Surface *screen;
} Game;

void start_game(Game *game);
void stop_game();

void update();
void render();

#endif // GAME_H
