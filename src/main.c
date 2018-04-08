/*
** EPITECH PROJECT, 2018
** navy.c
** File description:
** navy.c
*/

#include "my.h"

void select_only_rooms(data *pdata)
{
	int i = 0;
	int j = 0;
	char **tab = pdata->tmp_rooms;
	char **tmp = pdata->tmp_only_rooms;
	char **mdr = NULL;

	for (i = 0; tab[i] != NULL; i++);
	tmp = my_calloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tab[i] != NULL) {
		if (tab[i][0] != '#') {
			mdr = str_to_word_tab(tab[i], ' ');
			tmp[j] = my_strdup(mdr[0]);
			free(mdr);
			j++;
		}
		i++;
	}
	tmp[i] = NULL;
	pdata->tmp_only_rooms = tmp;
}

int get_file_and_parse(data *pdata, char **av)
{
	init_data_struct(pdata);
	if (get_file(pdata, av) == 84)
		return (84);
	if (verif_file(pdata) == 84) {
		my_putstr("PARSING ERROR\n");
		return (84);
	}
	select_only_rooms(pdata);
	if (verif_rooms_and_pipes_match(pdata) == 84) {
		my_putstr("PARSING ERROR\n");
		return (84);
	}
	if (*pdata->tmp_rooms == NULL || *pdata->tmp_tunnels == NULL)
		return (84);
	return (0);
}

void my_free(data *pdata)
{
	free_word_tab(pdata->tmp_rooms);
	free_word_tab(pdata->tmp_tunnels);
	free_word_tab(pdata->file_copy);
	free(pdata->room_name);
	free(pdata->start_room);
	free(pdata->end_room);
	free(pdata);
}

int main(int ac, char **av)
{
	data *pdata = my_calloc(sizeof(struct  data));
	ways **pways;
	char **paths = NULL;

	(void)ac;
	if (get_file_and_parse(pdata, av) == 84)
		return (84);
	my_putstr("#moves\n");
	pdata->tmp_tunnels = clear_tunnels(pdata->tmp_tunnels);
	paths = dijkstra(pdata);
	if (my_has_char(paths[0], '-') == 0)
		return (0);
	pways = my_calloc(sizeof(ways *) * (my_strlen(paths[0]) + 1));
	pways[my_strlen(paths[0])] = NULL;
	real_path(paths, pways, pdata);
	my_free(pdata);
	return (0);
}