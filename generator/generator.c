/*
** EPITECH PROJECT, 2018
** generator
** File description:
** generator
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "generator.h"

static void maze_generator(draw_maze_t *draw_maze,
generator_maze_t *generator_maze)
{
	auto unsigned long i = 0;
	auto unsigned long j = 0;

	srandom(time(NULL));
	for (j = 0;j < draw_maze->x;j = j + 1) {
		if (draw_maze->maze_container[0][j] == 'X' &&
			draw_maze->maze_container[0][j + 1] != '\n')
			draw_maze->maze_container[0][j] = '*';
	}
	for (i = 2;i < draw_maze->y;i = i + 2) {
		generator_maze->run_set = 0;
		generator_maze->track_cell = 0;
		generator_maze->trigger = true;
		browse_row(draw_maze,
		generator_maze, i, j);
	}
	make_maze_really_really_perfect(draw_maze);
	make_maze_imperfect(draw_maze, generator_maze);
}

static char **draw_map(char **av, draw_maze_t *draw_maze)
{
	volatile unsigned long i = 0;
	volatile unsigned long j = 0;

	draw_maze->x = atol(av[1]);
	draw_maze->y = atol(av[2]);
	draw_maze->maze_container = malloc(sizeof(char) *
	(draw_maze->y * draw_maze->x) * 3);
	for (i = 0;i < draw_maze->y;i++) {
		draw_maze->maze_container[i] = malloc(sizeof(char) *
		(draw_maze->x) + 2);
		for (j = 0;j < draw_maze->x;j++) {
			draw_maze->maze_container[i][j] = 'X';
			(int)j % 2 == 0 && (int)i % 2 == 0?
		draw_maze->maze_container[i][j] = '*' : 0;
		}
		add_back_slash_0_and_n(draw_maze, (int)i, (int)j);
	}
	draw_maze->maze_container[i] = NULL;
	return (draw_maze->maze_container);
}

static bool error_handle_dante(int ac, char **av, generator_t *generator)
{
	if (av[3] != NULL && strcmp(av[3], "perfect") == 0)
		generator->draw_maze->imperfect = false;
	else if (av[3] != NULL && strcmp(av[3], "perfect") != 0) {
		printf("./generator x y [perfect]\n");
		return (1);
	}
	else {
		if (ac <= 2) {
			printf("./generator x y [perfect]\n");
			return (1);
		}
	}
	return (0);
}

static void to_print_2d_array_dynamic_unsigned_long(char **array)
{
	for (long unsigned k = 0;array[k] != NULL;k++) {
		printf("%s", array[k]);
	}
}

int main(int ac, char **av)
{
	generator_t generator;

	generator.draw_maze = malloc(sizeof(draw_maze_t) * 3);
	generator.draw_maze->imperfect = true;
	if (error_handle_dante(ac, av, &generator) == 1)
		return (84);
	generator.draw_maze->maze_container = \
	draw_map(av, generator.draw_maze);
	maze_generator(generator.draw_maze, &(generator.generator_maze));
	to_print_2d_array_dynamic_unsigned_long(generator.
	draw_maze->maze_container);
	free(generator.draw_maze);
	free(generator.draw_maze->maze_container);
	return (0);
}
