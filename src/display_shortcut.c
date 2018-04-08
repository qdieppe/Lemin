/*
** EPITECH PROJECT, 2018
** display_shortcut.c
** File description:
** display_shortcut.c
*/

#include "my.h"

void display_shortcut(int x, char *str)
{
	my_putchar('P');
	my_put_nbr(x);
	my_putchar('-');
	my_putstr(str);
}