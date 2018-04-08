/*
** EPITECH PROJECT, 2018
** dijkstra_utils.c
** File description:
** dijkstra_utils.c
*/

#include "my.h"

struct room *get_room_named(char *name, struct room *rooms, int size)
{
	int i = 0;

	while (i < size) {
		if (my_strcmp(rooms[i].name, name) == 0)
			return (&(rooms[i]));
		i = i + 1;
	}
	return (NULL);
}

struct room *init_room_table(struct data *pdata)
{
	unsigned int i = 0;
	unsigned int size = get_table_size(pdata->tmp_only_rooms);
	struct room *rooms = malloc(sizeof(struct room) * size);
	struct room *swap = NULL;

	while (i < size) {
		rooms[i].name = my_strdup(pdata->tmp_only_rooms[i]);
		rooms[i].prev = NULL;
		rooms[i].min_value = -1;
		rooms[i].visited = 0;
		i = i + 1;
	}
	swap = get_room_named(pdata->start_room, rooms, size);
	swap->name = rooms->name;
	rooms->name = my_strdup(pdata->start_room);
	rooms->min_value = 0;
	rooms->visited = 0;
	return (rooms);
}

struct room *get_next_room(struct room *rooms, int size)
{
	int i = 0;

	while (i < size) {
		if (rooms[i].visited == 0 && rooms[i].min_value != -1) {
			rooms[i].visited = 1;
			return (&(rooms[i]));
		}
		i = i + 1;
	}
	return (NULL);
}

char *get_room_name(char *str, char *self)
{
	unsigned int i = 0;
	char *dup = my_strdup(str);
	char *keep1 = dup;
	char *keep2 = NULL;

	while (str[i] != '-')
		i++;
	dup[i] = 0;
	keep2 = &(dup[i + 1]);
	if (my_strcmp(keep1, self) == 0)
		return (keep2);
	else
		return (keep1);
}