/*
** EPITECH PROJECT, 2018
** solve
** File description:
** solve
*/

#ifndef SOLVE_H_
#define SOLVE_H_

typedef struct maze_s {
	int max_x;
	int max_y;
	int x;
	int y;
	char **arr;
	int prev_x;
	int prev_y;
	int error;
} maze_t;

void change_char_in_array(maze_t *mz, char c);
void solve_maze(maze_t *mz);
char **get_dir(char const *filename);
int my_strlen(char const *filename);
char *get_next_line(int fd);

#endif /* SOLVE_H_ */
