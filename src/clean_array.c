/*
** EPITECH PROJECT, 2018
** clean_array.c
** File description:
** clean_array.c
*/

#include "my.h"

char **clean_array_norm_2(char **tab, int i)
{
	for (; tab[i] != NULL && tab[i][0] != '\0'; i++)
		tab[i] = tab[i + 1];
	return (tab);
}

char **clean_array_norm_1(char **tab, int i, int j)
{
	if (tab[i][j] == '#' && tab[i][j+ 1] != '#' &&
		my_strcmp(tab[i], "##start") != 0 &&
		my_strcmp(tab[i], "##end") != 0) {
		tab[i][j] = '\0';
		tab[i] = clear_str(tab[i]);
	}
	return (tab);
}

char **clean_array(char **tab)
{
	int i = 0;
	int j = 0;

	for (i = 0; tab[i] != NULL && tab[i][0] != '\0'; i++, j = 0)
		for (j = 0; tab[i][j] != '\0'; j++)
			tab = clean_array_norm_1(tab, i, j);
	for (i = 0, j = 0; tab[i] != NULL && tab[i][0] != '\0'; i++)
		if (tab[i][j] == '\0')
			return (clean_array_norm_2(tab, i));
	return (tab);
}

char **clear_tunnels(char **tab)
{
	int i = 0;
	char **mdr = NULL;

	while (tab[i] != NULL) {
		mdr = str_to_word_tab(tab[i], '-');
		if (my_strcmp(mdr[0], mdr[1]) == 0) {
			tab[i][0] = '\0';
		}
		i++;
	}
	tab = clean_void_line(tab);
	return (tab);
}

char **sort(char **tab)
{
	int i = 0;
	char *good = my_calloc(sizeof(char) * 1);
	char *tmp = NULL;

	good = "-----------------------------------------"
	"-------------------------------------------------"
	"-------------------------------------------------"
	"-------------------------------------------------\n";
	while (tab[i] != NULL) {
		tmp = my_strdup(tab[i]);
		if (my_has_char(tab[i], '-') < my_has_char(good, '-')) {
			good = my_strdup(tmp);
		}
		i++;
	}
	tab[0] = my_strdup(good);
	return (tab);
}