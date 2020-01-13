/*
** EPITECH PROJECT, 2018
** get_map
** File description:
** get_the_map
*/

#include <fcntl.h>
#include <stdlib.h>
#include "solve.h"

static char **my_realloc(char **buff, int j)
{
	char **new_buff = malloc(sizeof(char *) * (j + 1));
	int i = 0;

	j = 0;
	while (buff[i]) {
		new_buff[i] = malloc(sizeof(char) * (my_strlen(buff[i]) + 1));
		while (buff[i][j] != '\0') {
			new_buff[i][j] = buff[i][j];
			j = j + 1;
		}
		new_buff[i][j] = '\0';
		j = 0;
		i = i + 1;
	}
	new_buff[i] = NULL;
	return (new_buff);
}

char **get_dir(char const *filename)
{
	int fd = open(filename, O_RDONLY);
	int j = 2;
	char **arr = malloc(sizeof(char *) * j);
	int i = 0;

	if (arr == NULL || fd == -1)
		return (NULL);
	arr[0] = NULL;
	arr[1] = NULL;
	while ((arr[i] = get_next_line(fd)) != NULL) {
		arr = my_realloc(arr, j);
		i = i + 1;
		j = j + 1;
		arr[j - 1] = NULL;
	}
	return (arr);
}

void change_char_in_array(maze_t *mz, char c)
{
	mz->arr[mz->y][mz->x] = c;
	mz->prev_x = mz->x;
	mz->prev_y = mz->y;
}
