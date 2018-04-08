/*
** EPITECH PROJECT, 2018
** utils2.c
** File description:
** utils2.c
*/

#include "my.h"

int my_strlen(char *str)
{
	int len;

	len = 0;
	while (str && str[len] != '\0') {
		len = len + 1;
	}
	return (len);
}

char *my_strdup(char *src)
{
	int lenght = my_strlen(src);
	int idx = 0;
	char *new_str;

	if (src == NULL)
		return (NULL);
	if ((new_str = malloc(sizeof(char) * (lenght + 1))) == NULL) {
		my_putstr("ERROR: Out of memory! malloc() failed\n");
		return (NULL);
	}
	while (src[idx]) {
		new_str[idx] = src[idx];
		idx += 1;
	}
	new_str[idx] = '\0';
	return (new_str);
}

char *my_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	char *tmp = malloc(sizeof(char) *
		(my_strlen(dest) + my_strlen(src) + 1));

	while (dest[i] != '\0') {
		tmp[i] = dest[i];
		i++;
	}
	while (src[j] != '\0') {
		tmp[i] = src[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int line_nb(char **tab)
{
	int i = 0;

	while (tab[i] != NULL) {
		i++;
	}
	return (i);
}