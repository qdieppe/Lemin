/*
** EPITECH PROJECT, 2017
** my_strlowcase
** File description:
** my_strlowcase
*/

int my_strlen(char *);

char *my_strlowcase(char *str)
{
	int i = 0;
	int size = my_strlen(str);

	while (i < size) {
		if (str[i] > 0x40 && str[i] < 0x5b)
			str[i] = str[i] + 0x20;
		i = i + 1;
	}
	return (str);
}
