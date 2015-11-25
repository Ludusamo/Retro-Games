#include "Snake.h"

Seg* create_seg(int x, int y, int dir) {
	Seg *seg = malloc(sizeof(Seg));
	seg->x = x;
	seg->y = y;
	seg->dir = dir;
	seg->nextSeg = NULL;
	return seg;
}

Snake create_snake() {
	Snake snake;	
	snake.head = create_seg(3, 3, RIGHT);

	snake.head->nextSeg = create_seg(2, 3, RIGHT);
	snake.head->nextSeg->parent = snake.head;

	snake.head->nextSeg->nextSeg = create_seg(1, 3, RIGHT);
	snake.head->nextSeg->nextSeg->parent = snake.head->nextSeg;
	snake.tail = snake.head->nextSeg->nextSeg;
	return snake;
}

void add_segment(Snake *snake) {
	int x, y;
	int dir = snake->tail->dir;
	if (dir == UP) {
		x = snake->tail->x;
		y = snake->tail->y + 1;
	} else if (dir == DOWN) {
		x = snake->tail->x;
		y = snake->tail->y - 1;
	} else if (dir == LEFT) {
		x = snake->tail->x + 1;
		y = snake->tail->y;
	} else if (dir == RIGHT) {
		x = snake->tail->x - 1;
		y = snake->tail->y;
	}

	Seg *newSeg = create_seg(x, y, dir);
	newSeg->parent = snake->tail;
	snake->tail->nextSeg = newSeg;
	snake->tail = newSeg;;
}

void move_snake(Snake *snake) {
	Seg *currSeg = snake->tail;		
	while (currSeg) {
		int dir = currSeg->dir;
		if (dir == UP) {
			currSeg->y--;
			if (currSeg->parent && currSeg->y == currSeg->parent->y)
				currSeg->dir = currSeg->parent->dir;
		}
		if (dir == DOWN) {
			currSeg->y++;
			if (currSeg->parent && currSeg->y == currSeg->parent->y)
				currSeg->dir = currSeg->parent->dir;
		}
		if (dir == LEFT) {
			currSeg->x--;
			if (currSeg->parent && currSeg->x == currSeg->parent->x)
				currSeg->dir = currSeg->parent->dir;
		}
		if (dir == RIGHT) {
			currSeg->x++;
			if (currSeg->parent && currSeg->x == currSeg->parent->x)
				currSeg->dir = currSeg->parent->dir;
		}
		currSeg = currSeg->parent;
	}
}

void render_snake(SDL_Renderer *renderer, Snake *snake) {
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	Seg *currSeg = snake->head;
	while (currSeg != NULL) {
		currSeg->bound = (SDL_Rect) { currSeg->x * SEG_WIDTH, currSeg->y * SEG_HEIGHT, SEG_WIDTH, SEG_HEIGHT };
		SDL_RenderFillRect(renderer, &currSeg->bound);
		currSeg = currSeg->nextSeg;
	}
}
