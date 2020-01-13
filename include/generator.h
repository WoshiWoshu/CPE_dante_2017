/*
** EPITECH PROJECT, 2018
** generator header
** File description:
** generator header
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_
#include <stdbool.h>

typedef struct draw_maze_s
{
	volatile unsigned long x;
	volatile unsigned long y;
	bool imperfect;
	int rand_x;
	int rand_y;
	char **maze_container;
} draw_maze_t;

typedef struct generator_maze_s
{
	int get_random;
	int run_set;
	int run_set_opt;
	int track_cell;
	bool trigger;
} generator_maze_t;

typedef struct generator_s
{
	draw_maze_t *draw_maze;
	generator_maze_t generator_maze;
} generator_t;

extern float dig_up_last_row(draw_maze_t *draw_maze,
generator_maze_t *generator_maze,
unsigned long i,
unsigned long j);
extern generator_maze_t *dig_up(draw_maze_t *draw_maze,
generator_maze_t *generator_maze,
unsigned long i,
unsigned long j);
extern generator_maze_t *dig_right(draw_maze_t *draw_maze,
generator_maze_t *generator_maze,
unsigned long i,
unsigned long j);
extern int browse_row(draw_maze_t *draw_maze, generator_maze_t *generator_maze,
unsigned long i,
unsigned long j);
extern void make_maze_really_really_perfect(draw_maze_t *draw_maze);
extern void make_maze_imperfect(draw_maze_t *draw_maze,
generator_maze_t *generator_maze);
extern void add_back_slash_0_and_n(draw_maze_t *draw_maze, int i, int j);
#endif /* GENERATOR_H_ */
