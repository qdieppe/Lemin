/*
** EPITECH PROJECT, 2018
** verif_file.c
** File description:
** verif_file.c
*/

#include "my.h"

void clean_input_file(data *pdata)
{
	char **tab = pdata->file_copy;
	int i = 0;
	int j = 0;

	for (i = 0; tab[i] != NULL; i++, j = 0) {
		clean_input_file_norm(tab, i, j);
	}
	pdata->file_copy = clean_void_line(pdata->file_copy);
}

struct garb *get_garb()
{
	static long long addr= (long long) NULL;
	static int i = 0;
	struct garb *keep = NULL;

	if (i == 0) {
		i = 1;
		keep = malloc(sizeof(struct garb));
		addr = (long long) keep;
		keep->line_of_ants_nb = 0;
		keep->line_of_room_ref = 0;
		keep->line_of_pipe_ref = 0;
		return (keep);
	}
	else
		return ((struct garb *)addr);
}

void fill_tmp_rooms(data *pdata, char *line)
{
	static int j = 0;

	pdata->tmp_rooms[j] = my_strdup(line);
	j++;
	pdata->tmp_rooms[j] = NULL;
}

void fill_tmp_tunnels(data *pdata, char *line)
{
	static int j = 0;

	pdata->tmp_tunnels[j] = my_strdup(line);
	j++;
	pdata->tmp_tunnels[j] = NULL;
}