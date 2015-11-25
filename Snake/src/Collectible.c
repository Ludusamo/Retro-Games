#include "Collectible.h"

Collectible* spawn_collectible() {
	Collectible *collectible = malloc(sizeof(Collectible));
	collectible->x = rand() % (800 / COL_WIDTH);
	collectible->y = rand() % (600 / COL_HEIGHT);
	return collectible;
}

void render_collectible(SDL_Renderer *renderer, Collectible *collectible) {
	SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
	collectible->bound = (SDL_Rect) { collectible->x * COL_WIDTH, collectible->y * COL_HEIGHT, COL_WIDTH, COL_HEIGHT };
	SDL_RenderFillRect(renderer, &collectible->bound);
}
