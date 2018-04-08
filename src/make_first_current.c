/*
** EPITECH PROJECT, 2018
** backtrack.c
** File description:
** backtrack
*/

#include "my.h"

char *make_first_current(struct data *pdata, char *start)
{
	unsigned int i = 0;
	unsigned int size = get_table_size(pdata->tmp_only_rooms);
	char *current = malloc(size);

	while (i < size) {
		if (my_strcmp(pdata->tmp_only_rooms[i], start) == 0)
			current[i] = 1;
		else
			current[i] = 0;
		i = i + 1;
	}
	return (current);
}