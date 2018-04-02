/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** my_desc
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char *src)
{
	int i = 0;
	int size = my_strlen(src);

	while (i < size) {
		dest[i] = src[i];
		i = i + 1;
	}
	dest[i] = '\0';
	return (dest);
}
