/*
** EPITECH PROJECT, 2018
** dante
** File description:
** functions imperfect or perfect
*/

#include <stdlib.h>
#include <time.h>
#include "generator.h"

static
void
make_maze_imperfect_global_region(draw_maze_t *draw_maze,
generator_maze_t *generator_maze)
{
	if (draw_maze->maze_container[draw_maze->rand_y]
	[draw_maze->rand_x] == 'X'
	&& draw_maze->maze_container[draw_maze->rand_y]
	[draw_maze->rand_x + 1] == '*'
	&& draw_maze->maze_container[draw_maze->rand_y]
	[draw_maze->rand_x - 1] == '*'
	&& draw_maze->maze_container[draw_maze->rand_y - 1]
	[draw_maze->rand_x] == 'X') {
		draw_maze->maze_container[draw_maze->rand_y]
		[draw_maze->rand_x] = '*';
		generator_maze->get_random--;
	} else {
		draw_maze->rand_x = (random() %
		((draw_maze->x - 2)
		- 0 + 1) + 0);
		draw_maze->rand_y = (random() %
		((draw_maze->y - 2)
		- 0 + 1) + 0);
	}
}

static
void
make_maze_imperfect_x_boundary_region(draw_maze_t *draw_maze,
generator_maze_t *generator_maze)
{
	if (draw_maze->maze_container[draw_maze->y - 1]
	[draw_maze->rand_x - 2] == 'X'
	&& draw_maze->maze_container[draw_maze->y - 2]
	[draw_maze->rand_x - 2] == 'X') {
		draw_maze->maze_container[draw_maze->y - 1]
		[draw_maze->rand_x - 2] = '*';
		generator_maze->get_random--;
	} else {
		draw_maze->rand_x = (random() %
		((draw_maze->x - 2) - 0 + 1) + 0);
		draw_maze->rand_y = (random() %
		((draw_maze->y - 2) - 0 + 1) + 0);
		generator_maze->get_random--;
	}
}

static
void
make_maze_imperfect_y_boundary_region(draw_maze_t *draw_maze,
generator_maze_t *generator_maze)
{
	if (draw_maze->maze_container[draw_maze->rand_y]
	[draw_maze->x - 1] == 'X'
	&& draw_maze->maze_container[draw_maze->rand_y]
	[draw_maze->x - 2] == 'X') {
		draw_maze->maze_container[draw_maze->rand_y]
		[draw_maze->x - 1] = '*';
		generator_maze->get_random--;
	} else {
		draw_maze->rand_x = (random() %
		((draw_maze->x - 2)
		- 0 + 1) + 0);
		draw_maze->rand_y = (random() %
		((draw_maze->y - 2)
		- 0 + 1) + 0);
		generator_maze->get_random--;
	}
}

extern
void
make_maze_imperfect(draw_maze_t *draw_maze,
generator_maze_t *generator_maze)
{
	draw_maze->rand_x = (random() %
	((draw_maze->x - 2)
	- 0 + 1) + 0);
	draw_maze->rand_y = (random() %
	((draw_maze->y - 2)
	- 0 + 1) + 0);
	generator_maze->get_random = draw_maze->x / 2;
	while (generator_maze->get_random != 0 &&
	draw_maze->imperfect == true) {
		make_maze_imperfect_global_region(draw_maze,
		generator_maze);
	}
	generator_maze->get_random = draw_maze->x * 2;
	while (generator_maze->get_random != 0 &&
	draw_maze->imperfect == true) {
		make_maze_imperfect_x_boundary_region(draw_maze,
		generator_maze);
		make_maze_imperfect_y_boundary_region(draw_maze,
		generator_maze);
	}
}

extern
void
make_maze_really_really_perfect(draw_maze_t *draw_maze)
{
	if (draw_maze->x % 2 == 1) {
		draw_maze->maze_container[(draw_maze->y) - 2]
		[(draw_maze->x) - 1] = '*';
		draw_maze->maze_container[(draw_maze->y) - 1]
		[(draw_maze->x) - 2] = 'X';
	}
	if (draw_maze->x % 2 == 0) {
		draw_maze->maze_container[(draw_maze->y) - 1]
		[(draw_maze->x) - 1] = '*';
		draw_maze->maze_container[(draw_maze->y) - 1]
		[(draw_maze->x) - 2] = '*';
	}
	if (draw_maze->y % 2 == 0) {
		draw_maze->maze_container[(draw_maze->y) - 1]
		[(draw_maze->x) - 1] = '*';
	}
}
