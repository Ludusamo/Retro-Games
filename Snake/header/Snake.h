#ifndef SNAKE_H
#define SNAKE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <stdio.h>

#define SEG_WIDTH 20
#define SEG_HEIGHT 20

typedef enum {
	UP,
	DOWN,
	LEFT,
	RIGHT
} Dir;

typedef struct Seg {
	int x;
	int y;
	int dir;
	struct Seg *nextSeg;
	struct Seg *parent;
	SDL_Rect bound;
} Seg;

typedef struct {
	Seg *head;	
	Seg *tail;
} Snake;

Seg* create_seg(int x, int y, int dir);
Snake create_snake();
void add_segment(Snake *snake);
int move_snake(Snake *snake);
void render_snake(SDL_Renderer *renderer, Snake *snake);

int collided_with_head(Seg *head, Seg *seg);

#endif // SNAKE_H
