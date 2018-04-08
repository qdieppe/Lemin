/*
** EPITECH PROJECT, 2018
** backtrack_utils_1.c
** File description:
** backtrack_utila_1.c
*/

#include "my.h"

char *make_new_current(struct data *pdata, char *current, char *room)
{
	unsigned int i = 0;
	unsigned int y = 0;
	unsigned int size = get_table_size(pdata->tmp_only_rooms);
	char *newcurrent = malloc(size);

	while (y < size) {
		newcurrent[y] = current[y];
		y = y + 1;
	}
	while (pdata->tmp_only_rooms[i] != NULL) {
		if (my_strcmp(pdata->tmp_only_rooms[i], room) == 0) {
			newcurrent[i] = 1;
			break;
		}
		i = i + 1;
	}
	return (newcurrent);
}

char **add_str(char **ret, char *other)
{
	unsigned int i = 0;
	char **new_str = NULL;
	unsigned int size;

	if (ret == NULL) {
		ret = malloc(sizeof(char *) * 2);
		ret[0] = my_strdup(other);
		ret[1] = NULL;
		return (ret);
	}
	size = get_table_size(ret);
	new_str = (char **) malloc(sizeof(char *) * (size + 2));
	new_str[size + 1] = NULL;
	while (i < size) {
		new_str[i] = ret[i];
		i = i + 1;
	}
	new_str[i] = my_strdup(other);
	return (new_str);
}

char **add_to_ret(char **ret, char **other)
{
	unsigned int i = 0;

	if (other == NULL)
		return (ret);
	while (other[i] != NULL) {
		ret = add_str(ret, other[i]);
		i = i + 1;
	}
	return (ret);
}

char *alloc_add(char *str, char *str2)
{
	int i = 0;
	int y = 0;
	int size1 = my_strlen(str);
	int size2 = my_strlen(str2);
	int N = size1 + size2;
	char *new_str = malloc(sizeof(char *) * (size1 + size2 + 1));

	new_str[size1 + size2] = 0;
	while (i < size1) {
		new_str[i] = str[i];
		i = i + 1;
	}
	while (i < N) {
		new_str[i] = str2[y];
		i = i + 1;
		y = y + 1;
	}
	return (new_str);
}