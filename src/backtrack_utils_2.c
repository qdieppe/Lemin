/*
** EPITECH PROJECT, 2018
** backtrack_utils_1.c
** File description:
** backtrack_utila_1.c
*/

#include "my.h"

char *get_tested_room(char **new_room, char *room)
{
	if (my_strcmp(new_room[0], room) == 0)
		return (new_room[0]);
	return (new_room[1]);
}

int is_used(struct data *pdata, char *str, char *current, char *room)
{
	unsigned int i = 0;

	while (pdata->tmp_only_rooms[i] != NULL) {
		if (my_strcmp(room, pdata->tmp_only_rooms[i]) != 0 &&
			is_linked(str, pdata->tmp_only_rooms[i]))
			if (current[i] == 1)
				return (1);
		i = i + 1;
	}
	return (0);
}

int is_linked(char *str, char *room)
{
	unsigned int i = 0;
	char *dup = my_strdup(str);
	char *keep1 = dup;
	char *keep2 = NULL;

	while (str[i] != '-')
		i++;
	dup[i] = 0;
	keep2 = &(dup[i + 1]);
	if (my_strcmp(keep1, room) == 0 || my_strcmp(keep2, room) == 0)
		return (1);
	return (0);
}

char *make_new_room(char *tunnel, char *room)
{
	char **new_room = malloc(sizeof(char *) * 3);

	new_room[2] = NULL;
	new_room = craft_new_rooms(tunnel, new_room);
	if (my_strcmp(new_room[0], room) != 0)
		return (new_room[0]);
	else
		return (new_room[1]);
}