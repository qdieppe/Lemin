/*
** EPITECH PROJECT, 2018
** backtrack.c
** File description:
** backtrack
*/

#include "my.h"

void make_links_main(struct room *rooms, struct room *linked_room)
{
	int tmp = 0;

	if (linked_room != NULL) {
		tmp = 1 + rooms->min_value;
		if (linked_room->min_value == -1) {
			linked_room->min_value = tmp;
			linked_room->prev = rooms->name;
		}
		if (linked_room->min_value > tmp) {
			linked_room->min_value = tmp;
			linked_room->prev = rooms->name;
		}
	}
}

void make_links(struct data *pdata, struct room *rooms,
	struct room *multirooms, int size)
{
	unsigned int i = 0;
	char *name = NULL;
	struct room *linked_room = NULL;

	while (pdata->tmp_tunnels[i] != NULL) {
		if (is_linked(pdata->tmp_tunnels[i], rooms->name)) {
			name = get_room_name(pdata->tmp_tunnels[i],
				rooms->name);
			linked_room = get_room_named(name, multirooms, size);
			make_links_main(rooms, linked_room);
		}
		i = i + 1;
	}
}

char **reverse_table(char **table)
{
	unsigned int i = 0;
	unsigned int size = get_table_size(table);
	unsigned int N = size - 1;
	char **new_table = malloc(sizeof(char *) * (size + 1));

	new_table[size] = NULL;
	while (i < size) {
		new_table[N] = table[i];
		i = i + 1;
		N--;
	}
	return (new_table);
}

char **make_dijkstra(struct data *pdata, struct room *rooms, int size)
{
	unsigned int i = 0;
	struct room *endroom = get_room_named(pdata->end_room, rooms, size);
	char **table = NULL;

	while (endroom->prev != NULL) {
		table = add_str(table, endroom->name);
		endroom = get_room_named(endroom->prev, rooms, size);
		i = i + 1;
	}
	table = add_str(table, endroom->name);
	i = 0;
	return (split_to_str(reverse_table(table)));
}

char **dijkstra(struct data *pdata)
{
	unsigned int i = 0;
	struct room *this = NULL;
	struct room *rooms = init_room_table(pdata);
	int size = get_table_size(pdata->tmp_only_rooms);

	while ((this = get_next_room(rooms, size)) != NULL) {
		this->visited = 1;
		make_links(pdata, this, rooms, size);
		i = i + 1;
	}
	return (make_dijkstra(pdata, rooms, size));
}