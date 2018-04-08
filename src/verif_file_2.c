/*
** EPITECH PROJECT, 2018
** verif_file.c
** File description:
** verif_file.c
*/

#include "my.h"

int start_chamber(data *pdata, char **file_copy, int i)
{
	char **tab = str_to_word_tab(file_copy[i + 1], ' ');

	if (tab[3] != NULL || tab[2] == NULL || pdata->start_room != NULL) {
		my_putstr("PROBLEM WITH THE START ROOM\n");
		return (84);
	}
	pdata->start_room = my_strdup(tab[0]);
	free(tab);
	return (0);
}

int end_chamber(data *pdata, char **file_copy, int i)
{
	char **tab = str_to_word_tab(file_copy[i + 1], ' ');

	if (tab[3] != NULL || tab[2] == NULL || pdata->end_room != NULL) {
		my_putstr("PROBLEM WITH THE END ROOM\n");
		return (84);
	}
	pdata->end_room = my_strdup(tab[0]);
	free(tab);
	return (0);
}

int start_and_end_verif(char **file_copy)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (file_copy[i] != NULL) {
		if (my_strcmp(file_copy[i], "##start") == 0) {
			j = j + 1;
		}
		if (my_strcmp(file_copy[i], "##end") == 0) {
			k++;
		}
		i++;
	}
	if (j == 1 && k == 1)
		return (0);
	else {
		my_putstr("MISSING OR PLUS ##START or ##END LINE\n");
		return (84);
	}
}

int get_verif_ant_nb(data *pdata, char *line)
{
	int i = 0;

	while (line[i] != '\0') {
		if ((line[i] < '0' || line[i] > '9') && line[i] != '-') {
			my_putstr("INVALID ANTS NB\n");
			return (84);
		}
		i++;
	}
	pdata->ants_nb = my_getnbr(line);
	if (pdata->ants_nb < 1) {
		my_putstr("ANTS NUMBER SHOULD BE AT LEAST 1!\n");
		return (84);
	}
	my_put_nbr(pdata->ants_nb);
	my_putchar('\n');
	return (0);
}