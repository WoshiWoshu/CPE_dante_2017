/*
** EPITECH PROJECT, 2018
** dante
** File description:
** added back slash n and 0 at the end
*/

#include "generator.h"

extern void add_back_slash_0_and_n(draw_maze_t *draw_maze, int i, int j)
{
	if (i != (int)draw_maze->y - 1) {
		draw_maze->maze_container[i][j] = '\n';
		draw_maze->maze_container[i][j + 1] = '\0';
	} else {
		draw_maze->maze_container[i][j] = '\0';
	}
}
