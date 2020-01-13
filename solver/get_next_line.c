/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** GNL
*/

#include "solve.h"
#include <unistd.h>
#include <stdlib.h>

static char save[10];

char *realloc_this(char *str, int i)
{
	char *str2;
	int j = 0;

	if (str == NULL) {
		str2 = malloc(sizeof(char) * (i + 2));
		str2[i] = '\0';
		return (str2);
	} else if (i == 0) {
		return (str);
	} else {
		str2 = malloc(sizeof(char) * (10 + i + 2));
		while (j < i) {
			str2[j] = str[j];
			j = j + 1;
		}
		str2[j] = '\0';
		free(str);
		return (str2);
	}
}

char *save_chars(char *straux, int i)
{
	int k = 0;

	i = i + 1;
	while (straux[i] != '\0') {
		save[k] = straux[i];
		k = k + 1;
		i = i + 1;
	}
	save[k] = '\0';
	return (straux);
}

char *fill_line(char *str, char *straux, int size, int fd)
{
	int i = 0;
	int j = my_strlen(str);

	while (straux[i] != '\n' && size != 0) {
		if (i == my_strlen(straux)) {
			str = realloc_this(str, j);
			size = read(fd, straux, 10);
			straux[size] = '\0';
			i = 0;
			j = my_strlen(str);
		} else {
			str[j] = straux[i];
			str[j + 1] = '\0';
			j = j + 1;
			i = i + 1;
		}
	}
	if (size != 0)
		straux = save_chars(straux, i);
	return (str);
}

char *fill_str(char *str)
{
	int p = 0;

	if (save[0] != '\0') {
		while (save[p]) {
			str[p] = save[p];
			p = p + 1;
		}
	}
	str[p] = '\0';
	return (str);
}

char *get_next_line(int fd)
{
	char *str = malloc(sizeof(char) * (10 + 1));
	char *straux = malloc(sizeof(char) * (10 + 1));
	int size = read(fd, straux, 10);

	if (fd == -1)
		return (NULL);
	if (str == NULL && straux == NULL && save[0] == '\0')
		return (NULL);
	str = fill_str(str);
	save[0] = '\0';
	straux[size] = '\0';
	if (size == 0 && my_strlen(str) == 0)
		return (NULL);
	if (size != 0) {
		str = realloc_this(str, my_strlen(str));
		str = fill_line(str, straux, size, fd);
	}
	free(straux);
	return (str);
}
