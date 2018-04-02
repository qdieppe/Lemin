/*
** EPITECH PROJECT, 2017
** my_getnbr_.c
** File description:
** my_getnbr_utils
*/

#include "my_getnbr.h"

int compare_min(char *str, char *my_str)
{
	int i = 0;

	while (i < 10) {
		if (str[i] != my_str[i])
			return (0);
		i = i + 1;
	}
	return (1);
}

int verify_for_max(const char *str, const char *my_str)
{
	int i = 0;

	while (i < 10) {
		if (my_str[i] < str[i])
			return (1);
		else if (my_str[i] == str[i])
			i = i + 1;
		else
			return (0);
	}
	return (0);
}
