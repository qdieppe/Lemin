/*
** EPITECH PROJECT, 2018
** backtrack_utils_3.c
** File description:
** backtrack_utils_3.c
*/

#include "my.h"

int my_memset(void *data, int size, int value)
{
	int i = 0;
	char *my_data = data;

	while (i < size) {
		*(my_data + i) = value;
		i = i + 1;
	}
	return (1);
}

unsigned int get_table_size(char **ret)
{
	unsigned int i = 0;

	while (ret[i] != NULL) {
		i = i + 1;
	}
	return (i);
}

int check_str(char *dest, char *str)
{
	int i = 0;

	while (dest[i] == str[i] && dest[i] != 0 && str[i] != 0)
		i = i + 1;
	if (str[i] == 0)
		return (1);
	return (0);
}

int my_strstr(char *dest, char *search)
{
	int size_dest = my_strlen(dest);
	int size_search = my_strlen(search);
	int i = 0;

	if (size_search > size_dest)
		return (0);
	while (i < size_dest) {
		if (check_str(&(dest[i]), search))
			return (1);
		i = i + 1;
	}
	return (0);
}

char **craft_new_rooms(char *tunnel, char **new_room)
{
	unsigned int i = 0;
	char *my_tunnel = my_strdup(tunnel);

	while (my_tunnel[i] != '-')
		i = i + 1;
	my_tunnel[i] = 0;
	new_room[0] = my_tunnel;
	new_room[1] = my_tunnel + i + 1;
	return (new_room);
}