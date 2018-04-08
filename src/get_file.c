/*
** EPITECH PROJECT, 2018
** get_file.c
** File description:
** get_file.c
*/

#include "my.h"

char **clean_tab(char **tab)
{
	int i = 0;
	int j = 0;
	char **tmp;

	while (tab[i] != NULL) {
		while (tab[i][j] != '\0') {
			tab[i][j] = (tab[i][j] == '\n' ? '\0' : tab[i][j]);
			j++;
		}
		i++;
		j = 0;
	}
	for (i = 0; tab[i] != NULL; i++);
	tmp = my_calloc(sizeof(char *) * (i + 1));
	for (i = 0; tab[i] != NULL; i++)
		tmp[i] = my_strdup(clear_str(tab[i]));
	tmp[i] = NULL;
	return (tab);
}

void rm_empty(char **tab)
{
	int i = 0;

	while (tab[i] != NULL) {
		if (my_strcmp("\n", tab[i]) == 0) {
			tab[i] = NULL;
			return ;
		}
		i = i + 1;
	}
}

int get_file(data *pdata, char **av)
{
	(void)av;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int i = 0;

	extern FILE *stdin;
	pdata->file_copy = malloc(sizeof(char*) * (1000));
	for (; (read = getline(&line, &len, stdin)) != -1; i++) {
		pdata->file_copy[i] = my_strdup(clear_str(line));
	}
	pdata->file_copy[i] = NULL;
	free(line);
	rm_empty(pdata->file_copy);
	pdata->file_copy = clean_tab(pdata->file_copy);
	return (0);
}