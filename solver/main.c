/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "solve.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i])
		i = i + 1;
	return (i);
}

static void print_maze(char *str, int i, int max)
{
	for (int j = 0; str[j]; j++) {
		if (str[j] == 'p')
			printf("o");
		else if (str[j] == 'q')
			printf("*");
		else
			printf("%c", str[j]);
	}
	if (i == max)
		return;
	else
		printf("\n");
}

static maze_t init_struct(char **av)
{
	maze_t mz;
	int i = 0;

	mz.error = 0;
	mz.prev_x = 0;
	mz.arr = get_dir(av[1]);
	if (mz.arr == NULL)
		mz.error++;
	for (; mz.arr[i]; i++);
	mz.y = i;
	mz.max_y = mz.y;
	mz.x = my_strlen(mz.arr[0]);
	mz.max_x = mz.x;
	mz.prev_y = 0;
	return (mz);
}

int main(int ac, char **av)
{
	maze_t maze;

	if (ac != 2)
		return (84);
	maze = init_struct(av);
	if (maze.error > 0)
		return (84);
	maze.x = maze.x - 1;
	maze.y = maze.y - 1;
	solve_maze(&maze);
	if (maze.error > 0) {
		printf("No solution found\n");
		return (84);
	}
	for (int i = 0; maze.arr[i]; i++)
		print_maze(maze.arr[i], i, maze.max_y - 1);
	return (0);
}
