#ifndef SNAKE_H
#define SNAKE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <stdio.h>

#define SEG_WIDTH 10
#define SEG_HEIGHT 10

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
	SDL_Rect bound;
} Seg;

typedef struct {
	Seg *head;	
	Seg *tail;
} Snake;

Seg* create_seg(int x, int y, int dir);
Snake create_snake();
void add_segment(Snake *snake);
void change_direction(Snake *snake);
void move_snake(Snake *snake);
void render_snake(SDL_Renderer *renderer, Snake *snake);

#endif // SNAKE_H