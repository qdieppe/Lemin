/*
** EPITECH PROJECT, 2018
** backtrack.c
** File description:
** backtrack
*/

#include "my.h"

char **split_to_str(char **room_table)
{
	unsigned int i = 0;
	char **new_str = malloc(sizeof(char *) * 2);

	new_str[0] = "\0";
	new_str[1] = NULL;
	while (room_table[i] != NULL) {
		if (i > 0)
			*new_str = alloc_add(*new_str, "-");
		*new_str = alloc_add(*new_str, room_table[i]);
		i = i + 1;
	}
	return (new_str);
}

char **craft_new_room_table(char **room_table, char *room)
{
	return (add_str(room_table, room));
}

void print_ret(char **ret)
{
	unsigned int i = 0;

	if (ret == NULL) {
		my_putstr("RET is NULL\n");
		return;
	}
	while (ret[i] != NULL) {
		my_putstr(ret[i]);
		my_putchar('\n');
		i = i + 1;
	}
}

char **backtrack(struct data *pdata, char *current,
	char *room, char **room_table)
{
	unsigned int i = 0;
	char **ret = NULL;
	char *new_room = NULL;

	room_table = craft_new_room_table(room_table, room);
	if (my_strcmp(room, pdata->end_room) == 0)
		return (split_to_str(room_table));
	while (pdata->tmp_tunnels[i] != NULL) {
		if (is_linked(pdata->tmp_tunnels[i], room) && !is_used(pdata,
			pdata->tmp_tunnels[i], current, room)) {
			new_room = make_new_room(pdata->tmp_tunnels[i], room);
			ret = add_to_ret(ret, backtrack(pdata,
				make_new_current(pdata, current, new_room),
				new_room, room_table));
		}
		i = i + 1;
	}
	return (ret);
}