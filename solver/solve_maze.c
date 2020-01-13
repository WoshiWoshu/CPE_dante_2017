/*
** EPITECH PROJECT, 2018
** solve_maze
** File description:
** solve_maze
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "solve.h"

static int get_stuck_conditions(maze_t *mz)
{
	if ((mz->x < mz->max_x - 1 && mz->arr[mz->y][mz->x + 1] == '*')
		|| (mz->x > 0 && mz->arr[mz->y][mz->x - 1] == '*')
		|| (mz->y < mz->max_y - 1 && mz->arr[mz->y + 1][mz->x] == '*')
		|| (mz->y > 0 && mz->arr[mz->y - 1][mz->x] == '*'))
		return (0);
	else
		return (1);
}

static void go_to_next_room(maze_t *mz)
{
	if (mz->x != 0 && mz->arr[mz->y][mz->x - 1] == '*') {
		for (; mz->x != 0 && mz->arr[mz->y][mz->x - 1] == '*'; mz->x--)
			change_char_in_array(mz, 'p');
		return;
	}
	if (mz->y + 1 != mz->max_y && mz->arr[mz->y + 1][mz->x] == '*') {
		for (; mz->y + 1 != mz->max_y
			&& mz->arr[mz->y + 1][mz->x] == '*'; mz->y++)
			change_char_in_array(mz, 'p');
		return;
	}
	if (mz->y != 0 && mz->arr[mz->y - 1][mz->x] == '*') {
		for (; mz->y != 0 && mz->arr[mz->y - 1][mz->x] == '*'; mz->y--)
			change_char_in_array(mz, 'p');
		return;
	}
	if (mz->x + 1 != mz->max_x && mz->arr[mz->y][mz->x + 1] == '*')
		for (; mz->x + 1 != mz->max_x
			&& mz->arr[mz->y][mz->x + 1] == '*'; mz->x++)
			change_char_in_array(mz, 'p');
}

static void do_backtracking(maze_t *mz)
{
	mz->arr[mz->y][mz->x] = 'q';
	mz->x = mz->prev_x;
	mz->y = mz->prev_y;
	for (; mz->x != 0 && get_stuck_conditions(mz) == 1
		&& mz->arr[mz->y][mz->x - 1] == 'p'; mz->x--)
		change_char_in_array(mz, 'q');
	for (; mz->y + 1 != mz->max_y && get_stuck_conditions(mz) == 1
		&& mz->arr[mz->y + 1][mz->x] == 'p'; mz->y++)
		change_char_in_array(mz, 'q');
	for (; mz->y != 0 && get_stuck_conditions(mz) == 1
		&& mz->arr[mz->y - 1][mz->x] == 'p'; mz->y--)
		change_char_in_array(mz, 'q');
	for (; mz->x + 1 != mz->max_x && get_stuck_conditions(mz) == 1
		&& mz->arr[mz->y][mz->x + 1] == 'p'; mz->x++)
		change_char_in_array(mz, 'q');
}

static bool solve_maze_get_error(maze_t *mz)
{
	if (mz->arr[mz->y - 1][mz->x] == 'X'
	&& mz->arr[mz->y][mz->x - 1] == 'X') {
		mz->error = mz->error + 1;
		return (1);
	}
	return (0);
}

void solve_maze(maze_t *mz)
{
	if (solve_maze_get_error(mz) == 1)
		return;
	while ((mz->x > 0 || mz->y > 0)
	&& (mz->x != mz->prev_x || mz->y != mz->prev_y)) {
		while (get_stuck_conditions(mz) == 1
		&& (mz->x != 0 || mz->y != 0)
		&& (mz->x != mz->max_x - 1 || mz->y != mz->max_y - 1)) {
			mz->arr[mz->y][mz->x] = 'q';
			do_backtracking(mz);
			mz->prev_x = mz->x;
			mz->prev_y = mz->y;
		}
		mz->arr[mz->y][mz->x] = 'p';
		go_to_next_room(mz);
		mz->arr[mz->y][mz->x] = 'p';
	}
	if (mz->x != 0 || mz->y != 0)
		mz->error++;
}
