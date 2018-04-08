/*
** EPITECH PROJECT, 2018
** utils_4.c
** File description:
** utils_4.c
*/

#include "my.h"

int my_show_array(char **tab)
{
	int i = 0;

	if (!tab) {
		my_putstr("TABLEAUX VIDE\n");
		return (84);
	}
	while (tab[i] != NULL) {
		my_putstr(tab[i]);
		my_putchar('\n');
		i++;
	}
	return (0);
}

int my_is_num(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
			return (-1);
		i++;
	}
	return (0);
}

int my_has_char(char *str, char c)
{
	int i = 0;
	int j = 0;

	if (!*str || str == NULL) {
		return (0);
	}
	while (str[i] != '\0') {
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}

void *to_zero(void *data, int q)
{
	int i = 0;

	for (i = 0; i < q; i++) {
		((char *)data)[i] = 0;
	}
	return (data);
}

void *my_calloc(int q)
{
	void *data = malloc(q);

	data = to_zero(data, q);
	return (data);
}
