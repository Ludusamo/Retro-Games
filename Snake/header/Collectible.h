#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#include <time.h>
#include <stdlib.h>

#define COL_WIDTH 20
#define COL_HEIGHT 20

typedef struct {
	int x;
	int y;
	SDL_Rect bound;
} Collectible;

Collectible* spawn_collectible();
void render_collectible(SDL_Renderer *renderer, Collectible *collectible);

#endif // COLLECTIBLE_H
