/*
** EPITECH PROJECT, 2018
** real_path.c
** File description:
** real_path.c
*/

#include "my.h"

int value_of_rooms(data *pdata, ways **pways, int last_room)
{
	int i = 0;

	while (pways[i] != NULL) {
		if (my_strcmp(pways[i]->room_name, pdata->start_room) == 0) {
			pways[i]->ant_present = pdata->ants_nb;
		}
		if (my_strcmp(pways[i]->room_name, pdata->end_room) == 0) {
			pways[i]->ant_present = 0;
			last_room = i;
		}
		i++;
	}
	return (last_room);
}

void display_norm_2(ways **pways, int last_room, int *has_one, int i)
{
	if (pways[i]->ant_present) {
		if (i != last_room) {
			write(1, " ", *has_one ? 1 : 0);
			display_shortcut(pways[i]->ant_number_present,
				pways[i + 1]->room_name);
			pways[i + 1]->ant_number_present =
			pways[i]->ant_number_present;
			*has_one = 1;
		}
		pways[i]->ant_number_present++;
		if (i != last_room)
			pways[i + 1]->ant_present++;
		pways[i]->ant_present--;
	}
}

void display_norm(ways **pways, int last_room, int *has_one)
{
	for (int i = last_room; i >= 0; i--) {
		display_norm_2(pways, last_room, has_one, i);
	}
}

void the_display(ways **pways, data *pdata, int last_room)
{
	int has_one = 0;

	while (pways[last_room]->ant_present != pdata->ants_nb + 1) {
		display_norm(pways, last_room, &has_one);
		has_one = 0;
		pways[last_room]->ant_present++;
		my_putchar('\n');
	}
}

int real_path(char **tab, ways **pways, data *pdata)
{
	int last_room = 0;
	int i = 0;
	int tab_len = 0;
	char **mdr = NULL;

	mdr = str_to_word_tab(tab[0], '-');
	for (i = 0; mdr[i] != NULL; i++, tab_len = i) {
		pways[i] = my_calloc(sizeof(struct ways));
		pways[i]->room_name = my_strdup(mdr[i]);
		pways[i]->ant_present = 0;
		pways[i]->ant_number_present = 0;
	}
	pways[0]->ant_number_present = 1;
	(void)tab_len;
	last_room = value_of_rooms(pdata, pways, last_room);
	the_display(pways, pdata, last_room);
	return (0);
}