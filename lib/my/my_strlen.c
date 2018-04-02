/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** my_desc
*/

int my_strlen(char const *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && i < 2147483647)
		i = i + 1;
	return (i);
}
