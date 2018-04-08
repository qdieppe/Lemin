/*
** EPITECH PROJECT, 2018
** verif_file_1_norm_2.c
** File description:
** verif_file_1_norm_2.c
*/

#include "my.h"

int room_verif_norm(char **tab_line, char *line, data *pdata)
{
	tab_line = str_to_word_tab(line, ' ');
	if (tab_line[3] != NULL || tab_line[2] == NULL)
		return (84);
	pdata->room_name = my_strdup(tab_line[0]);
	if (my_is_num(tab_line[1]) == 0)
		pdata->room_coor_x = my_getnbr(tab_line[1]);
	else
		return (84);
	if (my_is_num(tab_line[2]) == 0)
		pdata->room_coor_y = my_getnbr(tab_line[2]);
	else
		return (84);
	free(tab_line);
	return (0);
}

int room_verif(char *line, data *pdata, char **file_copy, int i)
{
	char **tab_line = NULL;

	if (my_strcmp(line, "##start") != 0 &&
		my_strcmp(line, "##end") != 0) {
		if (room_verif_norm(tab_line, line, pdata) == 84)
			return (84);
	}
	if (my_strcmp(line, "##start") == 0)
		if (start_chamber(pdata, file_copy, i) == 84)
			return (84);
	if (my_strcmp(file_copy[i], "##end") == 0)
		if (end_chamber(pdata, file_copy, i) == 84)
			return (84);
	return (0);
}

int links_verif(char *str)
{
	if (my_has_char(str, '-') > 1) {
		my_putstr("PROBLEME IN PIPE SYNTAX!\n");
		return (84);
	}
	return (0);
}

void clean_input_file_norm(char **tab, int i, int j)
{
	for (; tab[i][j] != '\0'; j++) {
		if (tab[i][j] == '#' && tab[i][j + 1] != '#' &&
			my_strcmp(tab[i], "##start") != 0 &&
			my_strcmp(tab[i], "##end") != 0) {
			tab[i][j] = '\0';
		}
	}
}