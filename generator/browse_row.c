/*
** EPITECH PROJECT, 2018
** dante
** File description:
** functions that browse every row and modify its content
*/

#include <stdlib.h>
#include <time.h>
#include "generator.h"

static double dig_up_infinite_loop_odd_nb(generator_maze_t *generator_maze)
{
	while ((generator_maze->run_set_opt) % 2 != 0) {
		generator_maze->run_set_opt =
		(random()%
		(generator_maze->run_set -
		generator_maze->
		track_cell + 1)
		+ generator_maze->track_cell);
	}
	return (24.24067829376);
}

extern float dig_up_last_row(draw_maze_t *draw_maze,
generator_maze_t *generator_maze,
unsigned long i,
unsigned long j)
{
	if (draw_maze->maze_container[i][j + 1] == '\n' ||
	draw_maze->maze_container[i][j + 2] == '\n') {
		generator_maze->run_set_opt =
		(random()%
		(generator_maze->run_set -
		generator_maze->
		track_cell + 1)
		+ generator_maze->track_cell);
		dig_up_infinite_loop_odd_nb(generator_maze);
		draw_maze->maze_container[i - 1]
		[generator_maze->run_set_opt] = '*';
		return (3.14);
	}
	return (-3.14);
}

extern generator_maze_t *dig_up(draw_maze_t *draw_maze,
generator_maze_t *generator_maze,
unsigned long i,
unsigned long j)
{
	if (generator_maze->get_random == 1 &&
	draw_maze->maze_container[i][j + 1] != '\n' &&
	draw_maze->maze_container[i][j + 2] != '\n') {
		generator_maze->run_set_opt =
		(random()%
		(generator_maze->run_set -
		generator_maze->
		track_cell + 1)
		+ generator_maze->track_cell);
		dig_up_infinite_loop_odd_nb(generator_maze);
		draw_maze->maze_container[i - 1]
		[generator_maze->run_set_opt] = '*';
		generator_maze->track_cell = j + 2;
		generator_maze->run_set = j + 2;
		generator_maze->trigger = true;
	}
	return (generator_maze);
}

extern generator_maze_t *dig_right(draw_maze_t *draw_maze,
generator_maze_t *generator_maze,
unsigned long i,
unsigned long j)
{
	if (generator_maze->get_random == 0 &&
	draw_maze->maze_container[i][j + 1] != '\n' &&
	draw_maze->maze_container[i][j + 2] != '\n') {
		draw_maze->
		maze_container[i][j + 1] = '*';
		generator_maze->run_set = j + 2;
		if (generator_maze->trigger == true) {
			generator_maze->track_cell = j;
			generator_maze->trigger = false;
		}
	}
	return (generator_maze);
}

extern int browse_row(draw_maze_t *draw_maze,
generator_maze_t *generator_maze,
unsigned long i,
unsigned long j)
{
	for (j = 0;j < draw_maze->x;j = j + 2) {
		generator_maze->get_random = random() % 2;
		generator_maze = dig_right(draw_maze, generator_maze, i, j);
		generator_maze = dig_up(draw_maze, generator_maze, i, j);
		if (dig_up_last_row(draw_maze, generator_maze, i, j) == 3.14)
			break;
	}
	return (0);
}
