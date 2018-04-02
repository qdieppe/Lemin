/*
** EPITECH PROJECT, 2017
** my_strdup.c
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char *str)
{
	int i = 0;
	int size = my_strlen(str);
	char *str_dup = malloc(size + 1);

	while (i < size + 1) {
		str_dup[i] = 0;
		i = i + 1;
	}
	my_strcpy(str_dup, str);
	return (str_dup);
}
