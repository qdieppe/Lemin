/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** my_desc
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

int my_putstr(char const *str)
{
	write(1, str, my_strlen(str));
	return (0);
}
