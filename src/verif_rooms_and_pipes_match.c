/*
** EPITECH PROJECT, 2018
** verif_rooms_and_pipes_match.c
** File description:
** verif_rooms_and_pipes_match.c
*/

#include "my.h"

int if_same_name(data *pdata)
{
	int i = 0;
	int j = 0;
	char **tab = NULL;
	char **copy = NULL;
	int nb_match = 0;

	select_only_rooms(pdata);
	tab = pdata->tmp_only_rooms;
	for (i = 0; tab[i] != NULL; i++);
	copy = my_calloc(sizeof(char *) * (i + 1));
	for (i = 0; tab[i] != NULL; copy[i] = my_strdup(tab[i]), i++);
	copy[i] = NULL;
	for (i = 0; tab[i] != NULL; i++, nb_match = 0, j = 0) {
		for (j = 0; copy[j] != NULL; j++)
			if (my_strcmp(tab[i], copy[j]) == 0)
				nb_match++;
		if (nb_match > 1)
			return (84);
	}
	return (0);
}

char **clean_void_line(char **tab)
{
	int i = 0;
	int j = 0;
	char **tmp = NULL;

	for (i = 0; tab[i] != NULL; i++);
	tmp = my_calloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tab[i] != NULL) {
		if (tab[i][0] != '\0') {
			tmp[j] = my_strdup(clear_str(tab[i]));
			j++;
		}
		i++;
	}
	tmp[j] = NULL;
	return (tmp);
}

int verif_rooms_and_pipes_match(data *pdata)
{
	pdata->tmp_rooms = clean_array(pdata->tmp_rooms);
	pdata->tmp_rooms = clean_void_line(pdata->tmp_rooms);
	if (if_same_name(pdata) == 84)
		return (84);
	return (0);
}