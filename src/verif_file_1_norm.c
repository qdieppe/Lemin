/*
** EPITECH PROJECT, 2018
** verif_file_1_norm.c
** File description:
** verif_file_1_norm.c
*/

#include "my.h"

int verif_file_norm_1(int i, char **tab, data *pdata)
{
	if (my_has_char(tab[i], '#') == 0 && my_has_char(tab[i], ' ') == 0 &&
		my_has_char(tab[i], '-') >= 0 && pdata->ants_nb == 0) {
		get_garb()->line_of_ants_nb = i + 1;
		if (get_garb()->line_of_room_ref != 0 ||
			get_garb()->line_of_pipe_ref != 0) {
			return (84);
		}
		if (get_verif_ant_nb(pdata, tab[i]) == 84)
			return (84);
		my_putstr("#rooms\n");
	}
	return (0);
}

int verif_file_norm_2(int i, char **tab, data *pdata)
{
	if ((my_has_char(pdata->file_copy[i], '-') >= 0 ||
		my_has_char(pdata->file_copy[i], '#') > 1 ) &&
		(my_has_char(pdata->file_copy[i], ' ') == 2 ||
		(my_strcmp(tab[i], "##start") == 0 ||
		my_strcmp(tab[i], "##end") == 0))) {
		get_garb()->line_of_room_ref = i + 1;
		my_putstr(pdata->file_copy[i]);
		my_putchar('\n');
		if (get_garb()->line_of_pipe_ref != 0 ||
			get_garb()->line_of_ants_nb == 0) {
			my_putstr("WRONG CONFIGURATION !\n");
			return (84);
		}
		if (room_verif(tab[i], pdata, tab, i) == 84) {
			return (84);
		}
	}
	return (0);
}

int verif_file_norm_3(int i, char **tab, data *pdata)
{
	if (my_has_char(tab[i], '-') >= 1 &&
		my_has_char(tab[i], ' ') == 0 &&
		my_has_char(tab[i], '#') == 0) {
		if (start_and_end_verif(tab) == 84)
			return (84);
		if (get_garb()->line_of_pipe_ref == 0)
			my_putstr("#tunnels\n");
		get_garb()->line_of_pipe_ref = i + 1;
		if (get_garb()->line_of_ants_nb == 0 ||
			get_garb()->line_of_room_ref == 0) {
			my_putstr("WRONG CONFIGURATION !\n");
			return (84);
		}
		if (links_verif(tab[i]) == 84) {
			return (84);
		}
		my_putstr(pdata->file_copy[i]);
		my_putchar('\n');
	}
	return (0);
}

int verif_file_norm_4(int i, char **tab, data *pdata)
{
	if ((my_has_char(pdata->file_copy[i], '-') >= 0 ||
		my_has_char(pdata->file_copy[i], '#') > 1 ) &&
		i != get_garb()->line_of_ants_nb &&
		(my_has_char(pdata->file_copy[i], ' ') == 2 ||
		(my_strcmp(tab[i], "##start") == 0 ||
		my_strcmp(tab[i], "##end") == 0))) {
		fill_tmp_rooms(pdata, pdata->file_copy[i]);
	}
	if (my_has_char(tab[i], '-') == 1 &&
		my_has_char(tab[i], ' ') == 0) {
		fill_tmp_tunnels(pdata, tab[i]);
	}
	return (0);
}

int verif_file(data *pdata)
{
	int i = 0;
	char **tab;

	clean_input_file(pdata);
	tab = pdata->file_copy;
	pdata->tmp_rooms = my_calloc(sizeof(char *) * line_nb(tab));
	pdata->tmp_tunnels = my_calloc(sizeof(char *) * line_nb(tab));
	my_putstr("#number_of_ants\n");
	for (i = 0; tab[i] != NULL; i++) {
		if (verif_file_norm_1(i, tab, pdata) == 84)
			return (84);
		if (verif_file_norm_2(i, tab, pdata) == 84)
			return (84);
		if (verif_file_norm_3(i, tab, pdata) == 84 ||
			verif_file_norm_4(i, tab, pdata) == 84)
			return (84);
	}
	return (0);
}