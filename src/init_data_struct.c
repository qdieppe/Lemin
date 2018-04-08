/*
** EPITECH PROJECT, 2018
** init_data_struct.c
** File description:
** init_data_struct.c
*/

#include "my.h"

void init_data_struct(data *pdata)
{
	pdata->file_copy = NULL;
	pdata->ants_nb = 0;
	pdata->cursor = 0;

	pdata->room_name = NULL;
	pdata->room_coor_x = 0;
	pdata->room_coor_y = 0;

	pdata->tmp_rooms = NULL;
	pdata->tmp_tunnels = NULL;

	pdata->start_room = NULL;
	pdata->end_room = NULL;
}