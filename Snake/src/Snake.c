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
	snake.head->nextSeg->nextSeg = create_seg(1, 3, RIGHT);
	snake.tail = snake.head->nextSeg->nextSeg;
	return snake;
}

void add_segment(Snake *snake) {
	int x, y;
	int dir = snake->tail->dir;
	switch (dir) {
	case UP:	
		break;
	case DOWN:
		break;
	case LEFT:
		break;
	case RIGHT:
		break;
	}
	//snake->tail->nextSeg = create_seg(
}

void render_snake(SDL_Renderer *renderer, Snake *snake) {
	printf("%i %i\n", snake->head->x, snake->head->y);
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	Seg *currSeg = snake->head;
	while (currSeg != NULL) {
		printf("%i %i\n", currSeg->x, currSeg->y);
		currSeg->bound = (SDL_Rect) { currSeg->x * SEG_WIDTH, currSeg->y * SEG_HEIGHT, 10, 10 };
		SDL_RenderFillRect(renderer, &currSeg->bound);
		currSeg = currSeg->nextSeg;
	}
}
